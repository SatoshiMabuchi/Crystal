#pragma once

#include "IPanel.h"

namespace Crystal {
	namespace UI {

class PolygonPanel : public IPanel
{
	PolygonPanel(IModel* model, ICanvas* canvas);

	void show() override;
};
	}
}