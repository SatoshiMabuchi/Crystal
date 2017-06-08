#ifndef __CRYSTAL_UI_CAMERA_NODE_H__
#define __CRYSTAL_UI_CAMERA_NODE_H__

#include "../Math/Matrix4d.h"
#include "../Graphics/PerspectiveCamera.h"

#include <string>
#include "imgui.h"
#include <vector>

namespace Crystal {
	namespace UI {
		class ShaderOutputSlot;

class Matrix4dSlot
{
public:

	void show(const ImVec2& pos,ImDrawList* drawList);

private:
	Math::Matrix4d<float> value;
};

class CameraNode
{
public:
	CameraNode(const int id, const std::string& name, const ImVec2& pos);

	void show(ImDrawList* drawList, ImVec2 offset);

private:
	const int id;
	const std::string name;
	const ImVec2 pos;
	//std::vector<ShaderOutputSlot*> outputSlots;
	Matrix4dSlot projectionMatrixSlot;
	Matrix4dSlot modelviewMatrixSlot;
//	Matrix4dSlot 
	Graphics::PerspectiveCamera<float> camera;
};

class ParticleNode
{

};

	}
}

#endif
