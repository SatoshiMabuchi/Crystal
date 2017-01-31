#include "Vector3d.h"
#include <cassert>

using namespace Crystal::Math;

template<typename T>
Vector3d<T>::Vector3d(void) :
	Vector3d(0, 0, 0)
{}

template<typename T>
Vector3d<T>::Vector3d(const std::array<T, 3>& v) :
	Vector3d(v[0], v[1], v[2])
{
}

template<typename T>
Vector3d<T>::Vector3d(const T x, const T y, const T z) :
	x(x), y(y), z(z)
{}

template<typename T>
Vector3d<T>::Vector3d(const Vector3d& start, const Vector3d& end) :
	x(end.x - start.x),
	y(end.y - start.y),
	z(end.z - start.z)
{}

template<typename T>
bool Vector3d<T>::equals(const Vector3d<T>&rhs) const
{
	const auto tolerance = 1.0e-6f;
	return
		Tolerance<T>::isEqual(this->x, rhs.x, tolerance) &&
		Tolerance<T>::isEqual(this->y, rhs.y, tolerance) &&
		Tolerance<T>::isEqual(this->z, rhs.z, tolerance);
}

template<typename T>
void Vector3d<T>::scale(const T factor)
{
	x *= factor;
	y *= factor;
	z *= factor;
}

template<typename T>
void Vector3d<T>::scale(const T xFactor, const T yFactor, const T zFactor)
{
	x *= xFactor;
	y *= yFactor;
	z *= zFactor;
}

template<typename T>
Vector3d<T> Vector3d<T>::normalize()
{
	const auto length = getLength();
	x /= length;
	y /= length;
	z /= length;
	return *this;
}

template<typename T>
Vector3d<T> Vector3d<T>::normalized() const
{
	Vector3d<T> vector = *(this);
	return vector.normalize();
}

template<typename T>
Vector3d<T> Vector3d<T>::operator+=(const Vector3d& rhs)
{
	x += rhs.x;
	y += rhs.y;
	z += rhs.z;
	return *this;
}

template<typename T>
Vector3d<T> Vector3d<T>::operator-=(const Vector3d& rhs)
{
	x -= rhs.x;
	y -= rhs.y;
	z -= rhs.z;
	return *this;
}

template<typename T>
Vector3d<T> Vector3d<T>::operator*(const T factor) const
{
	Vector3d vector(*this);
	return vector.scaled(factor);
}

template<typename T>
Vector3d<T> Vector3d<T>::operator/(const T factor) const
{
	Vector3d vector(*this);
	return vector.scaled(1.0f / factor);
}

template<typename T>
T Vector3d<T>::getInnerProduct(const Vector3d& rhs) const
{
	return x * rhs.x + y * rhs.y + z * rhs.z;
}

template<typename T>
Vector3d<T> Vector3d<T>::getOuterProduct(const Vector3d& rhs) const
{
	return Vector3d
	(
		y * rhs.z - z * rhs.y,
		-(x * rhs.z - z * rhs.x),
		x * rhs.y - y * rhs.x
	);
}

template<typename T>
T Vector3d<T>::operator[](const int index) const
{
	assert(0 <= index  && index <= 3);
	return toArray()[index];
}

template class Vector3d<float>;
template class Vector3d<double>;