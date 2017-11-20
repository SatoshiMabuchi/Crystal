#include "WireFramePanel.h"
#include "../ThirdParty/imgui-1.51/imgui.h"
#include "../UI/IModel.h"
#include "../UI/ICanvas.h"
#include "../Shape/WireFrameBuilder.h"

#include <cereal/cereal.hpp>

using namespace Crystal::Math;
using namespace Crystal::Graphics;
using namespace Crystal::UI;

void WireFramePanel::show()
{
	/*
	if (ImGui::Button("Box")) {
		ImGui::OpenPopup("Box");
	}
	if (ImGui::BeginPopup("Box")) {
		static glm::vec3 min = { -10.0f, -10.0f, -10.0f };
		ImGui::InputFloat3("Min", &min[0]);
		static glm::vec3 max = { 10.0f, 10.0f, 10.0f };
		ImGui::InputFloat3("Max", &max[0]);
		static glm::vec3 dx = { 1.0f, 1.0f, 1.0f };
		ImGui::InputFloat3("Dx", &dx[0]);

		if (ImGui::Button("OK")) {
			std::vector<Vector3df> positions;
			for (double x = min.x; x < max.x; x += dx[0]) {
				for (double y = min.y; y < max.y; y += dx[1]) {
					for (double z = min.z; z < max.z; z += dx[2]) {
						positions.push_back(Vector3df(x, y, z));
					}
				}
			}
			Crystal::Shape::WireFrameBuilder builder;
			model->addParticleSystem(positions, ColorRGBAf(1, 1, 1, 1), 100.0f);
			canvas->setViewModel(model->toViewModel());
			canvas->fitCamera(model->getBoundingBox());
			model->addWireFrame();
			ImGui::CloseCurrentPopup();
		}
		ImGui::EndPopup();
	}
	*/

	if (ImGui::Button("Sphere")) {
		ImGui::OpenPopup("Sphere");
	}
	if (ImGui::BeginPopup("Sphere")) {
		static glm::vec3 center = { 0.0f, 0.0f, 0.0f };
		ImGui::InputFloat3("Center", &center[0]);
		static float radius = 1.0;
		ImGui::InputFloat("Radius", &radius);
		
		if (ImGui::Button("OK")) {
			Sphere3d sphere(center, radius);
			Crystal::Shape::WireFrameBuilder builder;
			builder.build(sphere);
			model->addWireFrame(builder.getWireFrame(), ColorRGBAf(1, 1, 1, 1));
			canvas->setViewModel(model->toViewModel());
			canvas->fitCamera(model->getBoundingBox());
			ImGui::CloseCurrentPopup();
		}
		ImGui::EndPopup();
	}
}