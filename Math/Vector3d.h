#ifndef __CRSYTAL_MATH_VECTOR_3D_H__
#define __CRSYTAL_MATH_VECTOR_3D_H__

#include <cmath>
#include <vector>
#include <array>
#include "Tolerance.h"
#include "../ThirdParty/glm-0.9.8.5/glm/glm.hpp"

namespace Crystal {
	namespace Math {

using Vector3df = glm::vec3;
using Vector3dd = glm::dvec3;

static float getLengthSquared(const Vector3df& v)
{
	return std::pow(v.x, 2.0f) + std::pow(v.y, 2.0f) + std::pow(v.z, 2.0f);
}

static double getDistanceSquared(const Vector3dd& v)
{
	return std::pow(v.x, 2.0) + std::pow(v.y, 2.0) + std::pow(v.z, 2.0);
}

static float getDistanceSquared(const Vector3df& lhs, const Vector3df& rhs)
{
	return std::pow(lhs.x - rhs.x, 2.0f) + std::pow(lhs.y - rhs.y, 2.0f) + std::pow(lhs.z - rhs.z, 2.0f);
}

static double getDistanceSquared(const Vector3dd& lhs, const Vector3dd& rhs)
{
	return std::pow(lhs.x - rhs.x, 2.0) + std::pow(lhs.y - rhs.y, 2.0) + std::pow(lhs.z - rhs.z, 2.0);
}

static bool isEqualLoosely(const Vector3dd& lhs, const Vector3dd& rhs)
{
	const auto tolerance = Tolerance<double>::getLooseTolerance();
	return getDistanceSquared(lhs, rhs) < tolerance;
}

	}
}

#endif