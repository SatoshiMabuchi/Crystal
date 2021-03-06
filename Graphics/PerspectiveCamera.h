#ifndef __CRYSTAL_GRAPHICS_PERSPECTIVE_CAMERA_H__
#define __CRYSTAL_GRAPHICS_PERSPECTIVE_CAMERA_H__

#include "ICamera.h"
#include "../ThirdParty/glm-0.9.8.5/glm/gtc/matrix_transform.hpp"

namespace Crystal {
	namespace Graphics {

class PerspectiveCamera : public ICamera
{
public:
	PerspectiveCamera(){}

	PerspectiveCamera(const float fovy, const float aspect) :
		fovy(fovy),
		aspect(aspect)
	{}

	PerspectiveCamera(const float fovy, const float aspect, const glm::vec3& target, const glm::vec3& position, const float near, const float far) :
		fovy(fovy),
		aspect(aspect),
		ICamera(target, position, near_, far_)
	{}


	void setFovy(const float fovy) { this->fovy = fovy; }

	void setAspect(const float aspect) { this->aspect = aspect; }

	glm::mat4 getProjectionMatrix() const override {
		return glm::perspective(fovy, aspect, near_, far_);
	}

private:
	float fovy;
	float aspect;
};

	}
}

#endif