#pragma once

#include "GL\glew.h"
#include <string>

namespace Crystal {
	namespace Shader {

class ShaderType
{
public:
	static std::string toString(const GLenum e);
};

	}
}