#ifndef __CRYSTAL_SHADER_SMOOTH_RENDERER_H__
#define __CRYSTAL_SHADER_SMOOTH_RENDERER_H__

#include "../Graphics/ICamera.h"
#include "../Graphics/TriangleBuffer.h"
#include "../Graphics/PointLight.h"

#include "ShaderObject.h"
#include "TextureObject.h"

namespace Crystal {
	namespace Shader {

class SmoothRenderer
{
public:
	void findLocation();

	void setBuffer(const Graphics::TriangleBuffer& buffer) { this->buffer = buffer; }

	void render(const Graphics::ICamera& camera, const Graphics::PointLight& light, const TextureObject& texture);

	bool build();

private:

	std::string getBuildinVertexShaderSource() const;

	std::string getBuildinFragmentShaderSource() const;

private:
	ShaderObject shader;
	Graphics::TriangleBuffer buffer;
};

	}
}

#endif