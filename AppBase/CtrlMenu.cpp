#include "CtrlMenu.h"
#include "imgui.h"
#include "../UI/IModel.h"
#include "../UI/ICanvas.h"
#include "../UI/CameraUICtrl.h"
#include "../UI/RectSelectUICtrl.h"

using namespace Crystal::UI;

void CtrlMenu::show()
{
	if (ImGui::BeginMenu("Ctrl")) {
		if (ImGui::MenuItem("Camera")) {
			canvas->clearUICommand();
			canvas->addUICommand(new CameraUICtrl(canvas->getCamera()));
		}
		if (ImGui::MenuItem("Pick")) {
		}
		if (ImGui::MenuItem("Rect")) {
			canvas->clearUICommand();
			//canvas->addUICommand(new RectSelectUICtrl(canvas->getCamera()));

		}


		ImGui::EndMenu();
	}
	//ImGui::EndMenuBar();

}
