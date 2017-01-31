#ifndef __CRYSTAL_GRAPHICS_COLOR_RGBA_H__
#define __CRYSTAL_GRAPHICS_COLOR_RGBA_H__

#include <vector>
#include <array>

namespace Crystal {
	namespace Graphics {
		class ColorHSV;

		template< typename T >
		class ColorRGBA {
		public:
			ColorRGBA();

			ColorRGBA(const T red, const T green, const T blue, const T alpha = 255);

			void setRed(const T r) { this->red = r; }

			T getRed() const { return red; }

			void setGreen(const T g) { this->green = g; }

			T getGreen() const { return this->green; }

			void setBlue(const T b) { this->blue = b; }

			T getBlue() const { return blue; }

			void setAlpha(const T a) { this->alpha = a; }

			T getAlpha() const { return alpha; }

			static ColorRGBA White() { return ColorRGBA(255, 255, 255); }

			static ColorRGBA Black() { return ColorRGBA(0, 0, 0); }

			static ColorRGBA Red() { return ColorRGBA(255, 0, 0); }

			static ColorRGBA Green() { return ColorRGBA(0, 255, 0); }

			static ColorRGBA Blue() { return ColorRGBA(0, 0, 255); }

			static ColorRGBA Yellow() { return ColorRGBA(255, 255, 0); }

			static ColorRGBA Cyan() { return ColorRGBA(0, 255, 255); }

			static ColorRGBA Magenta() { return ColorRGBA(255, 0, 255); }

			std::array<T, 3> toArray3() const;

			std::vector<T> toArray4() const;

			bool equals(const ColorRGBA& rhs) const;

			bool operator==(const ColorRGBA& rhs) const { return equals(rhs); }

			bool operator!=(const ColorRGBA& rhs) const { return !equals(rhs); }

			ColorRGBA<T> getScaled(const T f) const { return ColorRGBA<T>(getRed() * f, getGreen() * f, getBlue() * f); }

			void add(const ColorRGBA& rhs) {
				this->red += rhs.red;
				this->green += rhs.green;
				this->blue += rhs.blue;
			}

			ColorRGBA<T> getAdded(const ColorRGBA<T>& rhs) const {
				return ColorRGBA<T>(this->red + rhs.red, this->green + rhs.green, this->blue + rhs.blue);
			}

			void operator+=(const ColorRGBA& rhs) { add(rhs); }

			ColorRGBA<T> operator+(const ColorRGBA& rhs) const { return getAdded(rhs); }

			T toGrayScale() const {
				const auto g = 77 * red + 150 * green + 29 * blue;
				return g / T{ 255 };
			}

			//ColorHSV toHSV() const;

		public:
			T red;
			T green;
			T blue;
			T alpha;
		};

	}
}

#endif