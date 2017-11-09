#ifndef __CRYSTAL_GRAPHICS_MATERIAL_H__
#define __CRYSTAL_GRAPHICS_MATERIAL_H__

#include <list>
#include <string>
#include <memory>

#include "ColorRGBA.h"
//#include "Texture.h"

namespace Crystal {
	namespace Graphics {


		class Material
		{
		public:

			Material(const unsigned int id = 0) :
				diffuse(Graphics::ColorRGBAf(0,0,0,0)),
				specular(Graphics::ColorRGBAf(0,0,0,0)),
				ambient(Graphics::ColorRGBAf(0,0,0,0)),
				shininess(1.0f),
				transparent(0.0f),
				id(id)
			{}

			~Material()
			{}

		public:

			std::string getName() const { return name; }

			void setName(const std::string& name) { this->name = name; }

			void setAmbient(const Graphics::ColorRGBAf& a) { this->ambient = a; }

			Graphics::ColorRGBAf getAmbient() const { return ambient; }

			void setDiffuse(const Graphics::ColorRGBAf& d) { this->diffuse = d; }

			Graphics::ColorRGBAf getDiffuse() const { return diffuse; }

			void setSpecular(const Graphics::ColorRGBAf& s) { this->specular = s; }

			Graphics::ColorRGBAf getSpecular() const { return specular; }

			void setShininess(const float s) { this->shininess = s; }

			float getShininess() const { return shininess; }

			void setTransparent(const float t) { this->transparent = t; }

			float getTransparent() const { return transparent; }

			//Texture getTexture() const { return texture; }

			//void setTexture(const Texture texture) { this->texture = texture; }

			unsigned int getId() const { return id; }

		private:
			std::string name;

			float shininess;
			float transparent;
			Graphics::ColorRGBAf ambient;
			Graphics::ColorRGBAf diffuse;
			Graphics::ColorRGBAf specular;

			const unsigned int id;

			//Texture texture;
		};

		//using PolygonMaterialMap = std::map<Core::PolygonMesh*, Material*>;

	}
}


#endif