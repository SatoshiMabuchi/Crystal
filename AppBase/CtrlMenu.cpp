#include "CtrlMenu.h"
#include "imgui.h"
#include "../UI/IModel.h"
#include "../UI/ICanvas.h"
#include "../UI/CameraUICommand.h"
#include "../UI/RectSelectUICtrl.h"

using namespace Crystal::UI;

void CtrlMenu::show()
{
	if (ImGui::BeginMenu("Ctrl")) {
		if (ImGui::MenuItem("Camera")) {
			CommandChain* chain = new CommandChain();
			chain->setOrigin(new CameraUICommand(canvas->getCamera()));
			canvas->setUICommands(chain);
		}
		if (ImGui::MenuItem("Pick")) {
			CommandChain* chain = new CommandChain();
			//chain->setOrigin(new PickUICommand(canvas->getCamera()));
			canvas->setUICommands(chain);
		}
		if (ImGui::MenuItem("Rect")) {
			//canvas->addUICommand(new RectSelectUICtrl(canvas->getCamera()));
		}


		ImGui::EndMenu();
	}
	//ImGui::EndMenuBar();

}
