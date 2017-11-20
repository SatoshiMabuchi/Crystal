#pragma once

#include "../../Crystal/UI/IRenderer.h"
#include "../../Crystal/Graphics/ICamera.h"
#include "../../Crystal/Shader/PointRenderer.h"

namespace Crystal {
	namespace UI {
		class ViewModel;

class Renderer : public IRenderer
{
public:
	explicit Renderer(Graphics::ICamera* camera) :
		camera(camera)
	{}

	bool build();

	void setViewModel(const ViewModel& vm) override;

	void render(const int width, const int height) override;

private:
	Shader::PointRenderer pointRenderer;
	Graphics::ICamera* camera;
};
	}
}
