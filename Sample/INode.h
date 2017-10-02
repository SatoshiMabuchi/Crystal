#pragma once

#include <vector>
#include <string>
#include "../AppBase/imgui.h"
#include "../Util/UnCopyable.h"

namespace Crystal {
	namespace UI {
		class INode;

class IInSlot// : private UnCopyable
{
public:
	IInSlot(INode* parent) :
		parent(parent)
	{}

	ImVec2 getPosition() const;

	virtual ~IInSlot() {}

	virtual void show(const ImVec2& pos, ImDrawList* drawList);


private:
	INode* parent;
};

class IOutSlot// : private UnCopyable
{
public:
	IOutSlot(INode* parent) :
		parent(parent)
	{}

	virtual ~IOutSlot() {}

	virtual void show(const ImVec2& pos, ImDrawList* drawList);

	ImVec2 getPosition() const;

private:
	INode* parent;
};

class INode //: private UnCopyable
{
public:
	INode(const int id, const std::string& name, const ImVec2& pos) :
		id(id),
		name(name),
		position(pos)
	{}

	virtual ~INode() {}

	const int getId() const { return id; }

	void setName(const std::string& name) { this->name = name; }

	const std::string getName() const { return name; }

	ImVec2 getPosition() const { return position; }

	virtual void show(ImDrawList* drawList, ImVec2 offset) = 0;

	void move(ImVec2 v) { this->position.x += v.x; this->position.y += v.y; }

	ImVec2 getSize() const { return size; }

	ImVec2 size;

private:
	const int id;
	std::string name;
	ImVec2 position;

	std::vector<IInSlot*> inputs;
	std::vector<IOutSlot*> outputs;
};

class ILink
{
public:
	explicit ILink(const int id, IOutSlot* out, IInSlot* in) :
		id(id),
		outSlot(out),
		inSlot(in)
	{
	}

	void setOut(IOutSlot* slot) { this->outSlot = slot; }

	void setIn(IInSlot* slot) { this->inSlot = slot; }

	void show(ImDrawList* drawList, const ImVec2& offset);

	//virtual void build() = 0;

private:
	int id;
	IOutSlot* outSlot;
	IInSlot* inSlot;
};


	}
}