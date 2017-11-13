#include "CameraMenu.h"
#include "imgui.h"
#include "../UI/IModel.h"
#include "../UI/ICanvas.h"

using namespace Crystal::UI;

void CameraMenu::show()
{
	if (ImGui::BeginMenu("Camera")) {
		if (ImGui::MenuItem("Fit")) {
			canvas->fitCamera(model->getBoundingBox());
			canvas->setViewModel( model->toViewModel() );
		}
		if (ImGui::MenuItem("XY")) {
			canvas->setCameraXY(model->getBoundingBox());
			canvas->setViewModel(model->toViewModel());
		}
		if (ImGui::MenuItem("YZ")) {
			canvas->setCameraYZ(model->getBoundingBox());
			canvas->setViewModel(model->toViewModel());
		}
		if (ImGui::MenuItem("ZX")) {
			canvas->setCameraZX(model->getBoundingBox());
			canvas->setViewModel(model->toViewModel());
		}

		ImGui::EndMenu();
	}
	//ImGui::EndMenuBar();

}
