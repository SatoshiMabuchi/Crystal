#pragma once

#include "../Physics/PhysicsWorld.h"

#include "../AppBase/IPanel.h"

namespace Crystal {
	namespace UI {

		class PhysicsPanel : public IPanel
		{
		public:
			PhysicsPanel(IModel* model, ICanvas* canvas);

			void show();

			std::vector<Crystal::Physics::SPHParticle*> getParticles();

		private:
			bool isUnderSimulation;
			Crystal::Physics::PhysicsWorld world;
		};

	}
}