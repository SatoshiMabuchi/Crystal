#include "PickUICommand.h"

using namespace Crystal::Math;
using namespace Crystal::Graphics;
using namespace Crystal::UI;

PickUICommand::PickUICommand(ICamera* camera) :
	camera(camera)
{
}

void PickUICommand::onLeftButtonDown(const Vector2df& position)
{
	prevPosition = position;
	//	camera->move();
}

void PickUICommand::onLeftButtonUp(const Vector2df& position)
{

}

void PickUICommand::onLeftDragging(const Vector2df& position)
{
	const auto diff = prevPosition - position;
	camera->move(glm::vec3(diff.x, diff.y, 0.0));
	this->prevPosition = position;
}

void PickUICommand::onRightButtonDown(const Vector2df& position)
{
	prevPosition = position;
}

void PickUICommand::onRightButtonUp(const Vector2df& position)
{

}

void PickUICommand::onRightDragging(const Vector2df& position)
{
	const auto diff = prevPosition - position;
	camera->rotate(diff.y, diff.x);
	this->prevPosition = position;
}

void PickUICommand::onWheel(const float dx)
{
	//camera->zoom(dx);
}
