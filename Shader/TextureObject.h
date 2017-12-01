#ifndef __CRYSTAL_SHADER_TEXTURE_H__
#define __CRYSTAL_SHADER_TEXTURE_H__

#include "../Graphics/Image.h"
#include "../Graphics/Imagef.h"
#include "ITextureObject.h"

namespace Crystal {
	namespace Shader {


class TextureObject : public ITextureObject
{
public:
	TextureObject(const int id = 0) :
		ITextureObject(id)
	{}

	TextureObject(const Graphics::Image& image, const int id = 0);

	TextureObject(const Graphics::Imagef& image, const int id = 0);

	void create(const Graphics::Image& image, const int id = 0);

	void create(const Graphics::Imagef& image, const int id = 0);

	void send(const Graphics::Image& image);

	void send(const Graphics::Imagef& image);

	void bind() const override;

	void unbind() const override;

private:
};


	}
}

#endif