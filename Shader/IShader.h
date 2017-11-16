#pragma once

#include "../Graphics/ICamera.h"

namespace Crystal {
	namespace Shader {

		class IShader
		{
		public:
			virtual ~IShader() {}

			virtual void render(const Graphics::ICamera& camera) = 0;

			virtual bool build() = 0;
		};

	}
}
