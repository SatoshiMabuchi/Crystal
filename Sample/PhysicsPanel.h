#pragma once

#include "../Physics/PhysicsWorld.h"

class PhysicsPanel
{
public:
	PhysicsPanel();

	void show();

	std::vector<Crystal::Physics::SPHParticle*> getParticles();

private:
	bool isUnderSimulation;
	Crystal::Physics::PhysicsWorld world;
};