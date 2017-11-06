#include "gtest/gtest.h"

#include "../Math/Sphere3d.h"
#include "../Math/Box3d.h"

using namespace Crystal::Math;

using T = float;

TEST(Sphere3dTest, OffsetTest)
{
	Sphere3d<float> s;
	s.outerOffset(1.0f);
	EXPECT_EQ(2.0f, s.getRadius());

	s.innerOffset(1.0f);
	EXPECT_EQ(1.0f, s.getRadius());
}

TEST(Sphere3dTest, TestIsInner)
{
	Sphere3d<float> s(Vector3df(0.0, 0.0, 0.0), 1.0f);
	EXPECT_TRUE(s.isInner(Vector3df(0.0f, 0.0f, 0.0f)));
	EXPECT_FALSE(s.isInner(Vector3df(2.0f, 0.0f, 0.0f)));
}

TEST(Sphere3dTest, TestGetPositionByAngle)
{
	using T = float;
	const Sphere3d<T> s(Vector3dd(0.0, 0.0, 0.0), 1.0);
	const auto pi = Tolerance<T>::getPI();

	EXPECT_EQ(Vector3dd( 0, 0, 1), s.getPositionByAngle(0.0f*pi, 0.0f*pi));
	EXPECT_EQ(Vector3dd( 0, 0, 1), s.getPositionByAngle(0.0f*pi, 0.5f*pi));
	EXPECT_EQ(Vector3dd( 0, 0, 1), s.getPositionByAngle(0.0f*pi, 1.0f*pi));
	EXPECT_EQ(Vector3dd( 0, 0, 1), s.getPositionByAngle(0.0f*pi, 1.5f*pi));
	EXPECT_EQ(Vector3dd( 0, 0, 1), s.getPositionByAngle(0.0f*pi, 2.0f*pi));

	EXPECT_EQ(Vector3dd( 1, 0, 0), s.getPositionByAngle(0.5f*pi, 0.0f*pi));
	EXPECT_EQ(Vector3dd( 0, 1, 0), s.getPositionByAngle(0.5f*pi, 0.5f*pi));
	EXPECT_EQ(Vector3dd(-1, 0, 0), s.getPositionByAngle(0.5f*pi, 1.0f*pi));
	EXPECT_EQ(Vector3dd( 0,-1, 0), s.getPositionByAngle(0.5f*pi, 1.5f*pi));
	EXPECT_EQ(Vector3dd( 1, 0, 0), s.getPositionByAngle(0.5f*pi, 2.0f*pi));

	EXPECT_EQ(Vector3dd( 0, 0,-1), s.getPositionByAngle(1.0f*pi, 0.0f*pi));
	EXPECT_EQ(Vector3dd( 0, 0,-1), s.getPositionByAngle(1.0f*pi, 0.5f*pi));
	EXPECT_EQ(Vector3dd( 0, 0,-1), s.getPositionByAngle(1.0f*pi, 1.0f*pi));
	EXPECT_EQ(Vector3dd( 0, 0,-1), s.getPositionByAngle(1.0f*pi, 1.5f*pi));
	EXPECT_EQ(Vector3dd( 0, 0,-1), s.getPositionByAngle(1.0f*pi, 2.0f*pi));
}

TEST(Sphere3dTest, TestGetPositionByParam)
{
	using T = float;
	const Sphere3d<T> s(Vector3dd(0.0, 0.0, 0.0), 1.0);
	EXPECT_EQ(Vector3dd( 0, 0, 1), s.getPositionByParam(0.0, 0.0 ));
	EXPECT_EQ(Vector3dd( 0, 0, 1), s.getPositionByParam(0.0, 0.25));
	EXPECT_EQ(Vector3dd( 0, 0, 1), s.getPositionByParam(0.0, 0.5 ));
	EXPECT_EQ(Vector3dd( 0, 0, 1), s.getPositionByParam(0.0, 0.75));
	EXPECT_EQ(Vector3dd( 0, 0, 1), s.getPositionByParam(0.0, 1.0 ));

	EXPECT_EQ(Vector3dd( 1, 0, 0), s.getPositionByParam(0.5, 0.0 ));
	EXPECT_EQ(Vector3dd( 0, 1, 0), s.getPositionByParam(0.5, 0.25));
	EXPECT_EQ(Vector3dd(-1, 0, 0), s.getPositionByParam(0.5, 0.5 ));
	EXPECT_EQ(Vector3dd( 0,-1, 0), s.getPositionByParam(0.5, 0.75));
	EXPECT_EQ(Vector3dd( 1, 0, 0), s.getPositionByParam(0.5, 1.0 ));

	EXPECT_EQ(Vector3dd( 0, 0,-1), s.getPositionByParam(1.0, 0.0 ));
	EXPECT_EQ(Vector3dd( 0, 0,-1), s.getPositionByParam(1.0, 0.25));
	EXPECT_EQ(Vector3dd( 0, 0,-1), s.getPositionByParam(1.0, 0.5 ));
	EXPECT_EQ(Vector3dd( 0, 0,-1), s.getPositionByParam(1.0, 0.75));
	EXPECT_EQ(Vector3dd( 0, 0,-1), s.getPositionByParam(1.0, 1.0 ));
}