#include "GLFSEditor.h"

#include <imgui.h>
#include <string>
#include <fstream>
#include "../ThirdParty/nativefiledialog/src/include/nfd.h"
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
	if (ImGui::Button("Open")) {
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
	}
	if (ImGui::Button("Save")) {
		;
	}
	if (ImGui::Button("SaveAs")) {
		;
	}
	if (ImGui::Button("Compile")) {
		//if (ImGui::MenuItem("Close")) *p_open = false;
			shaderUnit.compile(txt, ShaderUnit::Stage::FRAGMENT);
			const auto& str = shaderUnit.getLog();
			int len = str.length();
			logText = new char[len + 1];
			memcpy(logText, str.c_str(), len + 1);
	}

	ImGui::InputTextMultiline("Source", txt, 1024);
	ImGui::InputTextMultiline("Log", logText, 1024);
}