#ifndef __CRYSTAL_GRAPHICS_MATERIAL_H__
#define __CRYSTAL_GRAPHICS_MATERIAL_H__

#include <list>
#include <string>
#include <memory>

#include "ColorRGBA.h"
//#include "Texture.h"

namespace Crystal {
	namespace Graphics {


class Material
{
public:

	Material(const unsigned int id = 0) :
		shininess(1.0f),
		transparent(0.0f),
		id(id)
	{}

	~Material()
	{}

public:

	std::string getName() const { return name; }

	void setName(const std::string& name) { this->name = name; }

	void setAmbient(const glm::vec3& a) { this->ambient = a; }

	glm::vec3 getAmbient() const { return ambient; }

	void setDiffuse(const glm::vec3& d) { this->diffuse = d; }

	glm::vec3 getDiffuse() const { return diffuse; }

	void setSpecular(const glm::vec3& s) { this->specular = s; }

	glm::vec3 getSpecular() const { return specular; }

	void setShininess(const float s) { this->shininess = s; }

	float getShininess() const { return shininess; }

	void setTransparent(const float t) { this->transparent = t; }

	float getTransparent() const { return transparent; }

	//Texture getTexture() const { return texture; }

	//void setTexture(const Texture texture) { this->texture = texture; }

	int getTextureId() const { return textureId; }

	void setTextureId(const int id) { this->textureId = id; }

	unsigned int getId() const { return id; }

private:
	std::string name;

	float shininess;
	float transparent;
	glm::vec3 ambient;
	glm::vec3 diffuse;
	glm::vec3 specular;
	int textureId;

	unsigned int id;

	//Texture texture;
};

	}
}


#endif