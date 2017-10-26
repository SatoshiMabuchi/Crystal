#ifndef __CRYSTAL_GRAPHICS_PERSPECTIVE_CAMERA_H__
#define __CRYSTAL_GRAPHICS_PERSPECTIVE_CAMERA_H__

#include "ICamera.h"

namespace Crystal {
	namespace Graphics {

class PerspectiveCamera : public ICamera
{
public:
	PerspectiveCamera()
	{
		init();
	}

	void init();

	glm::mat4 getProjectionMatrix() const override;

private:
};

	}
}

#endif