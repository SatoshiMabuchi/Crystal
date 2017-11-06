#include "CommandChain.h"

using namespace Crystal::Math;
using namespace Crystal::UI;

CommandChain::CommandChain()
{
	currentIter = commands.begin();
}

bool CommandChain::isFirst() const
{
	return currentIter == commands.begin();
}

bool CommandChain::isLast() const
{
	return currentIter == commands.end();
}

bool CommandChain::isEmpty() const
{
	return commands.empty();
}

void CommandChain::clear()
{
	commands.clear();
	currentIter = commands.begin();
}

void CommandChain::setOrigin(IUICommand* command)
{
	this->commands.push_front( std::unique_ptr<IUICommand>(command) );
	currentIter = commands.begin();
}

void CommandChain::add(IUICommand* command)
{
	this->commands.push_back(std::unique_ptr<IUICommand>(command));
}

IUICommand* CommandChain::getCurrentCommand()
{
	return currentIter->get();
}

void CommandChain::onLeftButtonDown(const Vector2df& position)
{
	getCurrentCommand()->onLeftButtonDown(position);
	post();
}

void CommandChain::onLeftButtonUp(const Vector2df& position)
{
	getCurrentCommand()->onLeftButtonUp(position);
	post();
}

void CommandChain::onRightButtonDown(const Vector2df& position)
{
	getCurrentCommand()->onRightButtonDown(position);
	post();
}

void CommandChain::onRightButtonUp(const Vector2df& position)
{
	getCurrentCommand()->onRightButtonUp(position);
	post();
}

void CommandChain::onMiddleButtonDown(const Vector2df& position)
{
	getCurrentCommand()->onMiddleButtonDown(position);
	post();
}

void CommandChain::onMiddleButtonUp(const Vector2df& position)
{
	getCurrentCommand()->onMiddleButtonDown(position);
	post();
}

void CommandChain::onLeftDragging(const Vector2df& position)
{
	getCurrentCommand()->onLeftDragging(position);
	post();
}

void CommandChain::onRightDragging(const Vector2df& position)
{
	getCurrentCommand()->onRightDragging(position);
	post();
}

void CommandChain::onMiddleDragging(const Vector2df& position)
{
	getCurrentCommand()->onMiddleDragging(position);
	post();
}

void CommandChain::onWheel(const float dx)
{
	getCurrentCommand()->onWheel(dx);
	post();
}


void CommandChain::post()
{
	if (getCurrentCommand()->isCompleted()) {
		forward();
	}
}