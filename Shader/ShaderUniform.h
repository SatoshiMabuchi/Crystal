#pragma once

#include <string>
#include "GL/glew.h"

namespace Crystal {
	namespace Shader {

		class ShaderUniform
		{
		public:
			std::string name;
			GLenum type;

			std::string getTypeName() const;
		};

	}
}