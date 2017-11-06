#include "ParticlePanel.h"
#include "../ThirdParty/imgui-1.51/imgui.h"
#include "../UI/IModel.h"
#include "../UI/ICanvas.h"
#include "../UI/ICommand.h"

#include <cereal/cereal.hpp>

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
			Box3d box;
			glm::vec3 dx;
			template<class Archive>
			void serialize(Archive & archive) {
				archive(box);
				archive(dx);
			}
		};

		void setArgs(Args args) {
			this->args = args;
		};

		void execute() override
		{
			std::vector<Vector3df> positions;
			const auto& min = this->args.box.getMin();
			const auto& max = this->args.box.getMax();
			for (double x = min.x; x < max.x; x += args.dx[0]) {
				for (double y = min.y; y < max.y; y += args.dx[1]) {
					for (double z = min.z; z < max.z; z += args.dx[2]) {
						positions.push_back(Vector3df(x, y, z));
					}
				}
			}
			model->addParticleSystem(positions, ColorRGBA<float>(1,1,1,1), 100.0f);
			canvas->setViewModel( model->toViewModel() );
			canvas->fitCamera( model->getBoundingBox() );
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
		static glm::vec3 min = { -10.0f, -10.0f, -10.0f };
		ImGui::InputFloat3("Min", &min[0]);
		static glm::vec3 max = { 10.0f, 10.0f, 10.0f };
		ImGui::InputFloat3("Max", &max[0]);
		static glm::vec3 dx = { 1.0f, 1.0f, 1.0f };
		ImGui::InputFloat3("Dx", &dx[0]);

		if (ImGui::Button("OK")) {
			ParticleGenerateCommand command(model, canvas);
			ParticleGenerateCommand::Args args;
			args.box = Box3d(Vector3df(min[0], min[1], min[2]), Vector3df(max[0], max[1], max[2]));
			args.dx = dx;
			command.setArgs(args);
			command.execute();
			ImGui::CloseCurrentPopup();
		}
		ImGui::EndPopup();
	}
}