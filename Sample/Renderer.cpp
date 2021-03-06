#include "Renderer.h"
#include "../../Crystal/UI/ViewModel.h"

#include "../ThirdParty/stb/stb_image.h"

using namespace Crystal::Graphics;
using namespace Crystal::UI;

bool Renderer::build()
{
	if (!pointRenderer.build()) {
		return false;
	}
	if (!wireRenderer.build()) {
		return false;
	}
	if (!smoothRenderer.build()) {
		return false;
	}

	/*
	int width;
	int height;
	int bpp;
	auto pixels = stbi_load("C:\\Users\\PremiumGraphics\\Desktop\\SS.JPG", &width, &height, &bpp, 0);
	Graphics::Image image(width, height);
	int index = 0;
	for (int j = 0; j < height; ++j) {
		for (int i = 0; i < width; ++i) {
			auto r = pixels[index++];
			auto g = pixels[index++];
			auto b = pixels[index++];
			unsigned char a = 0;
			if (bpp == 4) {
				a = pixels[index++];
			}
			image.setColor(i, j, ColorRGBAuc(r,g,b,a));
		}
	}
	stbi_image_free(pixels);
	*/
	Image image(2, 2);
	image.setColor(0, 0, ColorRGBAuc(255, 0, 0, 0));
	image.setColor(1, 0, ColorRGBAuc(0, 255, 0, 0));
	image.setColor(0, 1, ColorRGBAuc(0, 0, 255, 0));
	image.setColor(1, 1, ColorRGBAuc(255, 255, 255, 0));

	texture.create(image, 0);
	return true;
}

void Renderer::setViewModel(const ViewModel& vm)
{
	this->pointRenderer.setBuffer(vm.getPointBuffer());
	this->wireRenderer.setBuffer(vm.getLineBuffer(), 1.0f);
	this->smoothRenderer.setBuffer(vm.getTriangleBuffer());
}

void Renderer::render(const int width, const int height)
{
	Graphics::PointLight light;
	light.setPos(glm::vec3(100, 100, 100));
	light.setAmbient(glm::vec4(1, 1, 1, 1));
	light.setDiffuse(glm::vec4(1, 1, 1, 1));
	light.setSpecular(glm::vec4(1, 1, 1, 1));

	glClearColor(0.0, 0.0, 1.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	pointRenderer.render(*camera);
	wireRenderer.render(*camera);
	smoothRenderer.render(*camera, light, texture);
}