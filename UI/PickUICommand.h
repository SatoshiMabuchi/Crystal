#include <memory>
#include "../Graphics/ICamera.h"
#include "IUICommand.h"
#include "IMouseListener.h"
#include "IUICommand.h"

namespace Crystal {
	namespace UI {

class PickUICommand : public IUICommand
{
public:
	virtual ~PickUICommand() {}

	explicit PickUICommand(Graphics::ICamera* camera);

	virtual void onLeftButtonDown(const Math::Vector2d<float>& position) override;

	virtual void onLeftButtonUp(const Math::Vector2d<float>& position) override;

	virtual void onLeftDragging(const Math::Vector2d<float>& position) override;

	virtual void onRightButtonDown(const Math::Vector2d<float>& position) override;

	virtual void onRightButtonUp(const Math::Vector2d<float>& position) override;

	virtual void onRightDragging(const Math::Vector2d<float>& position) override;

	virtual void onWheel(const float dx) override;

	virtual bool isCompleted() const override { return false; }

private:
	Math::Vector2d<float> prevPosition;
	Graphics::ICamera* camera;
};
	}
}
