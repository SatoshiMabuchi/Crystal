#pragma once

namespace Crystal {
	namespace UI {

class ICommand
{
public:
	virtual ~ICommand() {};

	virtual void execute() = 0;

};
	}
}