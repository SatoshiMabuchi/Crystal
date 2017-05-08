#ifndef __CRYSTAL_UI_SHADER_LINK_H__
#define __CRYSTAL_UI_SHADER_LINK_H__

namespace Crystal {
	namespace UI {

class ShaderNode;

class ShaderLink
{
public:
	ShaderLink(ShaderNode* inputNode, int input_slot, ShaderNode* outputNode, int output_slot) :
		inputNode(inputNode),
		outputNode(outputNode)
	{
		InputSlot = input_slot; OutputSlot = output_slot;
	}

	ShaderNode* inputNode;
	int InputSlot;
	ShaderNode* outputNode;
	int OutputSlot;
};

	}
}

#endif