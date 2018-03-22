#include "WireFrameBuilder.h"

using namespace Crystal::Math;
using namespace Crystal::Shape;

void WireFrameBuilder::build(const Box3d& box)
{
	std::vector<Vector3dd> vertices;
	vertices.push_back(box.getPosition(Vector3dd(0, 0, 0)));
	vertices.push_back(box.getPosition(Vector3dd(1, 0, 0)));
	vertices.push_back(box.getPosition(Vector3dd(1, 1, 0)));
	vertices.push_back(box.getPosition(Vector3dd(0, 1, 0)));
	vertices.push_back(box.getPosition(Vector3dd(0, 0, 1)));
	vertices.push_back(box.getPosition(Vector3dd(1, 0, 1)));
	vertices.push_back(box.getPosition(Vector3dd(1, 1, 1)));
	vertices.push_back(box.getPosition(Vector3dd(0, 1, 1)));

	std::vector<std::vector<Vector3dd>> grid;
	lines.push_back(Line3dd::fromPoints(vertices[0], vertices[1]));
	lines.push_back(Line3dd::fromPoints(vertices[1], vertices[2]));
	lines.push_back(Line3dd::fromPoints(vertices[2], vertices[3]));
	lines.push_back(Line3dd::fromPoints(vertices[3], vertices[0]));

	lines.push_back(Line3dd::fromPoints(vertices[4], vertices[5]));
	lines.push_back(Line3dd::fromPoints(vertices[5], vertices[6]));
	lines.push_back(Line3dd::fromPoints(vertices[6], vertices[7]));
	lines.push_back(Line3dd::fromPoints(vertices[7], vertices[4]));

	lines.push_back(Line3dd::fromPoints(vertices[0], vertices[4]));
	lines.push_back(Line3dd::fromPoints(vertices[1], vertices[5]));
	lines.push_back(Line3dd::fromPoints(vertices[2], vertices[6]));
	lines.push_back(Line3dd::fromPoints(vertices[3], vertices[7]));

}

void WireFrameBuilder::build(const Sphere3d& sphere)
{
	std::vector<std::vector<Math::Vector3dd>> grid;
	for (auto u = 0.0; u < 1.0; u += 0.1) {
		std::vector<Math::Vector3dd> g;
		for (auto v = 0.0; v < 1.0; v += 0.1) {
			g.push_back(sphere.getPosition(u, v));
		}
		grid.push_back(g);
	}
	make(grid);
}
