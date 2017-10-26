#pragma once

#include "IPanel.h"

namespace Crystal {
	namespace UI {

class ParticlePanel : public IPanel
{
public:
	ParticlePanel(IModel* model, ICanvas* canvas) :
		IPanel(model, canvas)
	{}

	void show() override;
};

	}
}