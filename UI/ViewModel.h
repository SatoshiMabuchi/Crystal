#pragma once

#include "../Graphics/PointBuffer.h"

namespace Crystal {
	namespace UI {
		class IModel;

class ViewModel
{
public:
	void update(IModel* model);
private:
	Graphics::PointBuffer pointBuffer;
};
	}
}