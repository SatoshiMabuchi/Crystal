#pragma once

namespace Crystal {
	namespace UI {

class ICommand
{
	virtual ~ICommand() {};

	virtual void execute() = 0;
};
	}
}