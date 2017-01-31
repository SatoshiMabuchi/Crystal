#ifndef __CRYSTAL_MATH_MATRIX_4D_H__
#define __CRYSTAL_MATH_MATRIX_4D_H__

#include "Tolerance.h"

#include <cassert>
#include <array>

namespace Crystal {
	namespace Math {
		template<typename>
		class Vector3d;
		template<typename>
		class Vector4d;
		template<typename>
		class Matrix3d;

template< typename T >
class Matrix4d
{
public:
	Matrix4d(void);

	Matrix4d(const std::array<T, 16>& x);

	Matrix4d(
		const T x00, const T x01, const T x02, const T x03,
		const T x10, const T x11, const T x12, const T x13,
		const T x20, const T x21, const T x22, const T x23,
		const T x30, const T x31, const T x32, const T x33
	);

	explicit Matrix4d(const Matrix3d<T>& m);

	~Matrix4d(void) = default;

	static Matrix4d Zero();

	static Matrix4d Identity();

	static Matrix4d RotateX(const T angle);

	static Matrix4d RotateY(const T angle);

	static Matrix4d RotateZ(const T angle);

	void translate(const T x, const T y, const T z);

	void setScale(const T x, const T y, const T z);

	void multiple(const Matrix4d& rhs);

	Matrix4d<T> multipled(const Matrix4d<T>& rhs);

	Vector3d<T> multiple(const Vector3d<T>& v);

	Vector4d<T> multiple(const Vector4d<T>& v);

	void operator*=(const Matrix4d& rhs) { multiple(rhs); }

	bool equals(const Matrix4d& rhs) const;

	bool operator==(const Matrix4d& rhs) const { return equals(rhs); }

	bool operator!=(const Matrix4d& rhs) const { return !equals(rhs); }

	std::array< T, 16 > toArray() const { return x; }

	void setX00(const T v) { x[0] = v; }

	void setX01(const T v) { x[1] = v; }

	void setX02(const T v) { x[2] = v; }

	void setX03(const T v) { x[3] = v; }

	void setX10(const T v) { x[4] = v; }

	void setX11(const T v) { x[5] = v; }

	void setX12(const T v) { x[6] = v; }

	void setX13(const T v) { x[7] = v; }

	void setX20(const T v) { x[8] = v; }

	void setX21(const T v) { x[9] = v; }

	void setX22(const T v) { x[10] = v; }

	void setX23(const T v) { x[11] = v; }

	void setX30(const T v) { x[12] = v; }

	void setX31(const T v) { x[13] = v; }

	void setX32(const T v) { x[14] = v; }

	void setX33(const T v) { x[15] = v; }

	T getX00() const { return x[0]; }

	T getX01() const { return x[1]; }

	T getX02() const { return x[2]; }

	T getX03() const { return x[3]; }

	T getX10() const { return x[4]; }

	T getX11() const { return x[5]; }

	T getX12() const { return x[6]; }

	T getX13() const { return x[7]; }

	T getX20() const { return x[8]; }

	T getX21() const { return x[9]; }

	T getX22() const { return x[10]; }

	T getX23() const { return x[11]; }

	T getX30() const { return x[12]; }

	T getX31() const { return x[13]; }

	T getX32() const { return x[14]; }

	T getX33() const { return x[15]; }

	Matrix4d<T> getTransposed() const;

	T getDeterminent() const;

	Matrix4d<T> getInverse() const;

	T operator[](int index) { return x[index]; }

	Matrix4d<T> scaled(const T scale) const;

	void add(const Matrix4d<T>& rhs);

	void operator+=(const Matrix4d<T>& rhs);

	void operator-=(const Matrix4d<T>& rhs);

	Matrix4d<T> operator*(const Matrix4d<T>& rhs);

	Vector4d<T> operator*(const Vector4d<T>& v);

	Matrix4d<T> operator-();

private:
	std::array< T, 16 > x;
};

	}
}

#endif