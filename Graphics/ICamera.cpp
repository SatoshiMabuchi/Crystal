#include "../Graphics/ICamera.h"

#include "../ThirdParty/glm-0.9.8.5/glm/gtc/matrix_transform.hpp"

using namespace Crystal::Math;
using namespace Crystal::Graphics;

ICamera::ICamera() :
	azimuth(0.0),
	elevation(0.0),
	near_(1.0f),
	far_(10.0f),
	scale(1.0f)
{
}

ICamera::ICamera(const glm::vec3& position, const glm::vec3& target, const float near_, const float far_) :
	azimuth(0.0),
	elevation(0.0),
	position(position),
	target(target),
	near_(near_),
	far_(far_),
	scale(1.0f)
{
}

void ICamera::move(const glm::vec3& v)
{
	this->position += v;
	this->target += v;
}

glm::mat4x4 ICamera::getRotateAround() const
{
	glm::mat4 matrix = glm::translate(glm::mat4(1.0f), target);
	matrix = glm::rotate(matrix, azimuth, glm::vec3(-1.0f, 0.0f, 0.0f));
	matrix = glm::rotate(matrix, elevation, glm::vec3(0.0f, 1.0f, 0.0f));
	return glm::translate(matrix, -target);
}

glm::mat4x4 ICamera::getModelviewMatrix() const
{
	glm::mat4 view = glm::translate(glm::mat4(1.0f), position);
	//view = glm::rotate(view, azimuth, glm::vec3(-1.0f, 0.0f, 0.0f));
	//view = glm::rotate(view, elevation, glm::vec3(0.0f, 1.0f, 0.0f));
	view = view * getRotateAround();
	glm::mat4 model = glm::scale(glm::mat4(1.0f), glm::vec3(scale));
	return view * model;
}

void ICamera::setAngle(const float azimuth, const float elevation)
{
	this->azimuth = azimuth;
	this->elevation = elevation;
}

void ICamera::rotate(const float azimuth, const float elevation)
{
	this->azimuth += azimuth;
	this->elevation += elevation;
}
