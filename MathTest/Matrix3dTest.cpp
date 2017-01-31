#include "gtest/gtest.h"

#include "../Math/Matrix3d.h"
#include "../Math/Vector3d.h"

using namespace Crystal::Math;

template<class T>
class Matrix3dTest : public testing::Test
{
};


typedef ::testing::Types<double> TestTypes;

TYPED_TEST_CASE(Matrix3dTest, TestTypes);


TYPED_TEST(Matrix3dTest, TestConstruct)
{
	Matrix3d<TypeParam> m;
	EXPECT_TRUE(m.isIdentity());
}

TYPED_TEST(Matrix3dTest, TestRotateX)
{
	using T = TypeParam;

	EXPECT_EQ(
		Matrix3d<T>::Identity(),
		Matrix3d<T>::RotateX(0.0f));

	EXPECT_EQ(
		Matrix3d<T>(1.0, 0.0, 0.0, 0.0, 0.0f, -1.0, 0.0, 1.0, 0.0),
		Matrix3d<T>::RotateX(Tolerance<T>::getHalfPI()));

	EXPECT_EQ(
		Matrix3d<T>(1.0, 0.0, 0.0, 0.0, -1.0, 0.0, 0.0, 0.0, -1.0),
		Matrix3d<T>::RotateX(Tolerance<T>::getPI()));

	EXPECT_EQ(
		Matrix3d<T>(1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, -1.0, 0.0),
		Matrix3d<T>::RotateX(270.0 / 180.0 * Tolerance<T>::getPI()));

	EXPECT_EQ(
		Matrix3d<T>::Identity(),
		Matrix3d<T>::RotateX(Tolerance<T>::getTwoPI()));
}

TYPED_TEST(Matrix3dTest, TestRotateY)
{
	using T = TypeParam;

	EXPECT_EQ(
		Matrix3d<T>::Identity(),
		Matrix3d<T>::RotateY(0.0f));

	EXPECT_EQ(
		Matrix3d<T>(0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, -1.0f, 0.0f, 0.0f),
		Matrix3d<T>::RotateY(Tolerance<T>::getHalfPI()));

	EXPECT_EQ(
		Matrix3d<T>(-1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, -1.0f),
		Matrix3d<T>::RotateY(Tolerance<T>::getPI()));

	EXPECT_EQ(
		Matrix3d<T>(0.0f, 0.0f, -1.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f),
		Matrix3d<T>::RotateY(270.0 / 180.0 * Tolerance<T>::getPI()));

	EXPECT_EQ(
		Matrix3d<T>::Identity(),
		Matrix3d<T>::RotateY(Tolerance<T>::getTwoPI()));
}

TYPED_TEST(Matrix3dTest, TestRotateZ)
{
	using T = TypeParam;

	EXPECT_EQ(
		Matrix3d<T>::Identity(),
		Matrix3d<T>::RotateZ(0.0f));

	EXPECT_EQ(
		Matrix3d<T>(0.0f, -1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f),
		Matrix3d<T>::RotateZ(Tolerance<T>::getHalfPI()));

	EXPECT_EQ(
		Matrix3d<T>(-1.0, 0.0, 0.0, 0.0, -1.0, 0.0, 0.0, 0.0, 1.0),
		Matrix3d<T>::RotateZ(Tolerance<T>::getPI()));

	EXPECT_EQ(
		Matrix3d<T>(0.0, 1.0, 0.0, -1.0, 0.0, 0.0, 0.0, 0.0, 1.0),
		Matrix3d<T>::RotateZ(270.0 / 180.0 * Tolerance<T>::getPI()));

	EXPECT_EQ(
		Matrix3d<T>::Identity(),
		Matrix3d<T>::RotateZ(Tolerance<T>::getTwoPI()));
}

TYPED_TEST(Matrix3dTest, TestScale)
{
	Matrix3d<TypeParam> m = Matrix3d<TypeParam>::Identity();
	EXPECT_TRUE(m.isIdentity());

	const Matrix3d<TypeParam>& scaled = m.getScaled(2.0f);

	const Matrix3d<TypeParam> expected(
		2.0f, 0.0f, 0.0f,
		0.0f, 2.0f, 0.0f,
		0.0f, 0.0f, 2.0f
	);
	EXPECT_EQ(expected, scaled);

	m.scale(2.0f);

	EXPECT_EQ(expected, m);
}

TYPED_TEST(Matrix3dTest, TestDeterminantFloat)
{
	using T = TypeParam;
	EXPECT_TRUE(Tolerance<T>::isEqualStrictly(0, Matrix3d<T>::Zero().getDeterminant()));
	EXPECT_TRUE(Tolerance<T>::isEqualStrictly(1, Matrix3d<T>::Identity().getDeterminant()));
}

TYPED_TEST(Matrix3dTest, TestInverse)
{
	using T = TypeParam;
	const auto mi = Matrix3d<T>::Identity();
	EXPECT_EQ(mi, mi.getInverse());
}

TYPED_TEST(Matrix3dTest, TestIsRegular)
{
	const auto mi = Matrix3d<TypeParam>::Identity();
	const auto m1 = Matrix3d<TypeParam>(1, 1, 1, 1, 1, 1, 1, 1, 1);
	EXPECT_TRUE( mi.isRegular());
	EXPECT_FALSE(m1.isRegular());
}

TYPED_TEST(Matrix3dTest, TestGetRowVector)
{
	using T = TypeParam;
	const Matrix3d<T> m(1, 2, 3, 4, 5, 6, 7, 8, 9);
	EXPECT_EQ(Vector3d<T>(1, 2, 3), m.getRowVector(0));
	EXPECT_EQ(Vector3d<T>(4, 5, 6), m.getRowVector(1));
	EXPECT_EQ(Vector3d<T>(7, 8, 9), m.getRowVector(2));
}

TYPED_TEST(Matrix3dTest, TestGetColumnVector)
{
	using T = TypeParam;
	const Matrix3d<T> m(1, 2, 3, 4, 5, 6, 7, 8, 9);
	EXPECT_EQ(Vector3d<T>(1, 4, 7), m.getColumnVector(0));
	EXPECT_EQ(Vector3d<T>(2, 5, 8), m.getColumnVector(1));
	EXPECT_EQ(Vector3d<T>(3, 6, 9), m.getColumnVector(2));
}