#pragma once

#include "INode.h"

#include "../Math/Matrix4d.h"

namespace Crystal {
	namespace UI {

class Matrix4dInSlot : public IInSlot
{
public:
	Matrix4dInSlot(INode* parent) :
		IInSlot(parent)
	{}

	void setValue(const std::array<double, 16>& value) { this->value = value; }

private:
	std::array<double, 16> value;
};

class Matrix4dOutSlot : public IOutSlot
{
public:
	Matrix4dOutSlot(INode* parent) :
		IOutSlot(parent)
	{}

	~Matrix4dOutSlot()
	{}


	Math::Matrix4d<double> getValue() const { return value; }

private:
	Math::Matrix4d<double> value;
};

class Matrix4dLink : public ILink
{
private:
	void build() override {
		input->setValue(output->getValue().toArray());
	}

	Matrix4dOutSlot* output;
	Matrix4dInSlot* input;
};


	}
}