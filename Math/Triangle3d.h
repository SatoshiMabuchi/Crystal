#pragma once

#include <array>
#include "Vector3d.h"

namespace Crystal {
	namespace Math {

template<typename T>
class Triangle3d
{
public:
	explicit Triangle3d(const std::array<Vector3dd, 3>& vertices) :
		vertices(vertices)
	{}

	Vector3dd getNormal() const;

	T getArea() const;

private:
	std::array<Vector3dd, 3> vertices;
};
	}
}