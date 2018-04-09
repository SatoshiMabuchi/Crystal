#include "PolygonPanel.h"
#include "../Math/Vector3d.h"
#include "../UI/IModel.h"
#include "../UI/ICanvas.h"
#include "../Shape/PolygonMeshBuilder.h"
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
		static float radius = 1.0f;
		static int unum = 36;
		static int vnum = 36;

		ImGui::InputFloat3("Center", &center[0]);
		ImGui::InputFloat3("Radius", &radius);
		ImGui::InputInt("UNum", &unum);
		ImGui::InputInt("VNum", &vnum);

		if (ImGui::Button("OK")) {
			PolygonMeshBuilder builder;
			const Sphere3d sphere(center, radius);
			builder.build(sphere, unum, vnum);
			Graphics::Material material;
			material.setAmbient( glm::vec3(1, 0, 0) );
			model->getRepository()->addPolygonMesh(builder.getPolygonMesh(), material);
			canvas->setViewModel(model->toViewModel());
			canvas->fitCamera(model->getBoundingBox());
			ImGui::CloseCurrentPopup();
		}
		ImGui::EndPopup();
	}

	if (ImGui::Button("Box")) {
		ImGui::OpenPopup("Box");
	}
	if (ImGui::BeginPopup("Box")) {
		static glm::vec3 point1 = { 0,0,0 };
		static glm::vec3 point2 = { 1,1,1 };

		ImGui::InputFloat3("Point1", &point1[0]);
		ImGui::InputFloat3("Point2", &point2[0]);

		if (ImGui::Button("OK")) {
			PolygonMeshBuilder builder;
			const Box3d box(point1, point2);
			builder.build(box);
			Graphics::Material material;
			material.setAmbient(glm::vec3(1, 0, 0));
			model->getRepository()->addPolygonMesh(builder.getPolygonMesh(), material);
			canvas->setViewModel(model->toViewModel());
			canvas->fitCamera(model->getBoundingBox());
			ImGui::CloseCurrentPopup();
		}
		ImGui::EndPopup();
	}

	if (ImGui::Button("Plane")) {
		ImGui::OpenPopup("Plane");
	}
	if (ImGui::BeginPopup("Plane")) {
		static glm::vec3 origin(0, 0, 0);
		static glm::vec3 uvec(1, 0, 0);
		static glm::vec3 vvec(0, 1, 0);
		if (ImGui::Button("OK")) {
			PolygonMeshBuilder builder;
			builder.build(origin, uvec, vvec);
			Graphics::Material material;
			material.setAmbient(glm::vec3(1, 0, 0));
			model->getRepository()->addPolygonMesh(builder.getPolygonMesh(), material);
			canvas->setViewModel(model->toViewModel());
			canvas->fitCamera(model->getBoundingBox());
			ImGui::CloseCurrentPopup();
		}
		ImGui::EndPopup();
	}

	ImGui::End();
}