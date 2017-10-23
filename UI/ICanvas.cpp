#include "ICanvas.h"
#include "../Graphics/PerspectiveCamera.h"

using namespace Crystal::Graphics;
using namespace Crystal::Shader;
using namespace Crystal::UI;

void ICanvas::build()
{

	camera.reset(new PerspectiveCamera<float>());
	camera->moveLookatTo(Crystal::Math::Vector3d<float>(0.0, 0.0, 2.0));
	camera->moveTo(Crystal::Math::Vector3d<float>(0.0, 0.0, -2.0));
	camera->setNear(1.0f);
	camera->setFar(100.0f);

	pointRenderer.build();
}

void ICanvas::render(const int width, const int height)
{
	pointRenderer.render(*camera, pointBuffer);
}
