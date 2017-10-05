#include <stdio.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <GL/GL.h>

#include "../Graphics/PerspectiveCamera.h"
#include "../Shader/PointRenderer.h"
#include "ShaderDesignPanel.h"
#include "GLVSEditor.h"
#include "GLFSEditor.h"
#include "../AppBase/FileMenu.h"

#include "../AppBase/Window.h"

#include "../UI/IModel.h"
#include "../UI/ICanvas.h"

//#pragma comment(lib, "glew32.lib")

using namespace Crystal::Math;
using namespace Crystal::Graphics;
using namespace Crystal::Shader;
using namespace Crystal::UI;

static void error_callback(int error, const char* description)
{
	fprintf(stderr, "Error %d: %s\n", error, description);
}

int main(int, char**)
{
	// Setup window
	glfwSetErrorCallback(error_callback);

	IModel model;
	ICanvas canvas;

	Window window;
	if (!window.init()) {
		assert(false);
	}

	window.add(new FileMenu(&model, &canvas));

	window.add(new PhysicsPanel(&model, &canvas));
	window.add(new ShaderDesignPanel(&model, &canvas));

	//PointRenderer renderer;
	//renderer.build();

	window.show();


	return 0;
}
