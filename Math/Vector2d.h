#ifndef __CRSYTAL_MATH_VECTOR_2D_H__
#define __CRSYTAL_MATH_VECTOR_2D_H__

#include <cmath>
#include <vector>
#include "Tolerance.h"

namespace Crystal {
	namespace Math {

template<typename T>
class Vector2d
{
public:
	Vector2d();

	Vector2d(const T x, const T y);

	T getX() const { return x; }

	T getY() const { return y; }

	T getDistanceSquared(const Vector2d& rhs) const;

	T getLengthSquared() const;

	T getLength() const;

	Vector2d& scale(const T scale);

	Vector2d scaled(const T scale) const;

	bool equals(const Vector2d& rhs) const;

	bool operator==(const Vector2d& rhs) const { return equals(rhs); }

	bool operator!=(const Vector2d& rhs) const { return !equals(rhs); }

	Vector2d operator+(const Vector2d& rhs) const { return Vector2d(x + rhs.x, y + rhs.y); }

	Vector2d operator-(const Vector2d& rhs) const { return Vector2d(x - rhs.x, y - rhs.y); }

	Vector2d& operator+=(const Vector2d& rhs);

	Vector2d& operator-=(const Vector2d& rhs);

	Vector2d operator/(const T factor) const { return scaled(T(1) / factor); }

	Vector2d operator/=(const T factor) { return scale(T(1) / factor); }

	Vector2d<T> normalize();

	Vector2d<T> normalized() const;

	//Angle<T> getAngle() const;

	//Angle<T> getAngle(const Vector2d<T>& rhs) const;

	//Angle<T> getSignedAngle(const Vector2d<T>& rhs) const;

	T getInnerProduct(const Vector2d<T>& rhs) const;

private:
	T x;
	T y;
};
	}
}

#endif