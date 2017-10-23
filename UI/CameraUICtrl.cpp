#include "CameraUICtrl.h"

using namespace Crystal::Math;
using namespace Crystal::Graphics;
using namespace Crystal::UI;

CameraUICtrl::CameraUICtrl(ICamera<float>* camera) :
	camera(camera)
{
}

void CameraUICtrl::onLeftButtonDown(const Vector2d<float>& position)
{
	prevPosition = position;
	//camera->move();
}

void CameraUICtrl::onLeftButtonUp(const Vector2d<float>& position)
{

}

void CameraUICtrl::onRightButtonDown(const Vector2d<float>& position)
{
	prevPosition = position;
}

void CameraUICtrl::onRightButtonUp(const Vector2d<float>& position)
{

}
