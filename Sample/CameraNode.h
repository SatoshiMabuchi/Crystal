#ifndef __CRYSTAL_UI_CAMERA_NODE_H__
#define __CRYSTAL_UI_CAMERA_NODE_H__

#include "../Math/Matrix4d.h"
#include "../Graphics/PerspectiveCamera.h"

#include <string>
#include "imgui.h"
#include "INode.h"
#include "Matrix4dLink.h"
#include <vector>

namespace Crystal {
	namespace UI {
		class ShaderOutputSlot;

class CameraNode : public INode
{
public:
	CameraNode(const int id, const std::string& name, const ImVec2& pos);

	void show(ImDrawList* drawList, ImVec2 offset) override;

	//void build();

private:
	Matrix4dOutSlot projectionMatrixSlot;
	Matrix4dOutSlot modelviewMatrixSlot;
	Graphics::PerspectiveCamera<float> camera;
};

class ParticleNode : public INode
{
public:
	ParticleNode(const int id, const std::string& name, const ImVec2& pos);

	void show(ImDrawList* drawList, ImVec2 offset) override;

private:
	//Vector3dOutputSlot positionSlot;
};

	}
}

#endif
