#ifndef __CRSYTAL_MATH_VECTOR_4D_H__
#define __CRSYTAL_MATH_VECTOR_4D_H__

#include <cmath>
#include <vector>
#include "Tolerance.h"
#include "Matrix4d.h"

namespace Crystal {
	namespace Math {

template<typename T>
class Vector4d
{
public:
	Vector4d(void) : Vector4d(0, 0, 0, 1.0)
	{}

	explicit Vector4d(const Vector3d<T>& v);

	Vector4d(const T x, const T y, const T z, const T w) :
		x(x), y(y), z(z), w(w)
	{}

	Vector4d(const Vector4d& start, const Vector4d& end) :
		x(end.x - start.x),
		y(end.y - start.y),
		z(end.z - start.z)
	{}

	T getLengthSquared() const { return x * x + y * y + z * z; }

	T getLength() const { return ::sqrt(getLengthSquared()); }

	T getDistance(const Vector4d& rhs) const { return ::sqrt(getDistanceSquared(rhs)); }

	T getDistanceSquared(const Vector4d& rhs) const;

	bool equals(const Vector4d&rhs) const { return Tolerance<T>::isZeroLoosely(getDistanceSquared(rhs)); }

	bool operator==(const Vector4d& rhs) const { return equals(rhs); }

	bool operator!=(const Vector4d& rhs) const { return !equals(rhs); }

	void multiple(const Matrix4d<T>& matrix) {
		*(this) = getMult(matrix);
	}


	Vector4d getMult(const Matrix4d<T>& matrix) const;

	Vector3d<T> toVector3d() const;

	Vector4d operator*(const Matrix4d<T>& matrix);


public:
	T getX() const { return x; }

	T getY() const { return y; }

	T getZ() const { return z; }

	T getW() const { return w; }

	void setX(const T x) { this->x = x; }

	void setY(const T y) { this->y = y; }

	void setZ(const T z) { this->z = z; }

	void setW(const T w) { this->w = w; }

private:
	T x;
	T y;
	T z;
	T w;
};
	}
}

#endif