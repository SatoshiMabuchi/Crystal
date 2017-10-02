#pragma once

namespace Crystal {
	namespace UI {
		class IModel;
		class ICanvas;

class IMenu
{
public:
	IMenu(IModel* model, ICanvas* canvas) :
		model(model),
		canvas(canvas)
	{}

	virtual ~IMenu() {};

	virtual void show() {};

protected:
	IModel* model;
	ICanvas* canvas;
};
	}
}