#include "ShaderUniform.h"
#include "ShaderObject.h"
#include <cassert>

using namespace Crystal::Shader;

void ShaderUniform1f::render(ShaderObject& shader)
{
	glUniform1f(shader.getUniformLocation(getName()), value);
}

void ShaderUniform2f::render(ShaderObject& shader)
{
	glUniform2fv(shader.getUniformLocation(getName()),1, value.data());
}

void ShaderUniform3f::render(ShaderObject& shader)
{
	glUniform3fv(shader.getUniformLocation(getName()), 1, value.data());
}

void ShaderUniform4f::render(ShaderObject& shader)
{
	glUniform4fv(shader.getUniformLocation(getName()), 1, value.data());
}

void ShaderUniform1i::render(ShaderObject& shader)
{
	glUniform1i(shader.getUniformLocation(getName()), value);
}

void ShaderUniform2i::render(ShaderObject& shader)
{
	glUniform2iv(shader.getUniformLocation(getName()), 1, value.data());
}

void ShaderUniform3i::render(ShaderObject& shader)
{
	glUniform3iv(shader.getUniformLocation(getName()), 1, value.data());
}

void ShaderUniform4i::render(ShaderObject& shader)
{
	glUniform4iv(shader.getUniformLocation(getName()), 1, value.data());
}

void ShaderUniform1b::render(ShaderObject& shader)
{
	glUniform1i(shader.getUniformLocation(getName()), value);
}

void ShaderUniform2b::render(ShaderObject& shader)
{
	glUniform2iv(shader.getUniformLocation(getName()), 1, value.data());
}

void ShaderUniform3b::render(ShaderObject& shader)
{
	glUniform3iv(shader.getUniformLocation(getName()), 1, value.data());
}

void ShaderUniform4b::render(ShaderObject& shader)
{
	glUniform4iv(shader.getUniformLocation(getName()), 1, value.data());
}

void ShaderUniformMatrix2d::render(ShaderObject& shader)
{
	glUniformMatrix2fv(shader.getUniformLocation(getName()), 1, GL_FALSE, value.data());
}

void ShaderUniformMatrix3d::render(ShaderObject& shader)
{
	glUniformMatrix3fv(shader.getUniformLocation(getName()), 1, GL_FALSE, value.data());
}

void ShaderUniformMatrix4d::render(ShaderObject& shader)
{
	glUniformMatrix4fv(shader.getUniformLocation(getName()), 1, GL_FALSE, value.data());
}

void ShaderUniformSampler2d::render(ShaderObject& shader)
{
	glUniform1i(shader.getUniformLocation(getName()), id);
}

void ShaderUniformCubeSampler::render(ShaderObject& shader)
{
	glUniform1i(shader.getUniformLocation(getName()), id);
}
