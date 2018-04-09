#include "WireFrame.h"

using namespace Crystal::Math;
using namespace Crystal::Shape;

std::vector<Line3dd> WireFrame::getLines() const
{
	return lines;
}

std::vector<Vector3dd> WireFrame::getVertices() const
{
	if (lines.empty()) {
		return std::vector<Vector3dd>();
	}

	std::vector<Vector3dd> vertices;
	for (const auto& l : lines) {
		vertices.push_back(l.getStart());
	}
	vertices.push_back(lines.back().getEnd());
	return vertices;
}
