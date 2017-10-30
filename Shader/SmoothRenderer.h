#ifndef __CRYSTAL_SHADER_SMOOTH_RENDERER_H__
#define __CRYSTAL_SHADER_SMOOTH_RENDERER_H__

#include "../Graphics/ICamera.h"
#include "../Graphics/TriangleBuffer.h"
#include "../Graphics/PointLight.h"

#include "ShaderObject.h"

namespace Crystal {
	namespace Shader {

class SmoothRenderer
{
public:
	void findLocation();

	void render(const Graphics::ICamera& camera, const Graphics::TriangleBuffer& buffer, const Graphics::PointLight& light);

	bool build();

private:

	std::string getBuildinVertexShaderSource() const;

	std::string getBuildinFragmentShaderSource() const;

private:
	ShaderObject shader;
};

	}
}

#endif