#include "ShaderAttribute.h"

using namespace Crystal::Shader;

std::string ShaderAttribute::getTypeName() const
{
	return type.toString();
}