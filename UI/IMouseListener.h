#pragma once

#include "../Math/Vector2d.h"

namespace Crystal {
	namespace UI {

class IMouseListener
{
	virtual void onLeftButtonDown(const Math::Vector2d<float>& position) {};

	virtual void onLeftButtonUp(const Math::Vector2d<float>& position) {};

	virtual void onRightButtonDown(const Math::Vector2d<float>& position) {};

	virtual void onRightButtonUp(const Math::Vector2d<float>& position) {};

	virtual void onMiddleButtonDown(const Math::Vector2d<float>& position) {};

	virtual void onMiddleButtonUp(const Math::Vector2d<float>& position) {};

	virtual void onLeftDragging(const Math::Vector2d<float>& position) {};

	virtual void onRightDragging(const Math::Vector2d<float>& position) {};

	virtual void onMiddleDragging(const Math::Vector2d<float>& position) {}
};

	}
}