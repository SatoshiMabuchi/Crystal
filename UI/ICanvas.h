#ifndef __CRYSTAL_UI_I_CANVAS_H__
#define __CRYSTAL_UI_I_CANVAS_H__

#include "../Math/Vector2d.h"
#include "IUICommand.h"

namespace Crystal {
	namespace UI {
		class IUICtrl;
		class IModel;


class ICanvas
{
public:
	void setUICtrl(IUICommand* ctrl) { this->ctrl = ctrl; }


	//void update(IModel* model);

private:
	IUICommand* ctrl;
};
	}
}

#endif