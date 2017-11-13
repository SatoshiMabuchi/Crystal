#pragma once
#include "IMouseListener.h"

namespace Crystal {
	namespace UI {

class IUICommand : public IMouseListener
{
public:
	IUICommand() {}

	explicit IUICommand(const std::string& name) :
		name(name)
	{}
//	virtual ~IUICommand();

	virtual bool isCompleted() const = 0;

	std::string getName() const { return name; }

private:
	std::string name;
};
	}
}