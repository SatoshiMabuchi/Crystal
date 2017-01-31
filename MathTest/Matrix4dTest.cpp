#include "gtest/gtest.h"

#include "../Math/Matrix4d.h"
#include "../Math/Vector3d.h"

using namespace Crystal::Math;

template<class T>
class Matrix4dTest : public testing::Test
{
};

using TestTypes = ::testing::Types<double>;

TYPED_TEST_CASE(Matrix4dTest, TestTypes);

TYPED_TEST(Matrix4dTest, TestRotate)
{
	using T = TypeParam;
	EXPECT_EQ(Matrix4d<T>::Identity(), Matrix4d<T>::RotateX(0.0f));
	EXPECT_EQ(Matrix4d<T>::Identity(), Matrix4d<T>::RotateY(0.0f));
	EXPECT_EQ(Matrix4d<T>::Identity(), Matrix4d<T>::RotateZ(0.0f));
}

TYPED_TEST(Matrix4dTest, TestToArrays)
{
	using T = TypeParam;

	const Matrix4d<T>& m = Matrix4d<T>::Identity();
	const auto& x = m.toArray();
	EXPECT_EQ(x[0], 1.0f);
	EXPECT_EQ(x[1], 0.0f);
	EXPECT_EQ(x[2], 0.0f);
	EXPECT_EQ(x[3], 0.0f);
}

TYPED_TEST(Matrix4dTest, TestMultipleVector3d)
{
	using T = TypeParam;

	Matrix4d<T> m(
		1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		1, 1, 1, 1);
	const auto actual = m.multiple(Vector3d<T>(1, 2, 3));
}

TYPED_TEST(Matrix4dTest, TestTransposed)
{
	using T = TypeParam;

	const Matrix4d<T> m(
		0, 1, 2, 3,
		10, 11, 12, 13,
		20, 21, 22, 23,
		30, 31, 32, 33);
	const auto actual = m.transposed();
	const Matrix4d<T> expected(
		0, 10, 20, 30,
		1, 11, 21, 31,
		2, 12, 22, 32,
		3, 13, 23, 33
	);
	EXPECT_EQ(expected, actual);
}

TYPED_TEST(Matrix4dTest, TestGetDeterminent)
{
	using T = TypeParam;

	const auto m1 = Matrix4d<T>::Identity();
	EXPECT_EQ(1, m1.getDeterminent());

	const Matrix4d<T> m2(
		 1, 1, 1,-1,
		 1, 1,-1, 1,
		 1,-1, 1, 1,
		-1, 1, 1, 1);
	EXPECT_EQ(-16, m2.getDeterminent());
}

TYPED_TEST(Matrix4dTest, TestGetInverse)
{
	using T = TypeParam;

	const Matrix4d<T> m1 = Matrix4d<T>::Identity();
	EXPECT_EQ(Matrix4d<T>::Identity(), m1.getInverse());

	const Matrix4d<T> m2(
		1, 1, 1, -1,
		1, 1, -1, 1,
		1, -1, 1, 1,
		-1, 1, 1, 1);
	const Matrix4d<T> expected(
		0.25, 0.25, 0.25, -0.25,
		0.25, 0.25, -0.25, 0.25,
		0.25, -0.25, 0.25, 0.25,
		-0.25, 0.25, 0.25, 0.25
	);
	EXPECT_EQ(expected, m2.getInverse());

}