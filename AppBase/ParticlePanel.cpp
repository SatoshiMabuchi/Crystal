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

		struct Args {
			Box3d<float> box;
			glm::vec3 dx;
		};

		void setArgs(Args args) {
			this->args = args;
		};

		void execute() override
		{
			std::vector<Vector3d<float>> positions;
			const auto& min = this->args.box.getMin();
			const auto& max = this->args.box.getMax();
			for (double x = min.getX(); x < max.getX(); x += args.dx[0]) {
				for (double y = min.getY(); y < max.getY(); y += args.dx[1]) {
					for (double z = min.getZ(); z < max.getZ(); z += args.dx[2]) {
						positions.push_back(Vector3d<float>(x, y, z));
					}
				}
			}
			model->addParticleSystem(positions, ColorRGBA<float>(1,1,1,1), 100.0f);
			canvas->setViewModel( model->toViewModel() );
		}

	private:
		Args args;
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
		float min[3] = { -10.0f, -10.0f, -10.0f };
		ImGui::InputFloat3("Min", min);
		float max[3] = { 10.0f, 10.0f, 10.0f };
		ImGui::InputFloat3("Max", max);
		glm::vec3 dx = { 1.0f, 1.0f, 1.0f };
		ImGui::InputFloat3("Dx", &dx[0]);

		if (ImGui::Button("OK")) {
			ParticleGenerateCommand command(model, canvas);
			ParticleGenerateCommand::Args args;
			args.box = Box3d<float>(Vector3d<float>(min[0], min[1], min[2]), Vector3d<float>(max[0], max[1], max[2]));
			args.dx = dx;
			command.setArgs(args);
			command.execute();
			ImGui::CloseCurrentPopup();
		}
		ImGui::EndPopup();
	}
}