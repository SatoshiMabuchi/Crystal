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

	PerspectiveCamera<float> camera;
	//camera.init();
	camera.moveLookatTo(Crystal::Math::Vector3d<float>(0.0, 0.0, 2.0));
	camera.moveTo(Crystal::Math::Vector3d<float>(0.0, 0.0, -2.0));
	camera.setNear(1.0f);
	camera.setFar(100.0f);

	return true;
}

void Window::show()
{

	// Main loop
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
		/*
		// 1. Show a simple window
		// Tip: if we don't call ImGui::Begin()/ImGui::End() the widgets appears in a window automatically called "Debug"
		{
			static float f = 0.0f;
			ImGui::Text("Hello, world!");
			ImGui::SliderFloat("float", &f, 0.0f, 1.0f);
			ImGui::ColorEdit3("clear color", (float*)&clear_color);
			if (ImGui::Button("Test Window")) show_test_window ^= 1;
			if (ImGui::Button("Another Window")) show_another_window ^= 1;
			ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
		}

		// 2. Show another simple window, this time using an explicit Begin/End pair
		if (show_another_window)
		{
			ImGui::SetNextWindowSize(ImVec2(200, 100), ImGuiSetCond_FirstUseEver);
			ImGui::Begin("Another Window", &show_another_window);
			ImGui::Text("Hello");
			ImGui::End();
		}

		// 3. Show the ImGui test window. Most of the sample code is in ImGui::ShowTestWindow()
		if (show_test_window)
		{
			//	ImGui::SetNextWindowPos(ImVec2(650, 20), ImGuiSetCond_FirstUseEver);
			//	ImGui::ShowTestWindow(&show_test_window);
		}

		physicsPanel.show();
		shaderPanel.show();

		// Rendering
		//glClearColor(clear_color.x, clear_color.y, clear_color.z, clear_color.w);
		//glClear(GL_COLOR_BUFFER_BIT);

		//glCreateProgram();

		//SPHConstant constant(1000.0, 1.0, 0.0, 0.0, 0.125f);
		//Crystal::Physics::PhysicsObject object(box, 0.1f, constant);
		PointBuffer buffer;
		const auto& particles = physicsPanel.getParticles();
		for (auto p : particles) {
			buffer.add(p->getPosition(), ColorRGBA<float>(1, 0, 0, 0), 10.0f);
		}
		//buffer.add(Vector3d<float>(0, 0, 0), ColorRGBA<float>(1, 0, 0, 1), 10000.0f);

		int display_w, display_h;
		glfwGetFramebufferSize(window, &display_w, &display_h);
		glViewport(0, 0, display_w, display_h);
		glClearColor(0, 0, 0, 0);
		glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
		renderer.render(camera, buffer);
		//PointBuffer buffer;
		//PerspectiveCamera<float> camera;
		//camera.init();

		//renderer.render(camera,buffer);
		*/
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