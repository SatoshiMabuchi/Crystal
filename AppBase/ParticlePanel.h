#pragma once

#include "IPanel.h"

namespace Crystal {
	namespace UI {

class ParticlePanel : public IPanel
{
	ParticlePanel(IModel* model, ICanvas* canvas);

	void show() override;
};

	}
}