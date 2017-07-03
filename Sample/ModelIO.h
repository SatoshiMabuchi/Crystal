#pragma once

#include "cereal/cereal.hpp"
#include "ShaderNode.h"

namespace Crystal {
	namespace UI {

		template<class Archive>
		void serialize(Archive& archive, ShaderNode& shaderNode)
		{
			archive(shaderNode.getId());
		}

	}
}