#pragma once

#include <array>
#include "Vector3d.h"

namespace Crystal {
	namespace Math {

template<typename T>
class Triangle3d
{
public:
	explicit Triangle3d(const std::array<Vector3d<T>, 3>& vertices) :
		vertices(vertices)
	{}

	Vector3d<T> getNormal() const;

	T getArea() const;

private:
	std::array<Vector3d<T>, 3> vertices;
};
	}
}