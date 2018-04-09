#include "PolygonMesh.h"

#include "../Math/Vector3d.h"
#include "Vertex.h"
#include "Face.h"

using namespace Crystal::Math;
using namespace Crystal::Shape;


PolygonMesh::~PolygonMesh()
{
	clear();
}

PolygonMesh::PolygonMesh(const std::vector<Vertex*>& vertices, const std::list<Face*>& faces) :
	vertices(vertices),
	faces(faces)
{}

void PolygonMesh::clear()
{
	vertices.clear();
	faces.clear();
}

//void create(const Math::TriangleCurve3d<float>& curve, const int id = -1);

#include "HalfEdge.h"

HalfEdge* PolygonMesh::getShortestEdge()
{
	std::list<HalfEdge> edges;
	auto minEdge = faces.front()->getEdges().front();
	for (auto f : faces) {
		auto edges = f->getEdges();
		for (auto e : edges) {
			if (e->getLength() < minEdge->getLength()) {
				minEdge = e;
			}
		}
	}
	return minEdge;
}



void PolygonMesh::add(Face* f)
{
	faces.push_back(f);
}

bool PolygonMesh::has(Face* f)
{
	return std::find(faces.begin(), faces.end(), f) != faces.end();
}

bool PolygonMesh::has(HalfEdge* e)
{
	const auto& edges = getEdges();
	return std::find(edges.begin(), edges.end(), e) != edges.end();
}

bool PolygonMesh::has(Vertex* v)
{
	const auto& vertices = getVertices();
	return std::find(vertices.begin(), vertices.end(), v) != vertices.end();
}

std::vector<Vertex*> PolygonMesh::getVertices() const
{
	return vertices;
}

std::list<HalfEdge*> PolygonMesh::getEdges() const
{
	std::list<HalfEdge*> edges;
	for (auto f : faces) {
		auto es = f->getEdges();
		edges.insert(edges.end(), es.begin(), es.end());
	}
	edges.sort();
	edges.unique();
	return edges;
}

void PolygonMesh::remove(Face* f)
{
	faces.remove(f);
}

PolygonMesh* PolygonMesh::clone()
{
	return new PolygonMesh(vertices, faces);
}

void PolygonMesh::mergeDouble(PolygonMesh* rhs, float distance)
{
	auto faces1 = this->getFaces();
	auto faces2 = rhs->getFaces();
	for (auto f1 : faces1) {
		for (auto f2 : faces2) {
			f1->mergeDouble(*f2, distance);
		}
	}
}

Vector3df PolygonMesh::getCenter() const
{
	Vector3df center;
	const auto& vs = this->getVertices();
	for (const auto& v : vs) {
		center += v->getPosition() / static_cast<float>(vs.size());
	}
	return center;
}

void PolygonMesh::move(const Vector3df& v)
{
	const auto& vs = getVertices();
	for (auto& vert : vs) {
		vert->move(v);
	}
}

/*
void PolygonMesh::scale(const Vector3df& s)
{
	const auto& center = getCenter();
	move(-center);
	const auto& vs = getVertices();
	for (auto& vert : vs) {
		vert->scale(s);
	}
	move(center);
}

void PolygonMesh::rotate(const Quaternion<float>& quaternion)
{
	const auto& center = getCenter();
	move(-center);
	const auto& vs = getVertices();
	const auto& matrix = quaternion.toMatrix();
	for (auto& vert : vs) {
		vert->transform(matrix);
	}
	move(center);
}
*/

void PolygonMesh::merge(PolygonMesh& rhs)
{
	faces.splice(faces.end(), rhs.faces);
	rhs.clear();
}

void PolygonMesh::reverse()
{
	auto vs = getVertices();
	for (auto v : vs) {
		v->reverse();
	}
	for (auto f : faces) {
		f->reverse();
	}
}

std::list<Vertex*> PolygonMesh::findBoundaryVertices()
{
	const auto& bEdges = findBoundaryEdges();
	std::list<Vertex*> results;
	for (const auto& b : bEdges) {
		results.push_back(b->getStart());
	}
	results.sort();
	results.unique();
	return results;
}

std::list<Vertex*> PolygonMesh::findInnerVertices()
{
	auto all = getVertices();
	auto boundaries = findBoundaryVertices();
	std::list<Vertex*> inners;
	std::set_difference(
		all.begin(), all.end(),
		boundaries.begin(), boundaries.end(),
		std::back_inserter(inners)
	);
	return inners;
}


std::list<HalfEdge*> PolygonMesh::findBoundaryEdges()
{
	std::list<HalfEdge*> results;
	const auto& edges = getEdges();
	for (auto e : edges) {
		if (e->isBoundary()) {
			results.push_back(e);
		}
	}
	return results;
}

void PolygonMesh::updateNormals()
{
	std::list<Face*> fs;
	for (auto f : faces) {
		if (f->getArea() > 1.0e-6) {
			fs.push_back(f);
		}
	}

	for (auto f : fs) {
		for (auto v : f->getVertices()) {
			v->setNormal(Vector3df(0, 0, 0));
		}
	}
	for (auto f : fs) {
		const auto area = f->getArea() * 1.0e+6f;
		//assert(area > 0);
		//assert(area > 1.0e-1);
		const auto& normal = f->getNormal();
		for (auto v : f->getVertices()) {
			v->setNormal(v->getNormal() + area * normal);
		}
	}
	for (auto f : fs) {
		for (auto v : f->getVertices()) {
			auto n = v->getNormal();
			v->setNormal(glm::normalize( n ));
		}
	}
}