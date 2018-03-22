#include "PolygonPanel.h"
#include "../Math/Vector3d.h"
#include "../UI/IModel.h"
#include "../UI/ICanvas.h"
#include "../Shape/WireFrameBuilder.h"
#include "../Graphics/ColorRGBA.h"
#include "../ThirdParty/imgui-1.51/imgui.h"

using namespace Crystal::Math;
using namespace Crystal::Shape;
using namespace Crystal::UI;

void PolygonPanel::show()
{
	ImGui::Begin("Polygon");

	if (ImGui::Button("Sphere")) {
		ImGui::OpenPopup("Sphere");
	}
	if (ImGui::BeginPopup("Sphere")) {
		static glm::vec3 center = { 0,0,0 };
		ImGui::InputFloat3("Center", &center[0]);
		static float radius = 1.0f;
		ImGui::InputFloat3("Radius", &radius);

		if (ImGui::Button("OK")) {
			WireFrameBuilder builder;
			const Sphere3d sphere(center, radius);
			builder.build(sphere);
			model->getRepository()->addWireFrame(builder.getWireFrame(), Graphics::ColorRGBAf(1, 0, 0, 0));
			canvas->setViewModel(model->toViewModel());
			canvas->fitCamera(model->getBoundingBox());
			ImGui::CloseCurrentPopup();
		}
		ImGui::EndPopup();
	}

	ImGui::End();
}