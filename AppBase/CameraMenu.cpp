#include "CameraMenu.h"
#include "imgui.h"
#include "../UI/IModel.h"
#include "../UI/ICanvas.h"

using namespace Crystal::UI;

void CameraMenu::show()
{
	if (ImGui::BeginMenu("Ctrl")) {
		if (ImGui::MenuItem("Fit")) {
			canvas->fitCamera(model->getBoundingBox());
			canvas->setViewModel( model->toViewModel() );
		}
		if (ImGui::MenuItem("XY")) {
			canvas->setCameraXY(model->getBoundingBox());
			canvas->setViewModel(model->toViewModel());
		}
		if (ImGui::MenuItem("YZ")) {
			//canvas->addUICommand(new RectSelectUICtrl(canvas->getCamera()));
		}
		if (ImGui::MenuItem("ZX")) {
			CommandChain* chain = new CommandChain();
			//chain->setOrigin(new PickUICommand(canvas->getCamera()));
			canvas->setUICommands(chain);
		}


		ImGui::EndMenu();
	}
	//ImGui::EndMenuBar();

}
