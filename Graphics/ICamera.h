#ifndef __CRYSTAL_GRAPHICS_CAMERA_H__
#define __CRYSTAL_GRAPHICS_CAMERA_H__

#include "../Math/Vector3d.h"
#include "../Math/Matrix4d.h"

#include "../ThirdParty/glm-0.9.8.5/glm/gtc/matrix_transform.hpp"

namespace Crystal {
	namespace Graphics {

class ICamera
{
public:
	ICamera() :
		azimuth(0.0),
		elevation(0.0),
		near_(1.0f),
		far_(10.0f),
		scale(1.0f)
	{}

	ICamera(const glm::vec3& position, const glm::vec3& target, const float near_, const float far_) :
		azimuth(0.0),
		elevation(0.0),
		position(position),
		target(target),
		near_(near_),
		far_(far_),
		scale(1.0f)
	{}

	virtual ~ICamera() = default;

	void move(const glm::vec3& v) {
		this->position += v;
		this->target += v;
	}

	void moveTo(const glm::vec3& p) { this->position = p; }

	void setTarget(const Math::Vector3df& target) { this->target = target; }

	Math::Vector3df getPosition() const { return position; }

	Math::Matrix4df getRotateAround() const {
		glm::mat4 matrix = glm::translate(glm::mat4(1.0f), target);
		matrix = glm::rotate(matrix, azimuth, glm::vec3(-1.0f, 0.0f, 0.0f));
		matrix = glm::rotate(matrix, elevation, glm::vec3(0.0f, 1.0f, 0.0f));
		return glm::translate(matrix, -target);
	}

	Math::Matrix4df getModelviewMatrix() const {
		glm::mat4 view = glm::translate(glm::mat4(1.0f), position);
		//view = glm::rotate(view, azimuth, glm::vec3(-1.0f, 0.0f, 0.0f));
		//view = glm::rotate(view, elevation, glm::vec3(0.0f, 1.0f, 0.0f));
		view = view * getRotateAround();
		glm::mat4 model = glm::scale(glm::mat4(1.0f), glm::vec3(scale));
		return view * model;
	}

	void setFar(const float f) { this->far_ = f; }

	void setNear(const float n) { this->near_ = n; }

	float getFar() const { return far_; }

	float getNear() const { return near_; }

	virtual Math::Matrix4df getProjectionMatrix() const = 0;

	void setAngle(const float azimuth, const float elevation) {
		this->azimuth = azimuth;
		this->elevation = elevation;
	}

	void rotate(const float azimuth, const float elevation) {
		this->azimuth += azimuth;
		this->elevation += elevation;
	}

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