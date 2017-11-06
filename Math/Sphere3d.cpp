#include "Sphere3d.h"

#include "Box3d.h"
#include "Tolerance.h"

using namespace Crystal::Math;

template<typename T>
Sphere3d<T>::Sphere3d() :
	center(Vector3dd(0,0,0)),
	radius(1.0f)
{}

template<typename T>
Sphere3d<T>::Sphere3d(const Vector3dd& center, const float radius) :
	center(center),
	radius(radius)
{}

template<typename T>
Sphere3d<T>::Sphere3d(const Box3d& boundingBox)
{
	center = boundingBox.getCenter();
	const auto& length = boundingBox.getLength();
	radius = std::min<T>(std::min<T>(length.x, length.y), length.z) * T { 0.5 };
}

template<typename T>
Vector3dd Sphere3d<T>::getPositionByAngle(const T theta, const T phi) const
{
	assert(0.0 <= theta && theta <= Tolerance<T>::getPI());
	assert(0.0 <= phi && phi <= Tolerance<T>::getTwoPI());

	const auto x = radius * std::sin(theta) * std::cos(phi);
	const auto y = radius * std::sin(theta) * std::sin(phi);
	const auto z = radius * std::cos(theta);
	return Vector3dd(x, y, z);
}

template<typename T>
Vector3dd Sphere3d<T>::getPositionByParam(const T u, const T v) const
{
	const auto theta = u * Tolerance<T>::getPI();
	const auto phi = v * Tolerance<T>::getTwoPI();
	return getPositionByAngle(theta, phi);
}

/*
template<typename T>
Vector3dd Sphere<T>::getNormalByPosition(const Angle<T> u, const Angle<T> v) const
{
	const auto& pos = getPosition(u, v);
	Vector3dd n(pos - center);
	return n.normalized();
}

template<typename T>
Vector3dd Sphere<T>::getNormal(const Param<T> u, const Param<T> v) const
{
	const auto& pos = getPosition(u, v);
	Vector3dd n(pos - center);
	return n.normalized();
}

template<typename T>
Point3d<T> Sphere<T>::getPoint(const Param<T> u, const Param<T> v) const
{
	return Point3d<T>(getPosition(u, v), getNormal(u, v), Vector2d<T>(u.get(), v.get()));
}
*/

template<typename T>
Sphere3d<T> Sphere3d<T>::getInnerOffset(const float offsetLength) const
{
	Sphere3d sphere = *this;
	sphere.radius -= offsetLength;
	assert(sphere.isValid());
	return sphere;
}


template<typename T>
bool Sphere3d<T>::equals(const Sphere3d& rhs) const
{
	return
		Tolerance<T>::isEqualLoosely(radius, rhs.radius) &&
		(center == rhs.center);
}


template<typename T>
bool Sphere3d<T>::operator==(const Sphere3d& rhs) const
{
	return equals(rhs);
}

template<typename T>
bool Sphere3d<T>::operator!=(const Sphere3d& rhs) const
{
	return !equals(rhs);
}

template<typename T>
bool Sphere3d<T>::isInner(const Vector3dd& v) const
{
	return glm::distance( v, center) < radius;
}

template<typename T>
bool Sphere3d<T>::isOuter(const Vector3dd& v) const
{
	return glm::distance( v, center) > radius;
}

template class Sphere3d<float>;
template class Sphere3d<double>;