#ifndef __CRYSTAL_GRAPHICS_PERSPECTIVE_CAMERA_H__
#define __CRYSTAL_GRAPHICS_PERSPECTIVE_CAMERA_H__

#include "ICamera.h"

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
		ICamera(target, position, near, far)
	{}


	void setFovy(const float fovy) { this->fovy = fovy; }

	void setAspect(const float aspect) { this->aspect = aspect; }

	glm::mat4 getProjectionMatrix() const override;

private:
	float fovy;
	float aspect;
};

	}
}

#endif