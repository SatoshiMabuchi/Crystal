#pragma once

#include "imgui.h"
#include <string>
#include <vector>

namespace Crystal {
	namespace UI {
		class CameraNode;
		class ShaderNode;

class Model
{
public:
	bool save(const std::string& filename) const;

	bool load(const std::string& filename);

	void draw(ImDrawList* draw_list, ImVec2 offset);

	void build();

private:
	CameraNode* cameraNode;
	std::vector<ShaderNode*> nodes;

};
	}
}