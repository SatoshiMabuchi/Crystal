#ifndef __CRYSTAL_GRAPHICS_IMAGE_H__
#define __CRYSTAL_GRAPHICS_IMAGE_H__

#include "IImage.h"

namespace Crystal {
	namespace Graphics {

class Image : public IImage
{
public:
	Image(const int id = -1) : IImage(id)
	{}

	Image(const int width, const int height, const int id = -1) : IImage(width, height, id),
		values(width * height * 4)
	{}

	Image(const int width, const int height, const std::vector< unsigned char >& values, const int id = -1) :
		IImage(width, height, id),
		values(values)
	{
		assert(isValid());
	}

	Image(const int width, const int height, const unsigned char v) :
		IImage(width, height)
	{
		values.resize(width * height * 4);
		std::fill(values.begin(), values.end(), v);
		assert(isValid());
	}

	explicit Image(const std::string& filename) { read(filename); }

	static Image White(const int width, const int height) {
		std::vector<unsigned char> values(width * height * 4);
		for (int i = 0; i < width * height; ++i) {
			values[i * 4] = 255;
			values[i * 4 + 1] = 255;
			values[i * 4 + 2] = 255;
			values[i * 4 + 3] = 255;

		}
		return Image(width, height, values);
	}

	static Image Black(const int width, const int height) {
		std::vector<unsigned char> values(width * height * 4);
		for (int i = 0; i < width * height; ++i) {
			values[i * 4] = 0;
			values[i * 4 + 1] = 0;
			values[i * 4 + 2] = 0;
			values[i * 4 + 3] = 255;
		}
		return Image(width, height, values);
	}



	static Image Red(const int width, const int height) {
		std::vector<unsigned char> values(width * height * 4);
		for (int i = 0; i < width * height; ++i) {
			values[i * 4] = 255;
			values[i * 4 + 3] = 255;
		}
		return Image(width, height, values);
	}

	static Image Green(const int width, const int height) {
		std::vector<unsigned char> values(width * height * 4);
		for (int i = 0; i < width * height; ++i) {
			values[i * 4 + 1] = 255;
			values[i * 4 + 3] = 255;
		}
		return Image(width, height, values);
	}

	static Image Blue(const int width, const int height) {
		std::vector<unsigned char> values(width * height * 4);
		for (int i = 0; i < width * height; ++i) {
			values[i * 4 + 2] = 255;
			values[i * 4 + 3] = 255;
		}
		return Image(width, height, values);
	}


	//std::vector< T > getValues() const { return values; }

	bool isValid() const { return ((getWidth() * getHeight() * 4) == values.size()); }

	void setColor(const int i, const int j, const ColorRGBA<unsigned char>& c) {
		const auto index = getIndex1d(i, j);
		values[index] = c.getRed();
		values[index + 1] = c.getGreen();
		values[index + 2] = c.getBlue();
		values[index + 3] = c.getAlpha();
	}


	ColorRGBA<unsigned char> getColor(const int x, const int y) const {
		const auto index = getIndex1d(x, y);
		const auto r = values[index];
		const auto g = values[index + 1];
		const auto b = values[index + 2];
		const auto a = values[index + 3];
		return ColorRGBA<unsigned char>(r, g, b, a);
	}

	void changeSize(const int sizeX, const int sizeY);

	std::vector<unsigned char> getValues() const { return values; }

	bool equals(const Image& rhs) const {
		return
			(getWidth() == rhs.getWidth()) &&
			(getHeight() == rhs.getHeight()) &&
			(values == rhs.values);
	}

	bool operator==(const Image& rhs) const { return equals(rhs); }

	bool operator!=(const Image& rhs) const { return !equals(rhs); }

	void read(const std::string& filename) override;

	void save(const std::string& filename, const ImageFileFormat format) const override;

	Image reversed()
	{
		Image dest(getWidth(), getHeight());
		for (int x = 0; x < getWidth(); ++x) {
			for (int y = 0; y < getHeight(); ++y) {
				const auto destY = getHeight() - y - 1;
				const auto c = getColor(x, y);
				dest.setColor(x, destY, c);
			}
		}
		return dest;
	}


private:
	std::vector< unsigned char > values;
};

	}
}

#endif