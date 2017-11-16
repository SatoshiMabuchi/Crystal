#include "../Math/Vector3d.h"
#include "gtest/gtest.h"

using namespace Crystal::Math;

TEST(Vector3ddTest, TestIsEqualLoosely)
{
	EXPECT_TRUE( isEqualLoosely(Vector3dd(0, 0, 0), Vector3dd(0, 0, 0)));
	EXPECT_FALSE(isEqualLoosely(Vector3dd(1, 0, 0), Vector3dd(0, 0, 0)));
}