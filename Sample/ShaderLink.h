#ifndef __CRYSTAL_UI_SHADER_LINK_H__
#define __CRYSTAL_UI_SHADER_LINK_H__

#include "ShaderSlot.h"

namespace Crystal {
	namespace UI {

class ShaderNode;
//class ShaderOutputSlot;
//class ShaderInputSlot;

class ShaderLink
{
public:
	ShaderLink(ShaderOutputSlot* out, ShaderInputSlot* in) :
		out(out),
		in(in)
	{
	}

	ShaderOutputSlot* out;
	ShaderInputSlot* in;
};

	}
}

#endif