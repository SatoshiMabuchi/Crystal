#include "PickUICommand.h"

using namespace Crystal::Math;
using namespace Crystal::Graphics;
using namespace Crystal::UI;

PickUICommand::PickUICommand(ICamera* camera) :
	camera(camera)
{
}

void PickUICommand::onLeftButtonDown(const Vector2d<float>& position)
{
	prevPosition = position;
	//	camera->move();
}

void PickUICommand::onLeftButtonUp(const Vector2d<float>& position)
{

}

void PickUICommand::onLeftDragging(const Vector2d<float>& position)
{
	const auto diff = prevPosition - position;
	camera->move(glm::vec3(diff.getX(), diff.getY(), 0.0));
	this->prevPosition = position;
}

void PickUICommand::onRightButtonDown(const Vector2d<float>& position)
{
	prevPosition = position;
}

void PickUICommand::onRightButtonUp(const Vector2d<float>& position)
{

}

void PickUICommand::onRightDragging(const Vector2d<float>& position)
{
	const auto diff = prevPosition - position;
	camera->rotate(diff.getY(), diff.getX());
	this->prevPosition = position;
}

void PickUICommand::onWheel(const float dx)
{
	//camera->zoom(dx);
}
