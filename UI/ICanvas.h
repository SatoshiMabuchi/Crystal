#ifndef __CRYSTAL_UI_I_CANVAS_H__
#define __CRYSTAL_UI_I_CANVAS_H__

#include "../Math/Vector2d.h"
#include "../Shader/PointRenderer.h"
#include "../Graphics/ICamera.h"
#include <memory>
#include <list>

#include "IUICommand.h"
#include "CommandChain.h"
#include "ViewModel.h"

namespace Crystal {
	namespace UI {
		class IUICtrl;
		class IModel;


class ICanvas : public IMouseListener
{
public:
	void build();

	void setViewModel(const ViewModel& vm) { this->viewModel = vm; }

	void setUICommands(CommandChain* chain) { this->commands.reset(chain); }

	void render(const int width, const int height);

	virtual void onLeftButtonDown(const Math::Vector2d<float>& position) override;

	virtual void onLeftButtonUp(const Math::Vector2d<float>& position) override;

	virtual void onRightButtonDown(const Math::Vector2d<float>& position) override;

	virtual void onRightButtonUp(const Math::Vector2d<float>& position) override;

	virtual void onMiddleButtonDown(const Math::Vector2d<float>& position) override;

	virtual void onMiddleButtonUp(const Math::Vector2d<float>& position) override;

	virtual void onLeftDragging(const Math::Vector2d<float>& position) override;

	virtual void onRightDragging(const Math::Vector2d<float>& position) override;

	virtual void onMiddleDragging(const Math::Vector2d<float>& position) override;

	Graphics::ICamera<float>* getCamera() { return camera.get(); }

private:
	std::unique_ptr<Graphics::ICamera<float>> camera;
	std::unique_ptr<CommandChain> commands;
	Shader::PointRenderer pointRenderer;
	Graphics::PointBuffer pointBuffer;
	ViewModel viewModel;
};
	}
}

#endif