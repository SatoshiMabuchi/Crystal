#include "ShaderUniform.h"
#include "ShaderObject.h"
#include <cassert>

using namespace Crystal::Shader;

void ShaderUniformMatrix4d::render(ShaderObject& shader)
{
	glUniformMatrix4fv(shader.getUniformLocation(getName()), 1, GL_FALSE, value.data());
	//glUniformMatrix4fv(shader.getUniformLocation("modelviewMatrix"), 1, GL_FALSE, modelviewMatrix.data());

}
