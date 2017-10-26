#include "ICanvas.h"
#include "../Graphics/PerspectiveCamera.h"
#include "IUICommand.h"
#include "CameraUICommand.h"

using namespace Crystal::Math;
using namespace Crystal::Graphics;
using namespace Crystal::Shader;
using namespace Crystal::UI;

void ICanvas::build()
{
	camera.reset(new PerspectiveCamera());
	camera->moveLookatTo(glm::vec3(0.0, 0.0, 2.0));
	camera->moveTo(glm::vec3(0.0, 0.0, -2.0));
	camera->setNear(1.0f);
	camera->setFar(100.0f);

	CommandChain* chain = new CommandChain();
	chain->setOrigin(new CameraUICommand(getCamera()));
	setUICommands(chain);

	pointRenderer.build();
}

void ICanvas::render(const int width, const int height)
{
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