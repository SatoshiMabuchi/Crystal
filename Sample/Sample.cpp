#include "../AppBase/Window.h"
#include "../AppBase/FileMenu.h"
#include "../AppBase/CtrlMenu.h"

#include "../UI/IModel.h"
#include "../UI/ICanvas.h"

using namespace Crystal::Math;
using namespace Crystal::UI;

int main(int, char**)
{
	IModel model;
	ICanvas canvas;

	Window window(&model, &canvas);
	if (!window.init()) {
		assert(false);
	}

	window.add(new FileMenu(&model, &canvas));
	window.add(new CtrlMenu(&model, &canvas));

	window.show();

	return 0;
}
