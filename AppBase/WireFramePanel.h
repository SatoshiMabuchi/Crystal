#pragma once

#include "IPanel.h"

namespace Crystal {
	namespace UI {

		class WireFramePanel : public IPanel
		{
		public:
			WireFramePanel(IModel* model, ICanvas* canvas) :
				IPanel(model, canvas)
			{}

			void show() override;
		};

	}
}