#include "PolygonMeshBuilder.h"
#include "HalfEdge.h"

using namespace Crystal::Math;
using namespace Crystal::Shape;

void PolygonMeshBuilder::build(const Box3d& box)
{
	build(box.getPosition(Vector3dd( 0, 0, 0)), Vector3dd(1, 0, 0), Vector3dd(0, 1, 0));
	build(box.getPosition(Vector3dd( 1, 0, 0)), Vector3df(0, 0, 1), Vector3df(0, 1, 0));

	//faces
}

void PolygonMeshBuilder::build(const Sphere3d& sphere, const int unum, const int vnum)
{
	const auto du = 1.0 / (double)unum;
	const auto dv = 1.0 / (double)vnum;
	std::vector<std::vector<Vertex*>> grid;
	for (double u = 0.0; u < 1.0; u +=du) {
		std::vector<Vertex*> vs;
		for (double v = 0.0; v < 1.0; v+=dv) {
			Vertex* vert = new Vertex(sphere.getPosition(u, v), sphere.getNormal(u, v), Vector2df(u,v), nextId++);
			vs.push_back(vert);
			this->vertices.push_back(vert);
		}
		grid.push_back(vs);
	}
	for (int i = 0; i < grid.size()-1; ++i) {
		for (int j = 0; j < grid[i].size() - 1; ++j) {
			auto e1 = new HalfEdge(grid[i+1][j], grid[i][j] );
			auto e2 = new HalfEdge(grid[i][j+1], grid[i + 1][j] );
			auto e3 = new HalfEdge(grid[i][j], grid[i][j + 1]);
			faces.push_back(new Face(e1, e2, e3));
			auto e4 = new HalfEdge(grid[i][j+1], grid[i+1][j]);
			auto e5 = new HalfEdge(grid[i+1][j], grid[i+1][j+1]);
			auto e6 = new HalfEdge(grid[i+1][j+1], grid[i][j+1]);
			faces.push_back(new Face(e4, e5, e6));
		}
	}
}

void PolygonMeshBuilder::build(const Vector3dd& start, const Vector3dd& uvec, const Vector3dd& vvec)
{
	const auto& normal = -glm::cross(uvec, vvec);

	auto v0 = new Vertex(start, normal, Vector2df(0,0), nextId++);
	auto v1 = new Vertex(start + uvec, normal, Vector2df(1,0), nextId++);
	auto v2 = new Vertex(start + vvec, normal, Vector2df(0,1), nextId++);
	auto v3 = new Vertex(start + uvec + vvec, normal, Vector2df(1,1), nextId++);
	vertices.push_back(v0);
	vertices.push_back(v1);
	vertices.push_back(v2);
	vertices.push_back(v3);

	auto e1 = new HalfEdge(v0, v1);
	auto e2 = new HalfEdge(v1, v2);
	auto e3 = new HalfEdge(v2, v0);
	faces.push_back(new Face(e1, e2, e3));

	auto e4 = new HalfEdge(v2, v1);
	auto e5 = new HalfEdge(v1, v3);
	auto e6 = new HalfEdge(v3, v2);
	faces.push_back(new Face(e4, e5, e6));

	//vertices.push_back(new Ver)
}
