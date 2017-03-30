#include "gtest/gtest.h"

#include "../Math/Sphere3d.h"
#include "../Math/Box3d.h"

using namespace Crystal::Math;

using T = float;

TEST(Sphere3dTest, BoundingBoxTest)
{
	Sphere3d<float> s;
	const Box3d<T>& bb = s.getBoundingBox();
	const Box3d<T> expected(Vector3d<float>(-1.0, -1.0, -1.0), Vector3d<float>(1.0, 1.0, 1.0));
	EXPECT_EQ(expected, bb);
}

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
	Sphere3d<float> s(Vector3d<float>(0.0, 0.0, 0.0), 1.0f);
	EXPECT_TRUE(s.isInner(Vector3d<float>(0.0f, 0.0f, 0.0f)));
	EXPECT_FALSE(s.isInner(Vector3d<float>(2.0f, 0.0f, 0.0f)));
}

TEST(Sphere3dTest, TestIsOnStrictly)
{
	Sphere3d<float> s(Vector3d<float>(0.0, 0.0, 0.0), 1.0f);
	EXPECT_TRUE(s.isOnStrictly(Vector3d<float>(1.0f, 0.0, 0.0f)));
}

/*
TEST(Sphere3dTest, TestGetPositionByAngle)
{
	using T = float;
	const Sphere3d<T> s(Vector3d<T>(0.0, 0.0, 0.0), 1.0f);
	EXPECT_EQ(Vector3d<T>(0, 0, -1), s.getPosition(Angle<T>::Zero(), -Angle<T>::HalfPI()));
	EXPECT_EQ(Vector3d<T>(1, 0, 0), s.getPosition(Angle<T>::Zero(), Angle<T>::Zero()));
	EXPECT_EQ(Vector3d<T>(0, 0, 1), s.getPosition(Angle<T>::Zero(), Angle<T>::HalfPI()));

	EXPECT_EQ(Vector3d<T>(0, 0, -1), s.getPosition(Angle<T>::HalfPI(), -Angle<T>::HalfPI()));
	EXPECT_EQ(Vector3d<T>(0, 1, 0), s.getPosition(Angle<T>::HalfPI(), Angle<T>::Zero()));
	EXPECT_EQ(Vector3d<T>(0, 0, 1), s.getPosition(Angle<T>::HalfPI(), Angle<T>::HalfPI()));

	EXPECT_EQ(Vector3d<T>(0, 0, -1), s.getPosition(Angle<T>::PI(), -Angle<T>::HalfPI()));
	EXPECT_EQ(Vector3d<T>(-1, 0, 0), s.getPosition(Angle<T>::PI(), Angle<T>::Zero()));
	EXPECT_EQ(Vector3d<T>(0, 0, 1), s.getPosition(Angle<T>::PI(), Angle<T>::HalfPI()));

	EXPECT_EQ(Vector3d<T>(0, 0, -1), s.getPosition(Angle<T>::HalfPI() * 3, -Angle<T>::HalfPI()));
	EXPECT_EQ(Vector3d<T>(0, -1, 0), s.getPosition(Angle<T>::HalfPI() * 3, Angle<T>::Zero()));
	EXPECT_EQ(Vector3d<T>(0, 0, 1), s.getPosition(Angle<T>::HalfPI() * 3, Angle<T>::HalfPI()));

	EXPECT_EQ(Vector3d<T>(0, 0, -1), s.getPosition(Angle<T>::DoublePI(), -Angle<T>::HalfPI()));
	EXPECT_EQ(Vector3d<T>(1, 0, 0), s.getPosition(Angle<T>::DoublePI(), Angle<T>::Zero()));
	EXPECT_EQ(Vector3d<T>(0, 0, 1), s.getPosition(Angle<T>::DoublePI(), Angle<T>::HalfPI()));
}
*/

TEST(Sphere3dTest, TestGetPositionByParam)
{
	using T = float;
	const Sphere3d<T> s(Vector3d<T>(0.0, 0.0, 0.0), 1.0);
	EXPECT_EQ(Vector3d<T>( 0, 0, 1), s.getPositionByParam(0.0,0.0));
	EXPECT_EQ(Vector3d<T>( 0, 0, 1), s.getPositionByParam(0.0,0.5));
	EXPECT_EQ(Vector3d<T>( 0, 0, 1), s.getPositionByParam(0.0,1.0));

	EXPECT_EQ(Vector3d<T>( 1, 0, 0), s.getPositionByParam(0.5, 0.0));
	EXPECT_EQ(Vector3d<T>(-1, 0, 0), s.getPositionByParam(0.5, 0.5));
	EXPECT_EQ(Vector3d<T>( 1, 0, 0), s.getPositionByParam(0.5, 1.0));
	/*

	EXPECT_EQ(Vector3d<T>(0, 0, -1), s.getPosition(Param<T>(0.5), Param<T>(0.0)));
	EXPECT_EQ(Vector3d<T>(-1, 0, 0), s.getPosition(Param<T>(0.5), Param<T>(0.5)));
	EXPECT_EQ(Vector3d<T>(0, 0, 1), s.getPosition(Param<T>(0.5), Param<T>(1.0)));

	EXPECT_EQ(Vector3d<T>(0, 0, -1), s.getPosition(Param<T>(0.75), Param<T>(0.0)));
	EXPECT_EQ(Vector3d<T>(0, -1, 0), s.getPosition(Param<T>(0.75), Param<T>(0.5)));
	EXPECT_EQ(Vector3d<T>(0, 0, 1), s.getPosition(Param<T>(0.75), Param<T>(1.0)));

	EXPECT_EQ(Vector3d<T>(0, 0, -1), s.getPosition(Param<T>(1.0), Param<T>(0.0)));
	EXPECT_EQ(Vector3d<T>(1, 0, 0), s.getPosition(Param<T>(1.0), Param<T>(0.5)));
	EXPECT_EQ(Vector3d<T>(0, 0, 1), s.getPosition(Param<T>(1.0), Param<T>(1.0)));
	*/
}