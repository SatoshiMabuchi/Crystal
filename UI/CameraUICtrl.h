#pragma once

#include <memory>
#include "../Graphics/ICamera.h"
#include "IUICtrl.h"

namespace Crystal {
	namespace UI {

class CameraUICtrl : public IUICtrl
{
public:
	explicit CameraUICtrl(Graphics::ICamera<float>* camera);

	virtual void onLeftButtonDown(const Math::Vector2d<float>& position) override;

	virtual void onLeftButtonUp(const Math::Vector2d<float>& position) override;

	virtual void onRightButtonDown(const Math::Vector2d<float>& position) override;

	virtual void onRightButtonUp(const Math::Vector2d<float>& position) override;

private:
	Graphics::ICamera<float>* camera;
};
	}
}