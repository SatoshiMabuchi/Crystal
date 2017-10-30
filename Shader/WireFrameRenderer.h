#ifndef __CRYSTAL_WIRE_FRAME_RENDERER_H__
#define __CRYSTAL_WIRE_FRAME_RENDERER_H__

#include "../Graphics/ICamera.h"
#include "../Graphics/LineBuffer.h"

#include "ShaderObject.h"

namespace Crystal {
	namespace Shader {

class WireFrameRenderer
{
public:
	void findLocation();

	void render(const Graphics::ICamera& camera, const Graphics::LineBuffer& buffer, const float width);

	//void changeSize(const float size) { this->pointSize = size; }
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