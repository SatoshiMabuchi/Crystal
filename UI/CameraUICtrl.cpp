#include "CameraUICtrl.h"

using namespace Crystal::Math;
using namespace Crystal::Graphics;
using namespace Crystal::UI;

CameraUICtrl::CameraUICtrl(ICamera* camera) :
	camera(camera)
{
}

void CameraUICtrl::onLeftButtonDown(const Vector2df& position)
{
	prevPosition = position;
//	camera->move();
}

void CameraUICtrl::onLeftButtonUp(const Vector2df& position)
{

}

void CameraUICtrl::onLeftDragging(const Vector2df& position)
{
	const auto diff = prevPosition - position;
	camera->move( glm::vec3( diff.x, diff.y, 0.0) );
	this->prevPosition = position;
}

void CameraUICtrl::onRightButtonDown(const Vector2df& position)
{
	prevPosition = position;
}

void CameraUICtrl::onRightButtonUp(const Vector2df& position)
{

}

void CameraUICtrl::onRightDragging(const Vector2df& position)
{
	const auto diff = prevPosition - position;
	camera->rotate(diff.y, diff.x);
	this->prevPosition = position;
}

void CameraUICtrl::onWheel(const float dx)
{
	camera->zoom(dx / 100.0f);
}
