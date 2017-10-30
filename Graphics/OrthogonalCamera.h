#ifndef __CRYSTAL_GRAPHICS_ORTHOGONAL_CAMERA_H__
#define __CRYSTAL_GRAPHICS_ORTHOGONAL_CAMERA_H__

#include "ICamera.h"

namespace Crystal {
	namespace Graphics {

class OrthogonalCamera : public ICamera
{
public:
	OrthogonalCamera() {}

	glm::mat4 getProjectionMatrix() const override;

private:

};

	}
}

#endif