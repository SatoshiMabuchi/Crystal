#include "ICanvas.h"
#include "../Graphics/PerspectiveCamera.h"
#include "CameraUICtrl.h"
#include "../Math/Box3d.h"
#include "IRenderer.h"

using namespace Crystal::Math;
using namespace Crystal::Graphics;
using namespace Crystal::UI;

ICanvas::ICanvas(IRenderer* renderer, ICamera* camera) :
	renderer(renderer),
	camera(camera)
{

}

void ICanvas::build()
{
	setUICtrl(new CameraUICtrl(getCamera()));
	renderer->build();
}

void ICanvas::render(const int width, const int height)
{
	renderer->render(width, height);
}

void ICanvas::onLeftButtonDown(const Vector2df& position)
{
	ctrl->onLeftButtonDown(position);
}

void ICanvas::onLeftButtonUp(const Vector2df& position)
{
	ctrl->onLeftButtonUp(position);
}

void ICanvas::onRightButtonDown(const Vector2df& position)
{
	ctrl->onRightButtonDown(position);
}

void ICanvas::onRightButtonUp(const Vector2df& position)
{
	ctrl->onRightButtonUp(position);
}

void ICanvas::onMiddleButtonDown(const Vector2df& position)
{
	ctrl->onMiddleButtonDown(position);
}

void ICanvas::onMiddleButtonUp(const Vector2df& position)
{
	ctrl->onMiddleButtonUp(position);
}

void ICanvas::onLeftDragging(const Vector2df& position)
{
	ctrl->onLeftDragging(position);
}

void ICanvas::onRightDragging(const Vector2df& position)
{
	ctrl->onRightDragging(position);
}

void ICanvas::onMiddleDragging(const Vector2df& position)
{
	ctrl->onMiddleDragging(position);
}

void ICanvas::onWheel(const float scale)
{
	ctrl->onWheel(scale);
}

void ICanvas::fitCamera(const Box3d& boundingBox)
{
	const auto& dist = static_cast<float>( glm::distance(boundingBox.getMin(), boundingBox.getMax()) );
	camera->setNear(dist * 0.1f);
	camera->setFar(dist * 10.0f);
	camera->setTarget(boundingBox.getCenter());
	camera->moveTo(boundingBox.getCenter() - dist * 0.5); //boundingBox.getMin() - Vector3dd(0, 0, boundingBox.getLength().z));
	camera->setAngle(45.0f, 45.0f);

}

void ICanvas::setCameraXY(const Box3d& boundingBox)
{
	fitCamera(boundingBox);
	camera->setAngle(0.0f, 0.0f);
}

void ICanvas::setCameraYZ(const Box3d& boundingBox)
{
	fitCamera(boundingBox);
	camera->setAngle(90.0f, 0.0f);
}

void ICanvas::setCameraZX(const Box3d& boundingBox)
{
	fitCamera(boundingBox);
	camera->setAngle(0.0f, 90.0f);
}
