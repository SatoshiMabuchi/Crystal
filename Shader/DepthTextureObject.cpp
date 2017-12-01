#include "DepthTextureObject.h"

using namespace Crystal::Graphics;
using namespace Crystal::Shader;


DepthTextureObject::DepthTextureObject(const Imagef& image, const int id)
{
	create(image, id);
}

void DepthTextureObject::create(const Imagef& image, const int id)
{
	this->id = id;
	this->width = image.getWidth();
	this->height = image.getHeight();

	glActiveTexture(GL_TEXTURE0 + id);
	glGenTextures(1, &texHandle);
	glBindTexture(GL_TEXTURE_2D, texHandle);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT, image.getWidth(), image.getHeight(), 0, GL_DEPTH_COMPONENT, GL_FLOAT, image.getValues().data());

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	auto error = glGetError();

	glBindTexture(GL_TEXTURE_2D, 0);
	assert(GL_NO_ERROR == glGetError());
}

void DepthTextureObject::bind() const
{
	glActiveTexture(GL_TEXTURE0 + id);
	glBindTexture(GL_TEXTURE_2D, texHandle);
}

void DepthTextureObject::unbind() const
{
	glBindTexture(GL_TEXTURE_2D, 0);
	glActiveTexture(GL_TEXTURE0);
}