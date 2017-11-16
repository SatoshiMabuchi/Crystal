#include "../AppBase/Window.h"
#include "../AppBase/FileMenu.h"
#include "../AppBase/CameraMenu.h"
#include "../AppBase/CtrlMenu.h"

#include "../AppBase/ParticlePanel.h"


#include "../UI/IModel.h"
#include "../UI/ICanvas.h"

#include "../UI/IRenderer.h"
#include "../Shader/PointRenderer.h"

using namespace Crystal::Math;
using namespace Crystal::Graphics;
using namespace Crystal::UI;

namespace Crystal {
	namespace UI {
		class Renderer : public IRenderer
		{
		public:
			explicit Renderer(Graphics::ICamera* camera) :
				camera(camera)
			{}

			bool build()
			{
				return pointRenderer.build();
			}

			void setViewModel(const ViewModel& vm) override {
				this->pointBuffer = vm.getPointBuffer();
			}

			void render(const int width, const int height) override
			{
				glClearColor(0.0, 0.0, 1.0, 0.0);
				glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
				pointRenderer.render(*camera, pointBuffer);
			}

		private:
			Shader::PointRenderer pointRenderer;
			Graphics::PointBuffer pointBuffer;
			Graphics::ICamera* camera;
		};
	}
}

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
	}

	window.add(new FileMenu(&model, &canvas));
	window.add(new CameraMenu(&model, &canvas));
	window.add(new CtrlMenu(&model, &canvas));

	window.add(new ParticlePanel(&model, &canvas));

	window.show();

	return 0;
}
