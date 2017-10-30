#ifndef __CRYSTAL_GRAPHICS_CAMERA_H__
#define __CRYSTAL_GRAPHICS_CAMERA_H__

#include "../ThirdParty/glm-0.9.8.5/glm/vec3.hpp"
#include "../ThirdParty/glm-0.9.8.5/glm/vec4.hpp"
#include "../ThirdParty/glm-0.9.8.5/glm/mat4x4.hpp"

namespace Crystal {
	namespace Graphics {

class ICamera
{
public:
	ICamera();

	ICamera(const glm::vec3& position, const float near_, const float far_);

	virtual ~ICamera() = default;

	void move(const glm::vec3& v);

	void moveTo(const glm::vec3& p) { this->position = p; }

	glm::vec3 getPosition() const { return position; }

	glm::mat4x4 getModelviewMatrix() const;

	void setFar(const float f) { this->far_ = f; }

	void setNear(const float n) { this->near_ = n; }

	float getFar() const { return far_; }

	float getNear() const { return near_; }

	virtual glm::mat4x4 getProjectionMatrix() const = 0;

	void rotate(const float azimuth, const float elevation);

	void zoom(const float s) { this->scale += s; }

protected:
	glm::vec3 position;
	float azimuth;
	float elevation;
	float near_;
	float far_;
	float scale;
};

	}
}

#endif