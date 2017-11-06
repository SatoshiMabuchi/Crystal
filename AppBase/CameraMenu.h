#pragma once

#include "IMenu.h"

namespace Crystal {
	namespace UI {

		class CameraMenu : public IMenu
		{
		public:
			CameraMenu(IModel* model, ICanvas* canvas) :
				IMenu(model, canvas)
			{}

			virtual void show() override;
		};
	}
}