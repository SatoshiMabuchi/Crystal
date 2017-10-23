#include "Window.h"

#include "GL/glew.h"

#include "GLFW\glfw3.h"
#include "GLFW\glfw3native.h"

#include "imgui.h"
#include "imgui_impl_glfw_gl3.h"
#include "../UI/ICanvas.h"

#include "../Graphics/PerspectiveCamera.h"
#include <chrono>

using namespace Crystal::Math;
using namespace Crystal::Graphics;
using namespace Crystal::UI;

namespace {
	ICanvas* canvas;
	std::chrono::time_point<std::chrono::system_clock> lastPressedTime;

	Vector2d<float> toScreenCoord(GLFWwindow* window, const double x, const double y) {
		int width,height;
		glfwGetWindowSize(window, &width, &height);
		const auto xx = x / (float)width;
		const auto yy = y / (float)height;
		return Vector2d<float>(xx, yy);
	}

	void onMouse(GLFWwindow *window, int button, int action, int mods) {
		double x, y;
		glfwGetCursorPos(window, &x, &y);
		const auto& coord = toScreenCoord(window, x, y);
		if (button == GLFW_MOUSE_BUTTON_LEFT) {
			auto now = std::chrono::system_clock::now();
			if (action == GLFW_PRESS) {
				canvas->onLeftButtonDown(coord);
			}
			else if (action == GLFW_RELEASE) {
				canvas->onLeftButtonUp(coord);
			}
		}
		else if (button == GLFW_MOUSE_BUTTON_RIGHT) {
			if (action == GLFW_PRESS) {
				canvas->onRightButtonDown(coord);
			}
			else if (action == GLFW_RELEASE) {
				canvas->onRightButtonUp(coord);
			}
		}
	}
}

Window::Window(IModel* model, ICanvas* canvas) :
	model(model),
	canvas(canvas)
{
	::canvas = canvas;
}

bool Window::init()
{
	if (!glfwInit()) {
		return false;
	}


	//glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	//glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	//glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	window = glfwCreateWindow(1280, 720, "ImGui OpenGL3 example", NULL, NULL);
	glfwMakeContextCurrent(window);
	//	gl3wInit();

	const auto e = glewInit();
	if (e != GLEW_OK) {
		return false;
	}


	// Setup ImGui binding
	ImGui_ImplGlfwGL3_Init(window, true);

	glfwSetMouseButtonCallback(window, onMouse);

	// Load Fonts
	// (there is a default font, this is only if you want to change it. see extra_fonts/README.txt for more details)
	//ImGuiIO& io = ImGui::GetIO();
	//io.Fonts->AddFontDefault();
	//io.Fonts->AddFontFromFileTTF("../../extra_fonts/Cousine-Regular.ttf", 15.0f);
	//io.Fonts->AddFontFromFileTTF("../../extra_fonts/DroidSans.ttf", 16.0f);
	//io.Fonts->AddFontFromFileTTF("../../extra_fonts/ProggyClean.ttf", 13.0f);
	//io.Fonts->AddFontFromFileTTF("../../extra_fonts/ProggyTiny.ttf", 10.0f);
	//io.Fonts->AddFontFromFileTTF("c:\\Windows\\Fonts\\ArialUni.ttf", 18.0f, NULL, io.Fonts->GetGlyphRangesJapanese());

	//canvas->addUICommand(new CameraUICtrl());
	canvas->build();


	return true;
}

void Window::show()
{
	while (!glfwWindowShouldClose(window)) {
		ImGui_ImplGlfwGL3_NewFrame();

		if (ImGui::BeginMainMenuBar()) {
			for (auto& m : menus) {
				m->show();
			}
			ImGui::EndMainMenuBar();
		}

		for (auto& p : panels) {
			p->show();
		}

		glClearColor(0,0,0,0);
		glClear(GL_COLOR_BUFFER_BIT);

		int width, height;
		glfwGetWindowSize(window, &width, &height);
		canvas->render(width, height);

		glFlush();

		ImGui::Render();
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	// Cleanup
	ImGui_ImplGlfwGL3_Shutdown();
	glfwTerminate();
}