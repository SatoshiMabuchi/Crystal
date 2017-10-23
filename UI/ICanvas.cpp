#include "ICanvas.h"
#include "../Graphics/PerspectiveCamera.h"
#include "IUICommand.h"

using namespace Crystal::Math;
using namespace Crystal::Graphics;
using namespace Crystal::Shader;
using namespace Crystal::UI;

void ICanvas::build()
{
	camera.reset(new PerspectiveCamera<float>());
	camera->moveLookatTo(Crystal::Math::Vector3d<float>(0.0, 0.0, 2.0));
	camera->moveTo(Crystal::Math::Vector3d<float>(0.0, 0.0, -2.0));
	camera->setNear(1.0f);
	camera->setFar(100.0f);

	pointRenderer.build();
}

void ICanvas::render(const int width, const int height)
{
	pointRenderer.render(*camera, pointBuffer);
}

void ICanvas::onLeftButtonDown(const Vector2d<float>& position)
{
	for (auto& c : ctrls) {
		c->onLeftButtonDown(position);
	}
}

void ICanvas::onLeftButtonUp(const Vector2d<float>& position)
{
	for (auto& c : ctrls) {
		c->onLeftButtonUp(position);
	}
}

void ICanvas::onRightButtonDown(const Vector2d<float>& position)
{
	for (auto& c : ctrls) {
		c->onRightButtonDown(position);
	}
}

void ICanvas::onRightButtonUp(const Vector2d<float>& position)
{
	for (auto& c : ctrls) {
		c->onRightButtonUp(position);
	}
}

void ICanvas::onMiddleButtonDown(const Vector2d<float>& position)
{
	for (auto& c : ctrls) {
		c->onMiddleButtonDown(position);
	}
}

void ICanvas::onMiddleButtonUp(const Vector2d<float>& position)
{
	for (auto& c : ctrls) {
		c->onMiddleButtonUp(position);
	}
}

void ICanvas::onLeftDragging(const Vector2d<float>& position)
{
	for (auto& c : ctrls) {
		c->onLeftDragging(position);
	}
}

void ICanvas::onRightDragging(const Vector2d<float>& position)
{
	for (auto& c : ctrls) {
		c->onRightDragging(position);
	}
}

void ICanvas::onMiddleDragging(const Vector2d<float>& position)
{
	for (auto& c : ctrls) {
		c->onMiddleDragging(position);
	}
}