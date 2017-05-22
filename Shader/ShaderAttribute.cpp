#include "ShaderAttribute.h"
#include "ShaderType.h"

using namespace Crystal::Shader;

std::string ShaderAttribute::getTypeName() const
{
	return ShaderType::toString(type);
}