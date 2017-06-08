#pragma once

#include "INode.h"

#include "../Math/Vector3d.h"
#include "../Graphics/Buffer3d.h"

namespace Crystal {
	namespace UI {

		class Vector3dArrayInSlot : public IInSlot
		{
		public:
			void setValue(const std::vector <Math::Vector3d <double>> &value) {
				this->value.clear();
				for (auto v : value) {
					this->value.add(v);
				}
			}

		private:
			Graphics::Buffer3d<double> value;
		};

		class Vector3dArrayOutSlot : public IOutSlot
		{
		public:
			std::vector<Math::Vector3d<double>> getValue() const { return value; }

		private:
			std::vector<Math::Vector3d<double>> value;
		};

		class Vector3dArrayLink : public ILink
		{
		private:
			void build() override {
				input->setValue(output->getValue());
			}

			Vector3dArrayOutSlot* output;
			Vector3dArrayInSlot* input;
		};


	}
}