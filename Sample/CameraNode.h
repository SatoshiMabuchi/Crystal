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


class IInSlot
{
public:
	virtual ~IInSlot() {}
	virtual void show(const ImVec2& pos, ImDrawList* drawList);
};

class Matrix4dInSlot : public IInSlot
{
public:
	void setValue(const std::array<double, 16>& value) { this->value = value; }

private:
	std::array<double, 16> value;
};


class IOutSlot
{
public:
	virtual ~IOutSlot() {}

	virtual void show(const ImVec2& pos, ImDrawList* drawList);
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

class INode
{
public:
	INode(const int id, const std::string& name, const ImVec2& pos) :
		id(id),
		name(name),
		position(pos)
	{}

	virtual ~INode() {}

	const int getId() const { return id; }

	const std::string getName() const { return name; }

	const ImVec2 getPosition() const { return position; }

private:
	const int id;
	const std::string name;
	const ImVec2 position;

	std::vector<IInSlot*> inputs;
	std::vector<IOutSlot*> outputs;
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
