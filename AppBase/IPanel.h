#pragma once

namespace Crystal {
	namespace UI {
		class IModel;
		class ICanvas;

class IPanel
{
public:
	IPanel(IModel* model, ICanvas* canvas) :
		model(model),
		canvas(canvas)
	{}

	virtual ~IPanel() {};

	virtual void show() = 0;

protected:
	IModel* model;
	ICanvas* canvas;
};

	}
}