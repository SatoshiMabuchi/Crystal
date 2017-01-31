#include "gtest\gtest.h"

#include "../Math/Vector3d.h"

using namespace Crystal::Math;


template<class T>
class Vector3dTest : public testing::Test {
};

typedef ::testing::Types<float, double> TestTypes;

TYPED_TEST_CASE(Vector3dTest, TestTypes);

TYPED_TEST(Vector3dTest, TestGet)
{
	using T = TypeParam;
	EXPECT_EQ(0, Vector3d<T>().getX());
	EXPECT_EQ(0, Vector3d<T>().getY());
	EXPECT_EQ(0, Vector3d<T>().getZ());

	EXPECT_EQ(1, Vector3d<T>(1, 2, 3).getX());
	EXPECT_EQ(2, Vector3d<T>(1, 2, 3).getY());
	EXPECT_EQ(3, Vector3d<T>(1, 2, 3).getZ());
}

TYPED_TEST(Vector3dTest, TestScaled)
{
	using T = TypeParam;

	EXPECT_EQ(Vector3d<T>(2, 2, 2), Vector3d<T>(1, 1, 1).scaled(2));
	EXPECT_EQ(Vector3d<T>(1, 2, 3), Vector3d<T>(0.5, 1, 1.5).scaled(2));
}

TYPED_TEST(Vector3dTest, TestGetLengthSquared)
{
	using T = TypeParam;

	EXPECT_TRUE(Tolerance<T>::isEqualLoosely(3, Vector3d<T>(1, 1, 1).getLengthSquared()));
	EXPECT_TRUE(Tolerance<T>::isEqualStrictly(3, Vector3d<T>(1, 1, 1).getLengthSquared()));

	EXPECT_TRUE(Tolerance<T>::isEqualLoosely(14, Vector3d<T>(1, 2, 3).getLengthSquared()));
	EXPECT_TRUE(Tolerance<T>::isEqualStrictly(14, Vector3d<T>(1, 2, 3).getLengthSquared()));
}

TYPED_TEST(Vector3dTest, TestGetLength)
{
	using T = TypeParam;
	EXPECT_TRUE(Tolerance<T>::isEqualLoosely(std::sqrt(T(3)), Vector3d<T>(1, 1, 1).getLength()));
	EXPECT_TRUE(Tolerance<T>::isEqualStrictly(std::sqrt(T(3)), Vector3d<T>(1, 1, 1).getLength()));

	EXPECT_TRUE(Tolerance<T>::isEqualLoosely(std::sqrt(T(14)), Vector3d<T>(1, 2, 3).getLength()));
	EXPECT_TRUE(Tolerance<T>::isEqualStrictly(std::sqrt(T(14)), Vector3d<T>(1, 2, 3).getLength()));

}

TYPED_TEST(Vector3dTest, TestInnerProduct)
{
	using T = TypeParam;
	EXPECT_EQ(0, Vector3d<T>(0, 0, 0).getInnerProduct(Vector3d<T>(1, 1, 2)));
	EXPECT_EQ(8, Vector3d<T>(2, 2, 2).getInnerProduct(Vector3d<T>(1, 1, 2)));
}

TYPED_TEST(Vector3dTest, TestOuterProduct)
{
	using T = TypeParam;
	const Vector3d<T> vx(1, 0, 0);
	const Vector3d<T> vy(0, 1, 0);
	const Vector3d<T> vz(0, 0, 1);
	EXPECT_EQ(vz, vx.getOuterProduct(vy));
	EXPECT_EQ(vx, vy.getOuterProduct(vz));
	EXPECT_EQ(vy, vz.getOuterProduct(vx));
}

TYPED_TEST(Vector3dTest, TestGetDistance)
{
	using T = TypeParam;
	const Vector3d<T> v0(1, 1, 1);
	const Vector3d<T> v1(2, 2, 2);
	EXPECT_TRUE(Tolerance<T>::isEqualLoosely(v0.getDistance(v1), std::sqrt(T(3))));
	EXPECT_TRUE(Tolerance<T>::isEqualLoosely(v1.getDistance(v0), std::sqrt(T(3))));
}
