#ifndef __CRYSTAL_UI_I_CANVAS_H__
#define __CRYSTAL_UI_I_CANVAS_H__

#include "../Math/Vector2d.h"
#include "IUICtrl.h"

namespace Crystal {
	namespace UI {
		class IUICtrl;

class ICanvas
{
public:
	void setUICtrl(IUICtrl* ctrl) { this->ctrl = ctrl; }

	virtual void onLeftButtonDown(const Math::Vector2d<float>& position) {
		ctrl->onLeftButtonDown(position);
	}

	virtual void onLeftButtonUp(const Math::Vector2d<float>& position) {
		ctrl->onLeftButtonUp(position);
	}

	virtual void onRightButtonDown(const Math::Vector2d<float>& position) {
		ctrl->onRightButtonDown(position);
	}

	virtual void onRightButtonUp(const Math::Vector2d<float>& position) {
		ctrl->onRightButtonUp(position);
	}

	virtual void onMiddleButtonDown(const Math::Vector2d<float>& position) {
		ctrl->onMiddleButtonDown(position);
	}

	virtual void onMiddleButtonUp(const Math::Vector2d<float>& position) {
		ctrl->onMiddleButtonUp(position);
	}

	virtual void onLeftDragging(const Math::Vector2d<float>& position) {
		ctrl->onLeftDragging(position);
	}

	virtual void onRightDragging(const Math::Vector2d<float>& position) {
		ctrl->onRightDragging(position);
	}

	virtual void onMiddleDragging(const Math::Vector2d<float>& position) {
		ctrl->onMiddleDragging(position);
	}

private:
	IUICtrl* ctrl;
};
	}
}

#endif