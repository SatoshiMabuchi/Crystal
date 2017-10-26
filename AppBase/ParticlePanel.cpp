#include "ParticlePanel.h"
#include "../ThirdParty/imgui-1.51/imgui.h"
#include "../UI/IModel.h"
#include "../UI/ICanvas.h"
#include "../UI/ICommand.h"

using namespace Crystal::Math;
using namespace Crystal::Graphics;
using namespace Crystal::UI;

namespace {
	class ParticleGenerateCommand : public ICommand
	{
	public:
		ParticleGenerateCommand(IModel* model, ICanvas* canvas) :
			model(model),
			canvas(canvas)
		{}

		void execute() override
		{
			std::vector<Vector3d<double>> positions;
			positions.push_back(Vector3d<double>(0, 0, 0));
			model->addParticleSystem(positions, ColorRGBA<float>(1,1,1,1));
		}

	private:
		IModel* model;
		ICanvas* canvas;
	};
}

void ParticlePanel::show()
{
	if (ImGui::Button("Box")) {
		ImGui::OpenPopup("Box");
	}
	if (ImGui::BeginPopup("Box")) {
		if (ImGui::Button("OK")) {
			ParticleGenerateCommand command(model, canvas);
			command.execute();
			ImGui::CloseCurrentPopup();
		}
		ImGui::EndPopup();
	}
}