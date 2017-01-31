#ifndef __CRSYTAL_MATH_VECTOR_3D_H__
#define __CRSYTAL_MATH_VECTOR_3D_H__

#include <cmath>
#include <vector>
#include <array>
#include "Tolerance.h"

namespace Crystal {
	namespace Math {

template<typename T>
class Vector3d
{
public:
	Vector3d(void);

	explicit Vector3d(const std::array<T, 3>& v);

	Vector3d(const T x, const T y, const T z);

	Vector3d(const Vector3d& start, const Vector3d& end);

	T getLengthSquared() const { return x * x + y * y + z * z; }

	T getLength() const { return ::sqrt(getLengthSquared()); }

	T getDistance(const Vector3d& rhs) const { return ::sqrt(getDistanceSquared(rhs)); }

	T getDistanceSquared(const Vector3d& rhs) const { return pow(x - rhs.x, 2) + pow(y - rhs.y, 2) + pow(z - rhs.z, 2); }

	void scale(const T factor);

	void scale(const T xFactor, const T yFactor, const T zFactor);

	Vector3d scaled(const T factor) const { return Vector3d(x * factor, y * factor, z * factor); }

	Vector3d scaled(const T xFactor, const T yFactor, const T zFactor) const { return Vector3d(x*xFactor, y*yFactor, z*zFactor); }

	Vector3d normalize();

	Vector3d normalized() const;

	bool isNormalized() const { return Tolerance<T>::isEqualLoosely(getLength(), 1.0); }

	bool equals(const Vector3d&rhs) const;

	bool isZero() const { return equals(Vector3d(0,0,0)); }

	bool operator==(const Vector3d& rhs) const { return equals(rhs); }

	bool operator!=(const Vector3d& rhs) const { return !equals(rhs); }

	Vector3d operator+(const Vector3d& rhs) const { return Vector3d(x + rhs.x, y + rhs.y, z + rhs.z); }

	Vector3d operator-(const Vector3d& rhs) const { return Vector3d(x - rhs.x, y - rhs.y, z - rhs.z); }

	Vector3d operator+=(const Vector3d& rhs);

	Vector3d operator-=(const Vector3d& rhs);

	Vector3d operator-() const { return Vector3d(-x, -y, -z); }

	Vector3d operator*(const T factor) const;

	Vector3d operator/(const T factor) const;

	T getInnerProduct(const Vector3d& rhs) const;

	Vector3d getOuterProduct(const Vector3d& rhs) const;

	//Vector3d operator*=(const T factor) { return scale(factor); }

	//Vector3d operator/=(const T factor) { return scale(T(1) / factor); }

	T operator[](const int index) const;

public:
	T getX() const { return x; }

	T getY() const { return y; }

	T getZ() const { return z; }

	void setX(const T x) { this->x = x; }

	void setY(const T y) { this->y = y; }

	void setZ(const T z) { this->z = z; }

	void set(const T x, const T y, const T z) {
		this->x = x;
		this->y = y;
		this->z = z;
	}

	std::vector< T > toArray() const { return std::vector < T > { x, y, z }; }

	std::array< T, 3 > toArray3() const { return std::array < T, 3 > { x, y, z }; }

private:
	T x;
	T y;
	T z;
};

template<typename T>
static Vector3d<T> operator*(T factor, const Vector3d<T>& rhs) { return rhs.scaled(factor); }

template<typename T>
static Vector3d<T> operator/(T factor, const Vector3d<T>& rhs) { return rhs.scaled(1.0f / factor); }


	}
}

#endif