#include "gtest\gtest.h"
#include "../Math/Vector2d.h"

using namespace Crystal::Math;

template<class T>
class Vector2dTest : public testing::Test
{
};

using TestTypes = ::testing::Types<float, double>;

TYPED_TEST_CASE(Vector2dTest, TestTypes);

TYPED_TEST(Vector2dTest, TestScaled)
{
	using T = TypeParam;
	Vector2d<T> v(1, 2);
	EXPECT_EQ(Vector2d<T>(2, 4), v.scaled(2));
}

TYPED_TEST(Vector2dTest, TestGetLength)
{
	using T = TypeParam;
	EXPECT_EQ(1, Vector2d<T>(1, 0).getLength());
	EXPECT_EQ(std::sqrt(T{ 2 }), Vector2d<T>(1, 1).getLength());
	EXPECT_EQ(std::sqrt(T{ 5 }), Vector2d<T>(2, 1).getLength());
}

TYPED_TEST(Vector2dTest, TestGetLengthSquared)
{
	using T = TypeParam;
	EXPECT_EQ(T{ 1 }, Vector2d<T>(1, 0).getLengthSquared());
	EXPECT_EQ(T{ 2 }, Vector2d<T>(1, 1).getLengthSquared());
	EXPECT_EQ(T{ 5 }, Vector2d<T>(2, 1).getLengthSquared());
}