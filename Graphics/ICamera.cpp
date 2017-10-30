#include "../Graphics/ICamera.h"

#include "../ThirdParty/glm-0.9.8.5/glm/gtc/matrix_transform.hpp"

using namespace Crystal::Graphics;

ICamera::ICamera() :
	azimuth(0.0),
	elevation(0.0),
	near_(1.0f),
	far_(10.0f)
{
}

ICamera::ICamera(const glm::vec3& position, const float near_, const float far_) :
	azimuth(0.0),
	elevation(0.0),
	position(position),
	near_(near_),
	far_(far_)
{
}

void ICamera::move(const glm::vec3& v)
{
	this->position += v;
}

glm::mat4x4 ICamera::getModelviewMatrix() const
{
	glm::mat4 View = glm::translate(glm::mat4(1.0f), position);
	View = glm::rotate(View, azimuth, glm::vec3(-1.0f, 0.0f, 0.0f));
	View = glm::rotate(View, elevation, glm::vec3(0.0f, 1.0f, 0.0f));
	glm::mat4 Model = glm::scale(glm::mat4(1.0f), glm::vec3(1.0f));
	return View * Model;
}

void ICamera::rotate(const float azimuth, const float elevation)
{
	this->azimuth += azimuth;
	this->elevation += elevation;
}
