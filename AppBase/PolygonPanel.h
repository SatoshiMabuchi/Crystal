#pragma once

#include "IPanel.h"

namespace Crystal {
	namespace UI {

class PolygonPanel : public IPanel
{
public:
	PolygonPanel(IModel* model, ICanvas* canvas) :
		IPanel(model, canvas)
	{}

	void show() override;
};
	}
}