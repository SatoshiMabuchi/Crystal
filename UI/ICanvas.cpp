#include "ICanvas.h"
#include "../Graphics/PerspectiveCamera.h"
#include "IUICommand.h"
#include "CameraUICommand.h"
//#include "../ThirdParty/glm-0.9.8.5/glm/c"

using namespace Crystal::Math;
using namespace Crystal::Graphics;
using namespace Crystal::Shader;
using namespace Crystal::UI;

void ICanvas::build()
{
	auto perspectiveCamera = new PerspectiveCamera(1.0f, 0.5f * Tolerance<float>::getPI());
	camera.reset(perspectiveCamera);
	camera->moveTo(glm::vec3(0.0, 0.0, -10.0));
	camera->setNear(1.0f);
	camera->setFar(10.0f);

	CommandChain* chain = new CommandChain();
	chain->setOrigin(new CameraUICommand(getCamera()));
	setUICommands(chain);

	pointRenderer.build();
}

void ICanvas::render(const int width, const int height)
{
	glClearColor(0.0, 0.0, 1.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	pointRenderer.render(*camera, viewModel.getPointBuffer());
}

void ICanvas::onLeftButtonDown(const Vector2d<float>& position)
{
	commands->onLeftButtonDown(position);
}

void ICanvas::onLeftButtonUp(const Vector2d<float>& position)
{
	commands->onLeftButtonUp(position);
}

void ICanvas::onRightButtonDown(const Vector2d<float>& position)
{
	commands->onRightButtonDown(position);
}

void ICanvas::onRightButtonUp(const Vector2d<float>& position)
{
	commands->onRightButtonUp(position);
}

void ICanvas::onMiddleButtonDown(const Vector2d<float>& position)
{
	commands->onMiddleButtonDown(position);
}

void ICanvas::onMiddleButtonUp(const Vector2d<float>& position)
{
	commands->onMiddleButtonUp(position);
}

void ICanvas::onLeftDragging(const Vector2d<float>& position)
{
	commands->onLeftDragging(position);
}

void ICanvas::onRightDragging(const Vector2d<float>& position)
{
	commands->onRightDragging(position);
}

void ICanvas::onMiddleDragging(const Vector2d<float>& position)
{
	commands->onMiddleDragging(position);
}