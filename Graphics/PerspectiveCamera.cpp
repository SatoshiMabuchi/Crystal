#include "PerspectiveCamera.h"
#include "../ThirdParty/glm-0.9.8.5/glm/gtc/matrix_transform.hpp"

using namespace Crystal::Graphics;

glm::mat4 PerspectiveCamera::getProjectionMatrix() const
{
	return glm::perspective(fovy, aspect, near_, far_);
}