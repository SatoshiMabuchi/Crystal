#ifndef __CRYSTAL_SHADER_SHADER_ATTRIBUTE_H__
#define __CRYSTAL_SHADER_SHADER_ATTRIBUTE_H__

#include <string>
#include <array>
#include "GL/glew.h"
#include "ShaderType.h"

namespace Crystal {
	namespace Shader {
		class ShaderObject;

class IShaderAttribute
{
public:
	explicit IShaderAttribute(const std::string& name) :
		name(name)
	{}

	std::string getName() const { return name; }

	std::string getTypeName() const;

	virtual void render(ShaderObject& shader) = 0;

private:
	std::string name;
	ShaderType type;

};

class ShaderAttribute1f : public IShaderAttribute
{
public:
	explicit ShaderAttribute1f(const std::string& name) :
		IShaderAttribute(name)
	{}

	void setValue(const float v) { this->value = v; }

	void render(ShaderObject& shader) override;

private:
	float value;
};

class ShaderAttribute2f : public IShaderAttribute
{
public:
	explicit ShaderAttribute2f(const std::string& name) :
		IShaderAttribute(name)
	{}

	void render(ShaderObject& shader) override;

private:
	std::array<float, 2> value;
};



class ShaderAttribute3f : public IShaderAttribute
{
public:
	explicit ShaderAttribute3f(const std::string& name) :
		IShaderAttribute(name)
	{}

	void render(ShaderObject& shader) override;

private:
	std::array<float, 3> value;
};

class ShaderAttribute4f : public IShaderAttribute
{
public:
	explicit ShaderAttribute4f(const std::string& name) :
		IShaderAttribute(name)
	{}


	void render(ShaderObject& shader) override;

private:
	std::array<float,4> value;
};

class ShaderAttributeMatrix2d : public IShaderAttribute
{
public:
	explicit ShaderAttributeMatrix2d(const std::string& name) :
		IShaderAttribute(name)
	{
	}

	void render(ShaderObject& shader) override;

private:
	std::array<float, 4> value;
};

class ShaderAttributeMatrix3d : public IShaderAttribute
{
public:
	explicit ShaderAttributeMatrix3d(const std::string& name) :
		IShaderAttribute(name)
	{
	}

	void render(ShaderObject& shader) override;

private:
	std::array<float, 9> value;
};

class ShaderAttributeMatrix4d : public IShaderAttribute
{
public:
	explicit ShaderAttributeMatrix4d(const std::string& name) :
		IShaderAttribute(name)
	{
	}

	void render(ShaderObject& shader) override;

private:
	std::array<float, 16> value;
};


	}
}

#endif