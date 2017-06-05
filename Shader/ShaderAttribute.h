#ifndef __CRYSTAL_SHADER_SHADER_ATTRIBUTE_H__
#define __CRYSTAL_SHADER_SHADER_ATTRIBUTE_H__

#include <string>
#include <array>
#include "GL/glew.h"
#include "ShaderType.h"

namespace Crystal {
	namespace Shader {
		class ShaderObject;

class ShaderAttribute
{
public:
	explicit ShaderAttribute(const std::string& name) :
		name(name)
	{}

	std::string getName() const { return name; }

	std::string getTypeName() const;

	virtual void render(ShaderObject& shader) = 0;

private:
	std::string name;
	ShaderType type;

};

class ShaderAttribute1f : public ShaderAttribute
{
public:
	explicit ShaderAttribute1f(const std::string& name) :
		ShaderAttribute(name)
	{}

	void setValue(const float v) { this->value = v; }

	void render(ShaderObject& shader) override;

private:
	float value;
};

class ShaderAttribute2f : public ShaderAttribute
{
public:
	explicit ShaderAttribute2f(const std::string& name) :
		ShaderAttribute(name)
	{}

	void render(ShaderObject& shader) override;

private:
	std::array<float, 2> value;
};



class ShaderAttribute3f : public ShaderAttribute
{
public:
	explicit ShaderAttribute3f(const std::string& name) :
		ShaderAttribute(name)
	{}

	void render(ShaderObject& shader) override;

private:
	std::array<float, 3> value;
};

class ShaderAttribute4f : public ShaderAttribute
{
public:
	explicit ShaderAttribute4f(const std::string& name) :
		ShaderAttribute(name)
	{}


	void render(ShaderObject& shader) override;

private:
	std::array<float,4> value;
};


	}
}

#endif