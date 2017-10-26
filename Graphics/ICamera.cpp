#include "../Graphics/ICamera.h"

#include "../ThirdParty/glm-0.9.8.5/glm/gtc/matrix_transform.hpp"

using namespace Crystal::Graphics;

ICamera::ICamera() :
	up(0, 1, 0),
	lookat(0, 0, 0),
	azimuth(0.0),
	elevation(0.0)
{
	near_ = 1.0f;
	far_ = 10.0f;
	left = -0.5f;
	right = 0.5f;
	bottom = -0.5f;
	top = 0.5f;
}

void ICamera::move(const glm::vec3& v)
{
	this->pos += v;
}

void ICamera::translate(const glm::vec3& v)
{
	this->pos += v;
	this->lookat += v;
}

glm::mat4x4 ICamera::getModelviewMatrix() const
{
	glm::mat4 View = glm::translate(glm::mat4(1.0f), glm::vec3(pos));
	View = glm::rotate(View, azimuth, glm::vec3(-1.0f, 0.0f, 0.0f));
	View = glm::rotate(View, elevation, glm::vec3(0.0f, 1.0f, 0.0f));
	glm::mat4 Model = glm::scale(glm::mat4(1.0f), glm::vec3(0.5f));
	return View * Model;
}

glm::vec3 ICamera::getForwardVector() const
{
	const auto v = lookat - pos;
	return glm::normalize( v );
}

glm::vec3 ICamera::getUpVector() const
{
	return glm::normalize(up);
}

glm::vec3 ICamera::getRightVector() const
{
	return glm::normalize( glm::cross(getForwardVector(), getUpVector()) );
}