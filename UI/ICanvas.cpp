#include "ICanvas.h"
#include "../Graphics/PerspectiveCamera.h"
#include "IUICommand.h"
#include "CameraUICommand.h"
//#include "../ThirdParty/glm-0.9.8.5/glm/c"
#include "../Math/Box3d.h"

using namespace Crystal::Math;
using namespace Crystal::Graphics;
using namespace Crystal::Shader;
using namespace Crystal::UI;

void ICanvas::build()
{
	auto perspectiveCamera = new PerspectiveCamera(1.0f, 0.5f * Tolerance<float>::getPI());
	perspectiveCamera->setTarget(Vector3df(0, 0, 0));
	camera.reset(perspectiveCamera);
	camera->moveTo(glm::vec3(0.0, 0.0, -10.0));
	camera->setNear(1.0f);
	camera->setFar(10.0f);

	setUICommands(new CameraUICommand(getCamera()));

	pointRenderer.build();
}

void ICanvas::render(const int width, const int height)
{
	glClearColor(0.0, 0.0, 1.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	pointRenderer.render(*camera, viewModel.getPointBuffer());
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
	const auto& dist = glm::distance(boundingBox.getMin(), boundingBox.getMax());
	camera->setNear(dist * 0.1f);
	camera->setFar(dist * 10.0f);
	camera->setTarget(boundingBox.getCenter());
	camera->moveTo(boundingBox.getMin() - Vector3dd(0, 0, boundingBox.getLength().z));
	camera->setAngle(45.0f, 45.0f);

}

void ICanvas::setCameraXY(const Box3d& boundingBox)
{
	const auto& dist = glm::distance(boundingBox.getMin(), boundingBox.getMax());
	camera->setNear(dist * 0.1f);
	camera->setFar(dist * 10.0f);
	camera->setTarget(boundingBox.getCenter());
	camera->moveTo(Vector3df(0.0f, boundingBox.getMinY(), boundingBox.getMinZ()));
	camera->setAngle(0.0f, 0.0f);
}

void ICanvas::setCameraYZ(const Box3d& boundingBox)
{
	const auto& dist = glm::distance(boundingBox.getMin(), boundingBox.getMax());
	camera->setNear(dist * 0.1f);
	camera->setFar(dist * 10.0f);
	camera->setTarget(boundingBox.getCenter());
	camera->moveTo(Vector3df(0.0f, boundingBox.getMinY(), boundingBox.getMinZ()));
	camera->setAngle(90.0f, 0.0f);
}

void ICanvas::setCameraZX(const Box3d& boundingBox)
{
	const auto& dist = glm::distance(boundingBox.getMin(), boundingBox.getMax());
	camera->setNear(dist * 0.1f);
	camera->setFar(dist * 10.0f);
	camera->setTarget(boundingBox.getCenter());
	camera->moveTo(Vector3df(0.0f, boundingBox.getMinY(), boundingBox.getMinZ()));
	camera->setAngle(0.0f, 90.0f);
}
