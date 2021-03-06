#include "gtest\gtest.h"

#include "../Math/Triangle3d.h"

using namespace Crystal::Math;

TEST(Triangle3dTest, TestGetNormal)
{
	std::array<Vector3dd, 3> vertices = {
		Vector3dd(0,0,0),
		Vector3dd(1,0,0),
		Vector3dd(0,1,0)
	};
	Triangle3d triangle(vertices);
	EXPECT_EQ(Vector3dd(0, 0, 1), triangle.getNormal());
}

TEST(Triangle3dTest, TestGetArea)
{
	std::array<Vector3dd, 3> vertices = {
		Vector3dd(0,0,0),
		Vector3dd(1,0,0),
		Vector3dd(0,1,0)
	};
	Triangle3d triangle(vertices);
	EXPECT_DOUBLE_EQ(0.5, triangle.getArea());
}