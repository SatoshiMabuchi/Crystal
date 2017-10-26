#include "PerspectiveCamera.h"
#include "../ThirdParty/glm-0.9.8.5/glm/gtc/matrix_transform.hpp"

using namespace Crystal::Graphics;

void PerspectiveCamera::init()
{
	near_ = 1;
	far_ = 10.0;
	pos = glm::vec3(0,0,0);
}

glm::mat4 PerspectiveCamera::getProjectionMatrix() const
{
	return glm::perspective(glm::pi<float>() * 0.25f, 4.0f / 3.0f, 0.1f, 100.f);
}