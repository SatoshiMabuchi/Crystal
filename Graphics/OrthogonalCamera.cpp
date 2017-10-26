#include "OrthogonalCamera.h"
#include "../ThirdParty/glm-0.9.8.5/glm/gtc/matrix_transform.hpp"

using namespace Crystal::Graphics;

void OrthogonalCamera::init()
{
	near_ = 1;
	far_ = 10.0;
	pos = glm::vec3(0,0,0);
}

glm::mat4x4 OrthogonalCamera::getProjectionMatrix() const
{
	return glm::ortho(left, right, bottom, top, near_, far_);
}