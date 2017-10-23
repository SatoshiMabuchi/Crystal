#pragma once

#include "IMenu.h"

namespace Crystal {
	namespace UI {

		class CtrlMenu : public IMenu
		{
		public:
			CtrlMenu(IModel* model, ICanvas* canvas) :
				IMenu(model, canvas)
			{}

			virtual void show() override;
		};
	}
}