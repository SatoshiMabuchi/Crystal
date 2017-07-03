#pragma once

#include "cereal/cereal.hpp"
#include "ShaderNode.h"
#include "ShaderSlot.h"
#include "Vector3dArrayLink.h"

namespace Crystal {
	namespace UI {

		template<class Archive>
		void serialize(Archive& archive, ShaderInputSlot& input)
		{
			archive(input.id);
		}

		/*
		template<class Archive>
		void serialize(Archive& archive, INode& node)
		{
			archive(cereal::make_nvp("id", shaderNode.id));
			archive(cereal::make_nvp("name", shaderNode.name));
		}
		*/

		template<class Archive>
		void serialize(Archive& archive, ShaderNode& shaderNode)
		{
			//serialize(archive, shaderNode);
			//archive(cereal::make_nvp("source", shaderNode.shader.))
			for (auto slot : shaderNode.inputSlots) {
				archive(*slot);
			}
		}

		template<class Archive>
		void serialize(Archive& archive, Matrix4dLink& link)
		{
			archive(cereal::make_nvp("matrix4d",link.input->value));
		}

		template<class Archive>
		void serialize(Archive& archive, Vector3dArrayLink& link)
		{
			archive(cereal::make_nvp("value"), link.input->value);
		}
	}
}