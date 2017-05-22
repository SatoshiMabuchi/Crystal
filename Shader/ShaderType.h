#pragma once

#include "GL\glew.h"
#include <string>

namespace Crystal {
	namespace Shader {

class ShaderType
{
public:
	ShaderType() {}

	explicit ShaderType(const GLenum e);

	std::string toString() const;

private:
	GLenum e;
};

	}
}