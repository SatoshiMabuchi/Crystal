#pragma once

#include "Vector3d.h"

namespace Crystal {
	namespace Math {

class Line3dd
{
public:
	Line3dd(const Math::Vector3dd& origin, const Math::Vector3dd& dir) :
		origin(origin),
		dir(dir)
	{
	}

	static Line3dd fromPoints(const Vector3dd& start, const Vector3dd& end)
	{
		return Line3dd(start, end - start);
	}

	Math::Vector3dd getStart() const { return origin; }

	Math::Vector3dd getEnd() const { return origin + dir; }

	double getLength() const { return glm::distance(origin, dir); }

private:
	Math::Vector3dd origin;
	Math::Vector3dd dir;
};
	}
}