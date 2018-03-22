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
	ImGui::Begin("WireFrame");
	if (ImGui::Button("Box")) {
		ImGui::OpenPopup("Box");
	}
	if (ImGui::BeginPopup("Box")) {
		static glm::vec3 min = { -1.0f, -1.0f, -1.0f };
		ImGui::InputFloat3("Min", &min[0]);
		static glm::vec3 max = { 1.0f, 1.0f, 1.0f };
		ImGui::InputFloat3("Max", &max[0]);
		static glm::vec4 color;
		ImGui::ColorPicker4("Color", &color[0]);
		if (ImGui::Button("OK")) {
			const Box3d box(min, max);
			Crystal::Shape::WireFrameBuilder builder;
			builder.build(box);
			model->getRepository()->addWireFrame(builder.getWireFrame(), color);
			canvas->setViewModel(model->toViewModel());
			canvas->fitCamera(model->getBoundingBox());
			ImGui::CloseCurrentPopup();
		}
		ImGui::EndPopup();
	}

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
			model->getRepository()->addWireFrame(builder.getWireFrame(), ColorRGBAf(1, 1, 1, 1));
			canvas->setViewModel(model->toViewModel());
			canvas->fitCamera(model->getBoundingBox());
			ImGui::CloseCurrentPopup();
		}
		ImGui::EndPopup();
	}
	ImGui::End();
}