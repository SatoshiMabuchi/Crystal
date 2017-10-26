#include "CameraUICommand.h"

using namespace Crystal::Math;
using namespace Crystal::Graphics;
using namespace Crystal::UI;

CameraUICommand::CameraUICommand(ICamera<float>* camera) :
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

void CameraUICommand::onRightButtonDown(const Vector2d<float>& position)
{
	prevPosition = position;
}

void CameraUICommand::onRightButtonUp(const Vector2d<float>& position)
{

}
