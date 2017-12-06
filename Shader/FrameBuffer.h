#ifndef __CRYSTAL_SHADER_FRAME_BUFFER_H__
#define __CRYSTAL_SHADER_FRAME_BUFFER_H__

#include "../Graphics/Image.h"
#include "TextureObject.h"
#include "DepthTextureObject.h"
#include <cassert>
#include <vector>

namespace Crystal {
	namespace Shader {

		class FrameBuffer
		{
		public:
			void build(int width, int height);

			void setTexture(const ITextureObject& texture);

			void bind();

			void unbind();

			Graphics::Image toImage() const;

			Graphics::ColorRGBAuc getColor(const int x, const int y) const;

			Graphics::ColorRGBAf getColorf(const int x, const int y) const;

			std::vector<Graphics::ColorRGBAuc> getColors(const int x, const int y, const int width, const int height) const;

			std::vector<Graphics::ColorRGBAf> getColorsf(const int x, const int y, const int width, const int height) const;

			int getWidth() const { return width; }

			int getHeight() const { return height; }

		private:
			GLuint frameBuffer;
			int width;
			int height;
		};
	}
}

#endif
