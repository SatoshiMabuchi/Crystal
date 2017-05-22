#pragma once

#include <string>
#include "GL/glew.h"

namespace Crystal {
	namespace Shader {

class ShaderAttribute
{
public:
	std::string name;
	GLenum type;

	std::string getTypeName() const;
};

	}
}