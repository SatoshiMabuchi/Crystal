#include "PolygonMeshBuilder.h"
#include "HalfEdge.h"

using namespace Crystal::Math;
using namespace Crystal::Shape;

void PolygonMeshBuilder::build(const Box3d& box)
{
	std::vector<Vertex*> vertices;
	vertices.push_back(new Vertex(box.getPosition(Vector3dd(0, 0, 0)), nextId++));
	vertices.push_back(new Vertex(box.getPosition(Vector3dd(1, 0, 0)), nextId++));
	vertices.push_back(new Vertex(box.getPosition(Vector3dd(1, 1, 0)), nextId++));
	vertices.push_back(new Vertex(box.getPosition(Vector3dd(0, 1, 0)), nextId++));
	vertices.push_back(new Vertex(box.getPosition(Vector3dd(0, 0, 1)), nextId++));
	vertices.push_back(new Vertex(box.getPosition(Vector3dd(1, 0, 1)), nextId++));
	vertices.push_back(new Vertex(box.getPosition(Vector3dd(1, 1, 1)), nextId++));
	vertices.push_back(new Vertex(box.getPosition(Vector3dd(0, 1, 1)), nextId++));

	std::vector<HalfEdge*> edges;
	edges.push_back(new HalfEdge(vertices[0], vertices[1]));
	edges.push_back(new HalfEdge(vertices[1], vertices[3]));
	edges.push_back(new HalfEdge(vertices[3], vertices[0]));

	edges.push_back(new HalfEdge(vertices[3], vertices[1]));
	edges.push_back(new HalfEdge(vertices[1], vertices[2]));
	edges.push_back(new HalfEdge(vertices[2], vertices[3]));

	edges.push_back(new HalfEdge(vertices[4], vertices[5]));
	edges.push_back(new HalfEdge(vertices[5], vertices[7]));
	edges.push_back(new HalfEdge(vertices[7], vertices[4]));

	edges.push_back(new HalfEdge(vertices[7], vertices[5]));
	edges.push_back(new HalfEdge(vertices[5], vertices[6]));
	edges.push_back(new HalfEdge(vertices[6], vertices[7]));
	
	faces.push_back(new Face(edges[0], edges[1], edges[2]));
	faces.push_back(new Face(edges[3], edges[4], edges[5]));
	faces.push_back(new Face(edges[6], edges[7], edges[8]));
	faces.push_back(new Face(edges[9], edges[10], edges[11]));

	//faces
}

void PolygonMeshBuilder::build(const Sphere3d& sphere, const int unum, const int vnum)
{
	const auto du = 1.0 / (double)unum;
	const auto dv = 1.0 / (double)vnum;
	std::vector<std::vector<Vertex*>> vertices;
	for (double u = 0.0; u < 1.0; u +=du) {
		std::vector<Vertex*> vs;
		for (double v = 0.0; v < 1.0; v+=dv) {
			vs.push_back(new Vertex(sphere.getPosition(u, v), sphere.getNormal(u, v), nextId++));
		}
		vertices.push_back(vs);
	}
	for (int i = 0; i < vertices.size()-1; ++i) {
		for (int j = 0; j < vertices[i].size() - 1; ++j) {
			auto e1 = new HalfEdge(vertices[i][j], vertices[i+1][j]);
			auto e2 = new HalfEdge(vertices[i + 1][j], vertices[i][j + 1]);
			auto e3 = new HalfEdge(vertices[i][j + 1], vertices[i][j]);
			faces.push_back(new Face(e1, e2, e3));
		}
	}
}
