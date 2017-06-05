#ifndef __CRYSTAL_SHADER_RENDERER_H__
#define __CRYSTAL_SHADER_RENDERER_H__

#include "../Graphics/ICamera.h"
#include "../Graphics/PointBuffer.h"

#include "ShaderObject.h"

namespace Crystal {
	namespace Shader {

		class Renderer
		{
		public:

			void render(const Graphics::ICamera<float>& camera, const Graphics::PointBuffer& buffer, const std::vector<IShaderUniform*>& uniforms, const std::vector<IShaderAttribute*>& attributes);

			//void changeSize(const float size) { this->pointSize = size; }
		private:

		private:
			ShaderObject shader;
		};

	}
}

#endif