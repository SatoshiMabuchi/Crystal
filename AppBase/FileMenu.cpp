#include "FileMenu.h"
#include "imgui.h"
#include "tinyfiledialogs.h"
#include "../UI/IModel.h"

using namespace Crystal::UI;

void FileMenu::show()
{
	if (ImGui::BeginMenu("File")) {
		if (ImGui::MenuItem("Open")) {
			char const * lFilterPatterns[2] = { "*.stl", "*.obj" };
			const auto filename = tinyfd_openFileDialog("Open", "", 2, lFilterPatterns, nullptr, 0);
			model->read(filename);
		}
		if (ImGui::MenuItem("Save")) {
			char const * lFilterPatterns[2] = { "*.stl", "*.obj" };
			//const auto filename = tinyfd_saveFileDialog("Save", "", 2, lFilterPatterns, nullptr, 0);
			//model->write(filename);
		}

		ImGui::EndMenu();
	}
	//ImGui::EndMenuBar();

}
