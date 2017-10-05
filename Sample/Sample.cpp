#include "../AppBase/Window.h"
#include "../AppBase/FileMenu.h"

#include "../UI/IModel.h"
#include "../UI/ICanvas.h"

using namespace Crystal::Math;
using namespace Crystal::UI;

int main(int, char**)
{
	IModel model;
	ICanvas canvas;

	Window window;
	if (!window.init()) {
		assert(false);
	}

	window.add(new FileMenu(&model, &canvas));

	window.show();

	return 0;
}
