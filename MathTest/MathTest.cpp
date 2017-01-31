// MathTest.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include "gtest\gtest.h"
#include "../Math/Vector3d.h"

using namespace Crystal::Math;

TEST(Vector3dTest, Test)
{
	Vector3d<float> v(1, 0, 0);
	EXPECT_EQ(1, v.getLength());
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}