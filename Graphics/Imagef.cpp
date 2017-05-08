#include "Imagef.h"

#include "stb_image.h"

using namespace Crystal::Graphics;

void Imagef::read(const std::string& filename)
{
	int width = 0;
	int height = 0;
	int comp = 0;
	const auto loaded = stb::stbi_load(filename.c_str(), &width, &height, &comp, 4);
	assert(loaded != nullptr);
	assert(comp == stb::STBI_rgb || comp == stb::STBI_rgb_alpha);
	std::vector<float> values(width * height * 4);
	for (int i = 0; i < width * height; ++i) {
		values[i * 4] = loaded[i * 4] / 255.0f;
		values[i * 4 + 1] = loaded[i * 4 + 1] / 255.0f;
		values[i * 4 + 2] = loaded[i * 4 + 2] / 255.0f;
		values[i * 4 + 3] = loaded[i * 4 + 3] / 255.0f;
	}
	changeSize(width, height);
	this->values = values;
}

void Imagef::save(const std::string& filename, const ImageFileFormat format) const {
	std::vector<float> data = values;
	int comp = 4;
	if (format == ImageFileFormat::PNG) {
		stb::stbi_write_png(filename.c_str(), getWidth(), getHeight(), comp, data.data(), getWidth() * comp);
	}
	else if (format == ImageFileFormat::BMP) {
		stb::stbi_write_bmp(filename.c_str(), getWidth(), getHeight(), comp, data.data());
	}
	else {
		assert(false);
	}
}

void Imagef::changeSize(const int sizeX, const int sizeY)
{
	std::vector<float> dest(sizeX * sizeY * 4);
	stb::stbir_resize_float(values.data(), getWidth(), getHeight(), 0, dest.data(), sizeX, sizeY, 0, 4);

	IImage::changeSize(sizeX, sizeY);
	this->values = dest;
}