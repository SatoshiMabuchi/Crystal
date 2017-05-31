#pragma once

#include <string>
#include "../Shader/ShaderObject.h"

namespace Crystal {
	namespace UI {

class GLFSEditor
{
public:
	GLFSEditor()
	{
		txt = "";
		logText = "";
	}

	GLFSEditor(const std::string& str)
	{
		setSource(str);
	}

	void setSource(const std::string& str) {
		int len = str.length();
		txt = new char[len + 1];
		memcpy(txt, str.c_str(), len + 1);
	}

	void show();

	char* getSource();

private:
	char* txt;
	char* logText;
	Shader::ShaderUnit shaderUnit;
};
	}
}