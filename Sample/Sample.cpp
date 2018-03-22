#include "../AppBase/Window.h"
#include "../AppBase/FileMenu.h"
#include "../AppBase/CameraMenu.h"
#include "../AppBase/CtrlMenu.h"

#include "../AppBase/ParticlePanel.h"
#include "../AppBase/WireFramePanel.h"
#include "../AppBase/PolygonPanel.h"

#include "../UI/IModel.h"
#include "../UI/ICanvas.h"
#include "Renderer.h"

using namespace Crystal::Math;
using namespace Crystal::Graphics;
using namespace Crystal::UI;


#include "../Graphics/PerspectiveCamera.h"

int main(int, char**)
{
	auto camera = new PerspectiveCamera(
		1.0,
		0.5f * Tolerance<float>::getPI(),
		Vector3df(0,0,0),
		Vector3df(0,0,-10.0),
		1.0f, 10.0f
		);

	Renderer *renderer = new Renderer(camera);

	IModel model;
	ICanvas canvas(renderer, camera);

	Window window(&model, &canvas);
	if (!window.init()) {
		assert(false);
		return 0;
	}

	window.add(new FileMenu(&model, &canvas));
	window.add(new CameraMenu(&model, &canvas));
	window.add(new CtrlMenu(&model, &canvas));

	window.add(new ParticlePanel(&model, &canvas));
	window.add(new WireFramePanel(&model, &canvas));
	window.add(new PolygonPanel(&model, &canvas));

	window.show();

	return 0;
}
