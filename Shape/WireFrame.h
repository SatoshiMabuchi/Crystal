#pragma once

#include <list>
#include "../Math/Line3d.h"

namespace Crystal {
	namespace Shape {

class WireFrame
{
public:
	explicit WireFrame(const std::vector<Math::Line3dd>& lines) :
		lines(lines)
	{}

	void add(const Math::Line3dd& l) {
		this->lines.push_back(l);
	}

	std::vector<Math::Line3dd> getLines() const;

	std::vector<Math::Vector3dd> getVertices() const;

private:
	std::vector<Math::Line3dd> lines;
};
	}
}