#pragma once
#include "../Math/Vector2d.h"

namespace Crystal {
	namespace UI {

class IKeyListener
{
	virtual void onKeyDown(const int key) {};

	virtual void onKeyUp(const int key) {};
};

	}
}