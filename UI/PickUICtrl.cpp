#include "PickUICtrl.h"

using namespace Crystal::Math;
using namespace Crystal::Graphics;
using namespace Crystal::UI;

PickUICtrl::PickUICtrl(ICamera* camera) :
	camera(camera)
{
}

void PickUICtrl::onLeftButtonDown(const Vector2df& position)
{
	prevPosition = position;
	//	camera->move();
}

void PickUICtrl::onLeftButtonUp(const Vector2df& position)
{

}

void PickUICtrl::onLeftDragging(const Vector2df& position)
{
	const auto diff = prevPosition - position;
	camera->move(glm::vec3(diff.x, diff.y, 0.0));
	this->prevPosition = position;
}

void PickUICtrl::onRightButtonDown(const Vector2df& position)
{
	prevPosition = position;
}

void PickUICtrl::onRightButtonUp(const Vector2df& position)
{

}

void PickUICtrl::onRightDragging(const Vector2df& position)
{
	const auto diff = prevPosition - position;
	camera->rotate(diff.y, diff.x);
	this->prevPosition = position;
}

void PickUICtrl::onWheel(const float dx)
{
	//camera->zoom(dx);
}
