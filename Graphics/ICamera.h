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

	virtual ~ICamera() = default;

	void setCameraXY() { pos = glm::vec3(0.0, 0.0, 1.0); }

	void setCameraYZ() { pos = glm::vec3(1.0, 0.0, 0.0); }

	void setCameraZX() { pos = glm::vec3(0.0, 1.0, 0.0); }

	void moveLookatTo(const glm::vec3& p) { this->lookat = p; }

	void move(const glm::vec3& v);

	void translate(const glm::vec3& v);

	void moveTo(const glm::vec3& p) { this->pos = p; }

	glm::vec3 getPosition() const { return pos; }

	glm::mat4x4 getModelviewMatrix() const;

	void setFar(const float f) { this->far_ = f; }

	void setNear(const float n) { this->near_ = n; }

	float getFar() const { return far_; }

	float getNear() const { return near_; }

	virtual glm::mat4x4 getProjectionMatrix() const = 0;

	glm::vec3 getForwardVector() const;

	glm::vec3 getUpVector() const;

	glm::vec3 getRightVector() const;

	void setUpVector(const glm::vec3& v) { this->up = v; }

	void rotate(const float azimuth, const float elevation);

protected:
	glm::vec3 pos;
	glm::vec3 up;
	glm::vec3 lookat;
	float azimuth;
	float elevation;
	float near_;
	float far_;
	float left;
	float right;
	float bottom;
	float top;
};

	}
}

#endif