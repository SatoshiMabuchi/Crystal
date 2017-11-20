#include "Renderer.h"
#include "../../Crystal/UI/ViewModel.h"

using namespace Crystal::UI;

bool Renderer::build()
{
	return pointRenderer.build();
}

void Renderer::setViewModel(const ViewModel& vm)
{
	this->pointRenderer.setBuffer(vm.getPointBuffer());
}

void Renderer::render(const int width, const int height)
{
	glClearColor(0.0, 0.0, 1.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	pointRenderer.render(*camera);
}