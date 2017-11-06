#include "CameraUICommand.h"

using namespace Crystal::Math;
using namespace Crystal::Graphics;
using namespace Crystal::UI;

CameraUICommand::CameraUICommand(ICamera* camera) :
	camera(camera)
{
}

void CameraUICommand::onLeftButtonDown(const Vector2df& position)
{
	prevPosition = position;
//	camera->move();
}

void CameraUICommand::onLeftButtonUp(const Vector2df& position)
{

}

void CameraUICommand::onLeftDragging(const Vector2df& position)
{
	const auto diff = prevPosition - position;
	camera->move( glm::vec3( diff.x, diff.y, 0.0) );
	this->prevPosition = position;
}

void CameraUICommand::onRightButtonDown(const Vector2df& position)
{
	prevPosition = position;
}

void CameraUICommand::onRightButtonUp(const Vector2df& position)
{

}

void CameraUICommand::onRightDragging(const Vector2df& position)
{
	const auto diff = prevPosition - position;
	camera->rotate(diff.y, diff.x);
	this->prevPosition = position;
}

void CameraUICommand::onWheel(const float dx)
{
	camera->zoom(dx / 100.0f);
}
