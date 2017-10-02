#pragma once

#include "IMenu.h"

namespace Crystal {
	namespace UI {

class FileMenu : public IMenu
{
public:
	FileMenu(IModel* model, ICanvas* canvas) :
		IMenu(model, canvas)
	{}

	virtual void show() override;
};
	}
}