#pragma once

namespace Crystal {
	namespace UI {
		class ViewModel;

class IRenderer
{
public:
	virtual ~IRenderer() {}

	virtual bool build() = 0;

	virtual void render(const int width, const int height) = 0;

	virtual void setViewModel(const ViewModel& vm) = 0;
};
	}
}