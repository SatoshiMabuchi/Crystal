#include "gtest\gtest.h"

#include "../Math/Triangle3d.h"

using namespace Crystal::Math;

TEST(Triangle3dTest, TestGetNormal)
{
	std::array<Vector3d<double>, 3> vertices = {
		Vector3d<double>(0,0,0),
		Vector3d<double>(1,0,0),
		Vector3d<double>(0,1,0)
	};
	Triangle3d<double> triangle(vertices);
	EXPECT_EQ(Vector3d<double>(0, 0, 1), triangle.getNormal());
}

TEST(Triangle3dTest, TestGetArea)
{
	std::array<Vector3d<double>, 3> vertices = {
		Vector3d<double>(0,0,0),
		Vector3d<double>(1,0,0),
		Vector3d<double>(0,1,0)
	};
	Triangle3d<double> triangle(vertices);
	EXPECT_FLOAT_EQ(0.5, triangle.getArea());
}