#ifndef __CRYSTAL_SHADER_DEPTH_RENDERER_H__
#define __CRYSTAL_SHADER_DEPTH_RENDERER_H__

//#include "IDRenderer.h"
#include "DepthTextureObject.h"
#include "ShaderObject.h"

namespace Crystal {
	namespace Shader {

		class DepthRenderer
		{
		public:
			void render(const DepthTextureObject& depthTexture);

			bool build();
		private:
			ShaderObject shader;

			std::string getBuiltinVertexShaderSource();

			std::string getBuiltinFragmentShaderSource();

			void findLocation();

		};
	}
}

#endif