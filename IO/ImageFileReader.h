#pragma once

#include "../Graphics/Imagef.h"

namespace Crystal {
	namespace IO {

		class ImageFileReader
		{
		public:
			bool read(const std::string& filename);

			Graphics::Imagef getImage() const { return image; }

		private:
			Graphics::Imagef image;
		};
	}
}