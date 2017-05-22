#pragma once

#include <string>
#include "GL/glew.h"
#include "ShaderType.h"

namespace Crystal {
	namespace Shader {

		class ShaderUniform
		{
		public:
			std::string name;
			ShaderType type;

			std::string getTypeName() const;
		};

	}
}