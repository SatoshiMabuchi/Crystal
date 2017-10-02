#ifndef __CRYSTAL_UI_I_CANVAS_H__
#define __CRYSTAL_UI_I_CANVAS_H__

#include "../Math/Vector2d.h"

namespace Crystal {
	namespace UI {

class ICanvas
{
public:
	virtual void onLeftButtonDown(const Math::Vector2d<float>& position) = 0;

	virtual void onLeftButtonUp(const Math::Vector2d<float>& position) = 0;

	virtual void onRightButtonDown(const Math::Vector2d<float>& position) = 0;

	virtual void onRightButtonUp(const Math::Vector2d<float>& position) = 0;

	virtual void onMiddleButtonDown(const Math::Vector2d<float>& position) = 0;

	virtual void onMiddleButtonUp(const Math::Vector2d<float>& position) = 0;

	virtual void onLeftDragging(const Math::Vector2d<float>& position) = 0;

	virtual void onRightDragging(const Math::Vector2d<float>& position) = 0;

	virtual void onMiddleDragging(const Math::Vector2d<float>& position) = 0;
};
	}
}

#endif