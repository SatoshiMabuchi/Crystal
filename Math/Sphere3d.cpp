#include "Sphere3d.h"

#include "Box3d.h"
#include "Tolerance.h"

using namespace Crystal::Math;

Sphere3d::Sphere3d() :
	center(Vector3dd(0,0,0)),
	radius(1.0f)
{}

Sphere3d::Sphere3d(const Vector3dd& center, const float radius) :
	center(center),
	radius(radius)
{}

Sphere3d::Sphere3d(const Box3d& boundingBox)
{
	center = boundingBox.getCenter();
	const auto& length = boundingBox.getLength();
	radius = std::min<double>(std::min<double>(length.x, length.y), length.z) * 0.5;
}

Vector3dd Sphere3d::getPositionByAngle(const double theta, const double phi) const
{
	assert(0.0 <= theta && theta <= Tolerance<double>::getPI());
	assert(0.0 <= phi && phi <= Tolerance<double>::getTwoPI());

	const auto x = radius * std::sin(theta) * std::cos(phi);
	const auto y = radius * std::sin(theta) * std::sin(phi);
	const auto z = radius * std::cos(theta);
	return Vector3dd(x, y, z);
}

Vector3dd Sphere3d::getPositionByParam(const double u, const double v) const
{
	const auto theta = u * Tolerance<double>::getPI();
	const auto phi = v * Tolerance<double>::getTwoPI();
	return getPositionByAngle(theta, phi);
}

Sphere3d Sphere3d::getInnerOffset(const float offsetLength) const
{
	Sphere3d sphere = *this;
	sphere.radius -= offsetLength;
	assert(sphere.isValid());
	return sphere;
}

bool Sphere3d::equals(const Sphere3d& rhs) const
{
	return
		Tolerance<double>::isEqualLoosely(radius, rhs.radius) &&
		(center == rhs.center);
}

bool Sphere3d::operator==(const Sphere3d& rhs) const
{
	return equals(rhs);
}

bool Sphere3d::operator!=(const Sphere3d& rhs) const
{
	return !equals(rhs);
}

bool Sphere3d::isInner(const Vector3dd& v) const
{
	return glm::distance( v, center) < radius;
}

bool Sphere3d::isOuter(const Vector3dd& v) const
{
	return glm::distance( v, center) > radius;
}