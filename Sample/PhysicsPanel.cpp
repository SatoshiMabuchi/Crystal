#include "PhysicsPanel.h"

#include "imgui.h"

#include "../Math/Box3d.h"
#include "../Physics/PhysicsObject.h"

using namespace Crystal::Math;
using namespace Crystal::Physics;

PhysicsPanel::PhysicsPanel() :
	isUnderSimulation(false)
{}

void PhysicsPanel::show()
{
	ImGui::Begin("Physics");
	if (ImGui::Button("Add")) {
		ImGui::OpenPopup("Add");
	}
	if (ImGui::BeginPopup("Add")) {
		static float point1[3] = { 0.0f, 0.0f, 0.0f };
		ImGui::InputFloat3("Point1", point1);
		static float point2[3] = { 1.0f, 1.0f, 1.0f };
		ImGui::InputFloat3("Point2", point2);
		static float divideLength = 0.1f;
		ImGui::InputFloat("DivideLength", &divideLength);
		static float density = 1000.0f;
		ImGui::InputFloat("Density", &density);
		static float pressureCoe = 1.0f;
		ImGui::InputFloat("PressureCoe", &pressureCoe);
		static float viscosityCoe = 1.0f;
		ImGui::InputFloat("ViscosityCoe", &viscosityCoe);
		SPHConstant constant(density, pressureCoe,viscosityCoe, 0.0f, divideLength);
		if (ImGui::Button("OK")) {
			Box3d<float> box(Vector3d<float>(0.0, 0.0, 0.0), Vector3d<float>(1.0, 1.0, 1.0));
			PhysicsObject* object = new PhysicsObject(box, divideLength, constant);
			world.add(object);
		}
		ImGui::EndPopup();
	}
	if (ImGui::Button("Start")) {
		isUnderSimulation = !isUnderSimulation;
	}
	ImGui::End();
}