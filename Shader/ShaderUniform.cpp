#include "ShaderUniform.h"
#include "ShaderObject.h"
#include <cassert>

using namespace Crystal::Shader;

std::string ShaderUniform::getTypeName() const
{
	return type.toString();
}

ShaderType ShaderUniformMatrix4d::getType() const
{
	return ShaderType(GL_FLOAT_MAT4);
}

std::string ShaderUniformMatrix4d::getTypeName() const
{
	return getType().toString();
}

void ShaderUniformMatrix4d::render(ShaderObject& shader)
{
	glUniformMatrix4fv(shader.getUniformLocation(getName()), 1, GL_FALSE, value.data());
	//glUniformMatrix4fv(shader.getUniformLocation("modelviewMatrix"), 1, GL_FALSE, modelviewMatrix.data());

}
