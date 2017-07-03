#ifndef __CRYSTAL_UI_SHADER_DESIGNE_PANEL_H__
#define __CRYSTAL_UI_SHADER_DESIGNE_PANEL_H__

#include "imgui.h"
#include <string>
#include <vector>
#include "ShaderNode.h"
#include "GLVSEditor.h"
#include "Model.h"

namespace Crystal {
	namespace UI {
		class CameraNode;

class ShaderDesignPanel
{
public:
	void show();

private:
	bool inited = false;
	ImVec2 scrolling = ImVec2(0.0f, 0.0f);
	bool show_grid = true;
	ShaderNode* selectedNode;
	Model model;
};
	}
}

#endif
