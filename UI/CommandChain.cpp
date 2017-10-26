#include "CommandChain.h"

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
