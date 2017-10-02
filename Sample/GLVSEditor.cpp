#include "GLVSEditor.h"

#include <imgui.h>
#include <string>
#include <fstream>
#include <sstream>
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


void GLVSEditor::show()
{
	ImGui::BeginGroup(); // Lock horizontal position
	if (ImGui::Button("Open")) {
		char const * lFilterPatterns[2] = { "*.txt", "*.glvs" };
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
		shaderUnit.compile(txt, ShaderUnit::Stage::VERTEX);
		const auto& str = shaderUnit.getLog();
		int len = str.length();
		logText = new char[len + 1];
		memcpy(logText, str.c_str(), len + 1);
	}
	ImGui::EndGroup();

	ImGui::InputTextMultiline("Source", txt, 1024);
	ImGui::InputTextMultiline("Log", logText, 1024);
	//ImGui::End();
}