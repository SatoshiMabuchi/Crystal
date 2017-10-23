#ifndef __CRYSTAL_I_IMAGE_H__
#define __CRYSTAL_I_IMAGE_H__

#include <vector>
#include <cassert>

#include <memory>

#include "ColorRGBA.h"

namespace Crystal {
	namespace Graphics {

		enum class ImageFileFormat
		{
			BMP,
			PNG,
			JPG,
		};

		class IImage
		{
		public:
			IImage(const int id = -1) :
				width(0),
				height(0),
				id(id)
			{}

			IImage(const int width, const int height, const int id = -1) :
				width(width),
				height(height),
				id(id)
			{}

			int getWidth() const { return width; }

			int getHeight() const { return height; }

			void changeSize(const int width, const int height) {
				this->width = width;
				this->height = height;
			}

			int getIndex1d(const int x, const int y) const { return (y * width + x) * 4; }

			int getId() const { return id; }

		private:
			int width;
			int height;
			int id;
		};

	}
}

#endif