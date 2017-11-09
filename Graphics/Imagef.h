#ifndef __CRYSTAL_GRAPHICS_IMAGE_F_H__
#define __CRYSTAL_GRAPHICS_IMAGE_F_H__

#include "IImage.h"

namespace Crystal {
	namespace Graphics {

class Imagef : public IImage
{
public:
	Imagef(const int id = -1) : IImage(id)
	{}

	Imagef(const int width, const int height, const int id = -1) :
		IImage(width, height, id),
		values(width * height * 4)
	{}

	Imagef(const int width, const int height, const std::vector< float >& values, const int id = -1) :
		IImage(width, height, id),
		values(values)
	{
		assert(isValid());
	}

	Imagef(const int width, const int height, const float v, const int id = -1) :
		IImage(width, height, id)
	{
		values.resize(width * height * 4);
		std::fill(values.begin(), values.end(), v);
		assert(isValid());
	}

	static Imagef White(const int width, const int height) {
		std::vector<float> values(width * height * 4);
		for (int i = 0; i < width * height; ++i) {
			values[i * 4] = 1.0f;
			values[i * 4 + 1] = 1.0f;
			values[i * 4 + 2] = 1.0f;
			values[i * 4 + 3] = 1.0f;

		}
		return Imagef(width, height, values);
	}

	static Imagef Black(const int width, const int height) {
		std::vector<float> values(width * height * 4);
		for (int i = 0; i < width * height; ++i) {
			values[i * 4] = 0;
			values[i * 4 + 1] = 0;
			values[i * 4 + 2] = 0;
			values[i * 4 + 3] = 1.0f;
		}
		return Imagef(width, height, values);
	}

	static Imagef Red(const int width, const int height) {
		std::vector<float> values(width * height * 4);
		for (int i = 0; i < width * height; ++i) {
			values[i * 4] = 1.0f;
			values[i * 4 + 3] = 1.0f;
		}
		return Imagef(width, height, values);
	}

	static Imagef Green(const int width, const int height) {
		std::vector<float> values(width * height * 4);
		for (int i = 0; i < width * height; ++i) {
			values[i * 4 + 1] = 1.0f;
			values[i * 4 + 3] = 1.0f;
		}
		return Imagef(width, height, values);
	}

	static Imagef Blue(const int width, const int height) {
		std::vector<float> values(width * height * 4);
		for (int i = 0; i < width * height; ++i) {
			values[i * 4 + 2] = 1.0f;
			values[i * 4 + 3] = 1.0f;
		}
		return Imagef(width, height, values);
	}

	bool isValid() const { return ((getWidth() * getHeight() * 4) == values.size()); }

	void setColor(const int i, const int j, const ColorRGBAf& c) {
		const auto index = getIndex1d(i, j);
		values[index] = c.r;
		values[index + 1] = c.g;
		values[index + 2] = c.b;
		values[index + 3] = c.a;
	}

	ColorRGBAf getColor(const int x, const int y) const {
		const auto index = getIndex1d(x, y);
		const auto r = values[index];
		const auto g = values[index + 1];
		const auto b = values[index + 2];
		const auto a = values[index + 3];
		return ColorRGBAf(r, g, b, a);
	}


	std::vector<float> getValues() const { return values; }

	bool equals(const Imagef& rhs) const {
		return
			(getWidth() == rhs.getWidth()) &&
			(getHeight() == rhs.getHeight()) &&
			(values == rhs.values);
	}

	bool operator==(const Imagef& rhs) const { return equals(rhs); }

	bool operator!=(const Imagef& rhs) const { return !equals(rhs); }
	Imagef reversed()
	{
		Imagef dest(getWidth(), getHeight());
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
	std::vector< float > values;
};

	}
}

#endif