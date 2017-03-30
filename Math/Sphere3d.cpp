#include "Sphere3d.h"

#include "Box3d.h"
#include "Tolerance.h"

using namespace Crystal::Math;

template<typename T>
Sphere<T>::Sphere() :
	center(Vector3d<T>(0,0,0)),
	radius(1.0f)
{}

template<typename T>
Sphere<T>::Sphere(const Vector3d<T>& center, const float radius) :
	center(center),
	radius(radius)
{}

template<typename T>
Sphere<T>::Sphere(const Box3d<T>& boundingBox)
{
	center = Vector3d<T>(boundingBox.getCenter().getX(), boundingBox.getCenter().getY(), boundingBox.getCenter().getZ());
	const Vector3d<T>& length = boundingBox.getLength();
	radius = std::min<T>(std::min<T>(length.getX(), length.getY()), length.getZ()) * T { 0.5 };
}

template<typename T>
Sphere<T> Sphere<T>::UnitSphere()
{
	return Sphere<T>(Vector3d<T>(0,0,0), 1.0f);
}


template<typename T>
Box3d<T> Sphere<T>::getBoundingBox() const {
	Math::Box3d<T> box(center, center);
	return box.getOuterOffset(radius);
}

template<typename T>
std::vector<Vector3d<T>> Sphere<T>::toPoints(const T divideLength) const
{
	std::vector<Vector3d<T>> points;

	Math::Box3d<T> box(center, center);
	box.outerOffset(radius);

	for (auto x = box.getMinX(); x <= box.getMaxX(); x += divideLength) {
		for (auto y = box.getMinY(); y <= box.getMaxY(); y += divideLength) {
			for (auto z = box.getMinZ(); z <= box.getMaxZ(); z += divideLength) {
				const Vector3d<T> pos(x, y, z);
				if (pos.getDistanceSquared(center) < radius * radius) {
					points.push_back(pos);
				}
			}
		}
	}
	return points;
}

template<typename T>
Vector3d<T> Sphere<T>::getPositionByAngle(const T theta, const T phi) const
{
	assert(0.0 <= theta && theta <= Tolerance<T>::getTwoPI());
	assert(0.0 <= phi && phi <= Tolerance<T>::getPI());

	const auto x = radius * std::sin(theta) * std::cos(phi);
	const auto y = radius * std::sin(theta) * std::cos(phi);
	const auto z = radius * std::cos(theta);
	return Vector3d<T>(x, y, z);
}

template<typename T>
Vector3d<T> Sphere<T>::getPositionByParam(const T u, const T v) const
{
	const auto theta = u * Tolerance<T>::getTwoPI();
	const auto phi = v * Tolerance<T>::getPI();
	return getPositionByAngle(theta, phi);
}

/*
template<typename T>
Vector3d<T> Sphere<T>::getNormalByPosition(const Angle<T> u, const Angle<T> v) const
{
	const auto& pos = getPosition(u, v);
	Vector3d<T> n(pos - center);
	return n.normalized();
}

template<typename T>
Vector3d<T> Sphere<T>::getNormal(const Param<T> u, const Param<T> v) const
{
	const auto& pos = getPosition(u, v);
	Vector3d<T> n(pos - center);
	return n.normalized();
}

template<typename T>
Point3d<T> Sphere<T>::getPoint(const Param<T> u, const Param<T> v) const
{
	return Point3d<T>(getPosition(u, v), getNormal(u, v), Vector2d<T>(u.get(), v.get()));
}
*/

template<typename T>
Sphere<T> Sphere<T>::getInnerOffset(const float offsetLength) const
{
	Sphere sphere = *this;
	sphere.radius -= offsetLength;
	assert(sphere.isValid());
	return sphere;
}


template<typename T>
bool Sphere<T>::equals(const Sphere& rhs) const
{
	return
		Tolerance<T>::isEqualLoosely(radius, rhs.radius) &&
		(center == rhs.center);
}


template<typename T>
bool Sphere<T>::operator==(const Sphere& rhs) const
{
	return equals(rhs);
}

template<typename T>
bool Sphere<T>::operator!=(const Sphere& rhs) const
{
	return !equals(rhs);
}

template<typename T>
bool Sphere<T>::isInner(const Vector3d<T>& v) const
{
	return v.getDistanceSquared(center) < (radius * radius);
}

template<typename T>
bool Sphere<T>::isOuter(const Vector3d<T>& v) const
{
	return v.getDistanceSquared(center) > (radius * radius);
}


template<typename T>
bool Sphere<T>::isOnStrictly(const Vector3d<T>& v) const
{
	return Tolerance<T>::isEqualStrictly(v.getDistanceSquared(center), radius * radius);
}

template<typename T>
bool Sphere<T>::isOnLoosely(const Vector3d<T>& v) const
{
	return Tolerance<T>::isEqualLoosely(v.getDistanceSquared(center), radius * radius);
}

template class Sphere<float>;
template class Sphere<double>;