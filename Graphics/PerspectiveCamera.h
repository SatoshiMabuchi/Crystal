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