#ifndef __CRYSTAL_SHADER_SHADER_ATTRIBUTE_H__
#define __CRYSTAL_SHADER_SHADER_ATTRIBUTE_H__

#include <string>
#include "GL/glew.h"
#include "ShaderType.h"

namespace Crystal {
	namespace Shader {

class ShaderAttribute
{
public:
	std::string name;
	ShaderType type;

	std::string getTypeName() const;
};

	}
}

#endif