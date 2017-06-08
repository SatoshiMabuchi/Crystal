#pragma once

#include "INode.h"
#include "Vector3dArrayLink.h"
//#include "Color4dArrayLink.h"

namespace Crystal {
	namespace UI {

		class ParticleNode : public INode
		{
		public:
			ParticleNode(const int id, const std::string& name, const ImVec2& pos);

			void show(ImDrawList* drawList, ImVec2 offset) override;

		private:
//			Vector3dArrayOutSlot positionSlot;
//			Color4dArrayOutSlot colorSlot;
		};

	}
}