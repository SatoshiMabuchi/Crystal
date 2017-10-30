#include "gtest/gtest.h"
#include "../Graphics/PerspectiveCamera.h"
#include "../ThirdParty/glm-0.9.8.5/glm/gtc/matrix_transform.hpp"

using namespace Crystal::Graphics;

TEST(PerspectiveCameraTest, TestGetModelViewMatrix)
{
	PerspectiveCamera c;
	c.moveTo(glm::vec3(0, 0, 10));
	const auto& actual = c.getModelviewMatrix();
	glm::mat4x4 expected(
		1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.0f,10.0f, 1.0f
	);
	EXPECT_EQ(expected, actual);
}

TEST(PerspectiveCameraTest, TestGetProjectionMatrix)
{
	PerspectiveCamera c;
	c.setNear(1.0f);
	c.setFar(2.0f);
	c.setFovy(glm::pi<float>() * 0.5f);
	c.setAspect(1.0f);
	const auto& actual = c.getProjectionMatrix();
	const glm::mat4x4 expected(
		1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		0.0f, 0.0f,-3.0f,-1.0f,
		0.0f, 0.0f,-4.0f, 0.0f);
	EXPECT_EQ(expected, actual);
}