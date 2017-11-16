#ifndef __CRYSTAL_SHADER_POINT_RENDERER_H__
#define __CRYSTAL_SHADER_POINT_RENDERER_H__

#include "../Graphics/ICamera.h"
#include "../Graphics/PointBuffer.h"

#include "ShaderObject.h"
#include "IShader.h"

namespace Crystal {
	namespace Shader {

class PointRenderer : public IShader
{
public:
	void findLocation();

	void setBuffer(const Graphics::PointBuffer& buffer) { this->buffer = buffer; }

	void render(const Graphics::ICamera& camera) override;

	bool build() override;

private:
	std::string getBuildinVertexShaderSource() const;

	std::string getBuildinFragmentShaderSource() const;

private:
	ShaderObject shader;
	Graphics::PointBuffer buffer;
};

	}
}

#endif