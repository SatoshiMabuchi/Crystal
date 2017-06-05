#include "ShaderAttribute.h"
#include "ShaderObject.h"

using namespace Crystal::Shader;

std::string IShaderAttribute::getTypeName() const
{
	return type.toString();
}

void ShaderAttribute1f::render(ShaderObject& shader)
{
	glVertexAttribPointer(shader.getAttribLocation(getName()), 1, GL_FLOAT, GL_FALSE, 0, &value);
}

void ShaderAttribute2f::render(ShaderObject& shader)
{
	glVertexAttribPointer(shader.getAttribLocation(getName()), 2, GL_FLOAT, GL_FALSE, 0, &value);
}

void ShaderAttribute3f::render(ShaderObject& shader)
{
	glVertexAttribPointer(shader.getAttribLocation(getName()), 3, GL_FLOAT, GL_FALSE, 0, value.data());
}

void ShaderAttribute4f::render(ShaderObject& shader)
{
	glVertexAttribPointer(shader.getAttribLocation(getName()), 4, GL_FLOAT, GL_FALSE, 0, value.data());
}

void ShaderAttributeMatrix2d::render(ShaderObject& shader)
{
	glVertexAttribPointer(shader.getAttribLocation(getName()), 4, GL_FLOAT, GL_FALSE, 0, value.data());
}

void ShaderAttributeMatrix3d::render(ShaderObject& shader)
{
	glVertexAttribPointer(shader.getAttribLocation(getName()), 9, GL_FLOAT, GL_FALSE, 0, value.data());
}

void ShaderAttributeMatrix4d::render(ShaderObject& shader)
{
	glVertexAttribPointer(shader.getAttribLocation(getName()), 16, GL_FLOAT, GL_FALSE, 0, value.data());
}