#pragma once

#include "IUICommand.h"
#include <deque>
#include <memory>

namespace Crystal {
	namespace UI {

class CommandChain : public IMouseListener
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

	void backward() { currentIter--; }

	virtual void onLeftButtonDown(const Math::Vector2df& position) override;

	virtual void onLeftButtonUp(const Math::Vector2df& position) override;

	virtual void onRightButtonDown(const Math::Vector2df& position) override;

	virtual void onRightButtonUp(const Math::Vector2df& position) override;

	virtual void onMiddleButtonDown(const Math::Vector2df& position) override;

	virtual void onMiddleButtonUp(const Math::Vector2df& position) override;

	virtual void onLeftDragging(const Math::Vector2df& position) override;

	virtual void onRightDragging(const Math::Vector2df& position) override;

	virtual void onMiddleDragging(const Math::Vector2df& position) override;

	virtual void onWheel(const float dx) override;

	void post();

private:
	std::deque<std::unique_ptr<IUICommand>> commands;
	std::deque<std::unique_ptr<IUICommand>>::iterator currentIter;
};
	}
}