#pragma once

#include <memory>
#include "../Graphics/ICamera.h"
#include "IUICommand.h"
#include "IMouseListener.h"
#include "IUICommand.h"

namespace Crystal {
	namespace UI {

class CameraUICommand : public IUICommand
{
public:
	virtual ~CameraUICommand() {}

	explicit CameraUICommand(Graphics::ICamera* camera);

	virtual void onLeftButtonDown(const Math::Vector2d<float>& position) override;

	virtual void onLeftButtonUp(const Math::Vector2d<float>& position) override;

	virtual void onRightButtonDown(const Math::Vector2d<float>& position) override;

	virtual void onRightButtonUp(const Math::Vector2d<float>& position) override;

	virtual bool isCompleted() const override { return false; }

private:
	Math::Vector2d<float> prevPosition;
	Graphics::ICamera* camera;
};
	}
}