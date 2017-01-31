#include "gtest/gtest.h"

#include "../Math/Quaternion.h"
#include "../Math/Matrix3d.h"

using namespace Crystal::Math;

template<class T>
class QuaternionTest : public testing::Test
{
};

using TestTypes = ::testing::Types<float>;

TYPED_TEST_CASE(QuaternionTest, TestTypes);

TYPED_TEST(QuaternionTest, TestGetConjugate)
{
	using T = TypeParam;
	const Quaternion<T> q(1, 2, 3, 1);
	const Quaternion<T> expected(-1, -2, -3, 1);
	EXPECT_EQ(expected, q.getConjugate());
}

TYPED_TEST(QuaternionTest, TestGetInverse)
{
	using T = TypeParam;
	{
		const Quaternion<T> q(0, 0, 0, 1);
		const auto actual = q.getInverse();
		const Quaternion<T> expected(0, 0, 0, 1);
		EXPECT_EQ(expected, actual);
	}

	{
		const Quaternion<T> q(1, 2, 3, 1);
		const auto actual = q.getInverse();
		const auto m = q.mult(actual);
		EXPECT_EQ(m, Quaternion<T>());
	}
}

TYPED_TEST(QuaternionTest, TestMult)
{
	using T = TypeParam;
	{
		const Quaternion<T> q1(0, 0, 0, 1);
		const Quaternion<T> q2(1, 1, 1, 1);
		const auto actual = q1.mult(q2);
		EXPECT_EQ(Quaternion<T>(1, 1, 1, 1), actual);
	}

	{
		Quaternion<T> q1(Vector3d<T>(1, 0, 0), Tolerance<T>::getHalfPI());
		Quaternion<T> q2(Vector3d<T>(0, 1, 0), Tolerance<T>::getHalfPI());
		const auto q3 = q1 * q2;
		const auto& expected = q3.toMatrix();
		const auto& actual = Matrix3d<T>::RotateX(Tolerance<T>::getHalfPI()) * Matrix3d<T>::RotateY(Tolerance<T>::getHalfPI());
		EXPECT_EQ(expected, actual);
	}

	{
		Quaternion<T> q1(Vector3d<T>(1, 0, 0), Tolerance<T>::getHalfPI());
		Quaternion<T> q2(Vector3d<T>(0, 0, 1), Tolerance<T>::getHalfPI());
		const auto q3 = q1 * q2;
		const auto& expected = q3.toMatrix();
		const auto& actual = Matrix3d<T>::RotateX(Tolerance<T>::getHalfPI()) * Matrix3d<T>::RotateZ(Tolerance<T>::getHalfPI());
		EXPECT_EQ(expected, actual);
	}

	{
		Quaternion<T> q1(Vector3d<T>(1, 0, 0), Tolerance<T>::getHalfPI());
		Quaternion<T> q2(Vector3d<T>(0, 1, 0), Tolerance<T>::getHalfPI());
		Quaternion<T> q3(Vector3d<T>(0, 0, 1), Tolerance<T>::getHalfPI());
		const auto q4 = q1 * q2 * q3;
		const auto& expected = q4.toMatrix();
		const auto& actual = Matrix3d<T>::RotateX(Tolerance<T>::getHalfPI()) * Matrix3d<T>::RotateY(Tolerance<float>::getHalfPI()) * Matrix3d<T>::RotateZ(Tolerance<T>::getHalfPI());
		EXPECT_EQ(expected, actual);
	}
}

TYPED_TEST(QuaternionTest, TestToMatrix)
{
	using T = TypeParam;
	const Quaternion<T> q(0, 0, 0, 1);
	const auto& actual = q.toMatrix();
	EXPECT_EQ(Matrix3d<T>::Identity(), actual);
}

TYPED_TEST(QuaternionTest, TestSlerp)
{
	using T = TypeParam;
	const Quaternion<T> q1(Vector3d<T>(1, 0, 0), 0);
	const Quaternion<T> q2(Vector3d<T>(1, 0, 0), Tolerance<T>::getHalfPI());
	const Quaternion<T> q3(Vector3d<T>(1, 0, 0), Tolerance<T>::getPI());

	const Quaternion<T> expected1(Vector3d<T>(1, 0, 0), Tolerance<T>::getHalfPI()*0.5f);
	const Quaternion<T> expected2(Vector3d<T>(1, 0, 0), Tolerance<T>::getPI()*0.75f);

	EXPECT_EQ(expected1, q1.slerp(q2, 0.5));
	EXPECT_EQ(expected2, q2.slerp(q3, 0.5));
}