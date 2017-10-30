#pragma once

#include "../ThirdParty/glm-0.9.8.5/glm/vec3.hpp"
#include "../ThirdParty/glm-0.9.8.5/glm/vec4.hpp"

namespace Crystal {
	namespace Graphics {

class PointLight {
public:
	PointLight() :
		position(0.0f,0.0f,0.0f),
		diffuse(0.0f, 0.0f, 0.0f),
		specular(0.0f, 0.0f, 0.0f)
	{
	}

	~PointLight() {};

public:


	glm::vec3 getDiffuse() const { return diffuse; }

	void setDiffuse(const glm::vec4& d) { this->diffuse = d; }

	glm::vec3 getSpecular() const { return specular; }

	void setSpecular(const glm::vec4& s) { this->specular = s; }

	glm::vec3 getAmbient() const { return ambient; }

	void setAmbient(const glm::vec4& a) { this->ambient = a; }

	glm::vec3 getPos() const { return position; }

	void setPos(const glm::vec3& pos) { this->position = pos; }

private:
	glm::vec3 position;
	glm::vec3 diffuse;
	glm::vec3 ambient;
	glm::vec3 specular;
};

	}
}