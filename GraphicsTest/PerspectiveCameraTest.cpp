#include "gtest/gtest.h"
#include "../Graphics/PerspectiveCamera.h"

using namespace Crystal::Math;
using namespace Crystal::Graphics;

using T = float;

TEST(PerspectiveCameraTest, TestGetModelViewMatrix)
{
	PerspectiveCamera<T> c;
	c.moveTo(Vector3d<T>(0, 0, 10));
	const auto& actual = c.getModelviewMatrix();
	const Matrix4d<T> expected(
		1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		0, 0, -10, 1);
	EXPECT_EQ(expected, actual);
}

TEST(PerspectiveCameraTest, TestGetProjectionMatrix)
{
	PerspectiveCamera<T> c;
	c.setNear(1.0f);
	c.setFar(2.0f);
	const auto& actual = c.getProjectionMatrix();
	const Matrix4d<T> expected(
		2, 0, 0, 0,
		0, 2, 0, 0,
		0, 0, -3, -1,
		0, 0, -4, 0);
	EXPECT_EQ(expected, actual);
}

TEST(PerspectiveCameraTest, TestGetPosition)
{
	PerspectiveCamera<T> c;
	c.setNear(1.0f);
	c.setFar(2.0f);
	c.moveTo(Vector3d<T>(0, 0, 10));
	const auto actual = c.getPosition(Vector3d<T>(1, 1, 1));
	const Vector3d<T> expected(-2, -2, -6);
	EXPECT_EQ(expected, actual);
}