#include "Window.h"

#include "GL/glew.h"

#include "GLFW\glfw3.h"
#include "GLFW\glfw3native.h"

#include "imgui.h"
#include "imgui_impl_glfw_gl3.h"

#include "../Graphics/PerspectiveCamera.h"

using namespace Crystal::Graphics;
using namespace Crystal::UI;

bool Window::init()
{
	if (!glfwInit()) {
		return false;
	}


	//glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	//glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	//glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#if __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
	window = glfwCreateWindow(1280, 720, "ImGui OpenGL3 example", NULL, NULL);
	glfwMakeContextCurrent(window);
	//	gl3wInit();

	const auto e = glewInit();
	if (e != GLEW_OK) {
		return 1;
	}


	// Setup ImGui binding
	ImGui_ImplGlfwGL3_Init(window, true);

	// Load Fonts
	// (there is a default font, this is only if you want to change it. see extra_fonts/README.txt for more details)
	//ImGuiIO& io = ImGui::GetIO();
	//io.Fonts->AddFontDefault();
	//io.Fonts->AddFontFromFileTTF("../../extra_fonts/Cousine-Regular.ttf", 15.0f);
	//io.Fonts->AddFontFromFileTTF("../../extra_fonts/DroidSans.ttf", 16.0f);
	//io.Fonts->AddFontFromFileTTF("../../extra_fonts/ProggyClean.ttf", 13.0f);
	//io.Fonts->AddFontFromFileTTF("../../extra_fonts/ProggyTiny.ttf", 10.0f);
	//io.Fonts->AddFontFromFileTTF("c:\\Windows\\Fonts\\ArialUni.ttf", 18.0f, NULL, io.Fonts->GetGlyphRangesJapanese());

	bool show_test_window = true;
	bool show_another_window = false;
	ImVec4 clear_color = ImColor(114, 144, 154);


	return true;
}

void Window::show()
{
	while (!glfwWindowShouldClose(window))
	{
		ImGui_ImplGlfwGL3_NewFrame();

		//ImGui::Begin("config 1", nullptr, ImGuiWindowFlags_MenuBar);

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

		glFlush();

		ImGui::Render();
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	// Cleanup
	ImGui_ImplGlfwGL3_Shutdown();
	glfwTerminate();
}