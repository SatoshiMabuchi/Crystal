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
			std::vector<Vector3d<float>> positions;
			for (double x = -5.0; x < 5.0; x += 1.0) {
				for (double y = -5.0; y < 5.0; y += 1.0) {
					for (double z = -5.0; z < 5.0; z += 1.0) {
						positions.push_back(Vector3d<float>(x, y, z));
					}
				}
			}
			model->addParticleSystem(positions, ColorRGBA<float>(1,1,1,1), 100.0f);
			canvas->setViewModel( model->toViewModel() );
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