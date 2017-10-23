#ifndef __CRYSTAL_UI_I_CANVAS_H__
#define __CRYSTAL_UI_I_CANVAS_H__

#include "../Math/Vector2d.h"
#include "../Shader/PointRenderer.h"
#include "../Graphics/ICamera.h"
#include <memory>

#include "IUICommand.h"

namespace Crystal {
	namespace UI {
		class IUICtrl;
		class IModel;


class ICanvas
{
public:
	void build();

	void setUICommand(IUICommand* ctrl) { this->ctrl = ctrl; }


	//void update(IModel* model);

	void render(const int width, const int height);

private:
	std::unique_ptr<Graphics::ICamera<float>> camera;
	IUICommand* ctrl;
	Shader::PointRenderer pointRenderer;
	Graphics::PointBuffer pointBuffer;
};
	}
}

#endif