#ifndef __CRYSTAL_UI_CAMERA_NODE_H__
#define __CRYSTAL_UI_CAMERA_NODE_H__

#include <string>
#include "imgui.h"
#include <vector>

namespace Crystal {
	namespace UI {
		class ShaderOutputSlot;

class CameraNode
{
public:
	CameraNode(const int id, const std::string& name, const ImVec2& pos);

	void show();

private:
	const int id;
	const std::string name;
	const ImVec2& pos;
	std::vector<ShaderOutputSlot*> outputSlots;
};
	}
}

#endif
