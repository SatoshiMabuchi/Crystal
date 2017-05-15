#pragma once

#include "../Physics/PhysicsWorld.h"

class PhysicsPanel
{
public:
	PhysicsPanel();

	void show();

private:
	bool isUnderSimulation;
	Crystal::Physics::PhysicsWorld world;
};