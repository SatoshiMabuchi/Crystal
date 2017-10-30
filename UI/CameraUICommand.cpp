#include "CameraUICommand.h"

using namespace Crystal::Math;
using namespace Crystal::Graphics;
using namespace Crystal::UI;

CameraUICommand::CameraUICommand(ICamera* camera) :
	camera(camera)
{
}

void CameraUICommand::onLeftButtonDown(const Vector2d<float>& position)
{
	prevPosition = position;
//	camera->move();
}

void CameraUICommand::onLeftButtonUp(const Vector2d<float>& position)
{

}

void CameraUICommand::onLeftDragging(const Vector2d<float>& position)
{
	const auto diff = prevPosition - position;
	camera->move( glm::vec3( diff.getX(), diff.getY(), 0.0) );
	this->prevPosition = position;
}

void CameraUICommand::onRightButtonDown(const Vector2d<float>& position)
{
	prevPosition = position;
}

void CameraUICommand::onRightButtonUp(const Vector2d<float>& position)
{

}

void CameraUICommand::onRightDragging(const Vector2d<float>& position)
{
	const auto diff = prevPosition - position;
	camera->rotate(diff.getY(), diff.getX());
	this->prevPosition = position;
}

void CameraUICommand::onWheel(const float dx)
{
	//camera->zoom(dx);
}
