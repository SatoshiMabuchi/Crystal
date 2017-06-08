#ifndef __CRYSTAL_UI_CAMERA_NODE_H__
#define __CRYSTAL_UI_CAMERA_NODE_H__

#include "../Math/Matrix4d.h"
#include "../Graphics/PerspectiveCamera.h"

#include <string>
#include "imgui.h"
#include "INode.h"
#include <vector>

namespace Crystal {
	namespace UI {
		class ShaderOutputSlot;

class Matrix4dInSlot : public IInSlot
{
public:
	void setValue(const std::array<double, 16>& value) { this->value = value; }

private:
	std::array<double, 16> value;
};

class Matrix4dOutSlot : public IOutSlot
{
public:
	~Matrix4dOutSlot()
	{}


	Math::Matrix4d<double> getValue() const { return value; }

private:
	Math::Matrix4d<double> value;
};

class ILink
{
public:
	virtual void build() = 0;
};

class Matrix4dLink : public ILink
{
private:
	void build() override {
		input->setValue( output->getValue().toArray() );
	}

	Matrix4dOutSlot* output;
	Matrix4dInSlot* input;
};


class CameraNode : public INode
{
public:
	CameraNode(const int id, const std::string& name, const ImVec2& pos);

	void show(ImDrawList* drawList, ImVec2 offset);

	//void build();

private:
	Matrix4dOutSlot projectionMatrixSlot;
	Matrix4dOutSlot modelviewMatrixSlot;
	Graphics::PerspectiveCamera<float> camera;
};

class ParticleNode
{

};

	}
}

#endif
