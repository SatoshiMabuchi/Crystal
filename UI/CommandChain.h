#pragma once

#include "IUICommand.h"
#include <deque>
#include <memory>

namespace Crystal {
	namespace UI {

class CommandChain
{
public:
	CommandChain();

	bool isFirst() const;

	bool isLast() const;

	bool isEmpty() const;

	void clear();

	void setOrigin(IUICommand* command);

	void add(IUICommand* command);

	IUICommand* getCurrentCommand();

	void forward() { currentIter++; }

private:
	std::deque<std::unique_ptr<IUICommand>> commands;
	std::deque<std::unique_ptr<IUICommand>>::iterator currentIter;
};
	}
}