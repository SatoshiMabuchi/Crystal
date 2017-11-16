#ifndef __CRYSTAL_GRAPHICS_CAMERA_H__
#define __CRYSTAL_GRAPHICS_CAMERA_H__

#include "../Math/Vector3d.h"
#include "../Math/Matrix4d.h"

namespace Crystal {
	namespace Graphics {

class ICamera
{
public:
	ICamera();

	ICamera(const glm::vec3& position, const glm::vec3& target, const float near_, const float far_);

	virtual ~ICamera() = default;

	void move(const glm::vec3& v);

	void moveTo(const glm::vec3& p) { this->position = p; }

	void setTarget(const Math::Vector3df& target) { this->target = target; }

	Math::Vector3df getPosition() const { return position; }

	Math::Matrix4df getRotateAround() const;

	Math::Matrix4df getModelviewMatrix() const;

	void setFar(const float f) { this->far_ = f; }

	void setNear(const float n) { this->near_ = n; }

	float getFar() const { return far_; }

	float getNear() const { return near_; }

	virtual Math::Matrix4df getProjectionMatrix() const = 0;

	void setAngle(const float azimuth, const float elevation);

	void rotate(const float azimuth, const float elevation);

	void zoom(const float s) { this->scale += s; }

protected:
	Math::Vector3df target;
	Math::Vector3df position;
	float azimuth;
	float elevation;
	float near_;
	float far_;
	float scale;
};

	}
}

#endif