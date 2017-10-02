#include "GLFSEditor.h"

#include "../AppBase/imgui.h"
#include <string>
#include <fstream>
//#include "../ThirdParty/nativefiledialog/src/include/nfd.h"
#include "../AppBase/tinyfiledialogs.h"
#include "../Shader/ShaderObject.h"

using namespace Crystal::Shader;
using namespace Crystal::UI;

namespace {
	std::string getStrFromFile(const std::string& file)
	{
		std::ifstream stream(file);
		if (stream.fail()) {
			assert(false);
			return "";
		}
		std::istreambuf_iterator<char> it(stream);
		std::istreambuf_iterator<char> last;
		return std::string(it, last);
	}
}


void GLFSEditor::show()
{
	ImGui::BeginGroup();
	if (ImGui::Button("Open")) {
		/*
		nfdchar_t *outPath = NULL;
		std::string filter = "glfs";
		nfdresult_t result = NFD_OpenDialog(filter.data(), NULL, &outPath);

		if (result == NFD_OKAY) {
			setSource(getStrFromFile(outPath));
			puts("Success!");
			puts(outPath);
			free(outPath);
		}
		else if (result == NFD_CANCEL) {
			puts("User pressed cancel.");
		}
		else {
			printf("Error: %s\n", NFD_GetError());
		}
		*/
		char const * lFilterPatterns[2] = { "*.txt", "*.glfs" };
		const auto filename = tinyfd_openFileDialog("Open", "", 2, lFilterPatterns, nullptr, 0);
		if (!filename) {
			setSource(getStrFromFile(filename));
		}
	}
	if (ImGui::Button("Save")) {
		;
	}
	if (ImGui::Button("SaveAs")) {
		;
	}
	if (ImGui::Button("Compile")) {
		shaderUnit.compile(txt, ShaderUnit::Stage::FRAGMENT);
		const auto& str = shaderUnit.getLog();
		auto len = str.length();
		logText = new char[len + 1];
		memcpy(logText, str.c_str(), len + 1);
	}
	ImGui::EndGroup();

	ImGui::InputTextMultiline("Source", txt, 1024);
	ImGui::InputTextMultiline("Log", logText, 1024);
}

char* GLFSEditor::getSource()
{
	return txt;
}