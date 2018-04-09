#include "stdafx.h"
#include "SmoothRenderer.h"
#include "../Graphics/Material.h"
#include <sstream>

#include "ITextureObject.h"

using namespace Crystal::Graphics;
using namespace Crystal::Shader;

bool SmoothRenderer::build()
{
	const auto& vShader = getBuildinVertexShaderSource();
	const auto& fShader = getBuildinFragmentShaderSource();

	bool result = shader.build(vShader, fShader);
	findLocation();

	return result;
}

std::string SmoothRenderer::getBuildinVertexShaderSource() const
{
	std::ostringstream stream;
	stream
		<< "#version 150" << std::endl
		<< "in vec3 position;" << std::endl
		<< "in vec3 normal;" << std::endl
		<< "in vec3 texCoord;" << std::endl
		<< "out vec3 vNormal;" << std::endl
		<< "out vec3 vPosition;" << std::endl
		<< "out vec3 vTexCoord;" << std::endl
		<< "uniform mat4 projectionMatrix;"
		<< "uniform mat4 modelviewMatrix;"
		<< "void main(void) {" << std::endl
		<< "	gl_Position = projectionMatrix * modelviewMatrix * vec4(position, 1.0);" << std::endl
		<< "	vNormal = normalize(normal);" << std::endl
		<< "	vPosition = position;" << std::endl
		<< "	vTexCoord = texCoord;" << std::endl
		<< "}" << std::endl;
	return stream.str();
}

std::string SmoothRenderer::getBuildinFragmentShaderSource() const
{
	std::ostringstream stream;
	stream
		<< "#version 150" << std::endl
		<< "in vec3 vNormal;" << std::endl
		<< "in vec3 vPosition;" << std::endl
		<< "in vec3 vTexCoord;" << std::endl
		<< "out vec4 fragColor;" << std::endl
		<< "uniform vec3 eyePosition;" << std::endl
		<< "struct LightInfo {" << std::endl
		<< "	vec3 position;" << std::endl
		<< "	vec3 La;" << std::endl
		<< "	vec3 Ld;" << std::endl
		<< "	vec3 Ls;" << std::endl
		<< "};"
		<< "uniform LightInfo light;"
		<< "struct MaterialInfo {" << std::endl
		<< "	vec3 Ka;" << std::endl
		<< "	vec3 Kd;" << std::endl
		<< "	vec3 Ks;" << std::endl
		<< "	float shininess;" << std::endl
		<< "};"
		<< "uniform MaterialInfo material;"
		<< "vec3 getPhongShadedColor( vec3 position, vec3 normal) {"
		<< "	vec3 s = normalize(light.position - vPosition);" << std::endl
		<< "	vec3 v = normalize(vPosition - eyePosition);" << std::endl
		<< "	vec3 r = reflect( -s, normal );" << std::endl
		<< "	vec3 ambient = light.La * material.Ka;" << std::endl
		<< "	float innerProduct = max( dot(s,normal), 0.0);" << std::endl
		<< "	vec3 diffuse = light.Ld * material.Kd * innerProduct;" << std::endl
		<< "	vec3 specular = vec3(0.0);" << std::endl
		<< "	if(innerProduct > 0.0) {" << std::endl
		<< "		specular = light.Ls * material.Ks * pow( max( dot(r,v), 0.0 ), material.shininess );" << std::endl
		<< "	}" << std::endl
		<< "	return ambient + diffuse + specular;" << std::endl
		<< "}"
		<< "void main(void) {" << std::endl
		<< "	fragColor.rgb = getPhongShadedColor( eyePosition, vNormal);" << std::endl
		<< "	fragColor.a = 1.0;" << std::endl
		<< "}" << std::endl;
	return stream.str();
}


void SmoothRenderer::findLocation()
{
	shader.findUniformLocation("projectionMatrix");
	shader.findUniformLocation("modelviewMatrix");
	shader.findUniformLocation("eyePosition");
	shader.findUniformLocation("light.position");
	shader.findUniformLocation("light.La");
	shader.findUniformLocation("light.Ld");
	shader.findUniformLocation("light.Ls");
	shader.findUniformLocation("material.Ka");
	shader.findUniformLocation("material.Kd");
	shader.findUniformLocation("material.Ks");
	shader.findUniformLocation("material.shininess");

	shader.findAttribLocation("position");
	shader.findAttribLocation("normal");
	//shader.findAttribLocation("texCoord");
}


void SmoothRenderer::render(const ICamera& camera, const PointLight& light)
{
	const auto& positions = buffer.getPositions().get();// buffers[0].get();
	const auto& normals = buffer.getNormals().get();//buffers[1].get();
	const auto& texCoords = buffer.getTexCoords().get();
	if (positions.empty()) {
		return;
	}

	glEnable(GL_DEPTH_TEST);

	const auto& projectionMatrix = camera.getProjectionMatrix();
	const auto& modelviewMatrix = camera.getModelviewMatrix();
	const auto& eyePos = camera.getPosition();

	assert(GL_NO_ERROR == glGetError());

	glUseProgram(shader.getId());

	const auto& lightPos = light.getPos();//{ -10.0f, 10.0f, 10.0f };

	glUniform3fv(shader.getUniformLocation("light.position"), 1, &light.getPos()[0]);
	glUniform3fv(shader.getUniformLocation("light.La"), 1, &light.getAmbient()[0]);
	glUniform3fv(shader.getUniformLocation("light.Ld"), 1, &light.getDiffuse()[0]);
	glUniform3fv(shader.getUniformLocation("light.Ls"), 1, &light.getSpecular()[0]);

	glBindFragDataLocation(shader.getId(), 0, "fragColor");

	glUniformMatrix4fv(shader.getUniformLocation("projectionMatrix"), 1, GL_FALSE, &projectionMatrix[0][0]);
	glUniformMatrix4fv(shader.getUniformLocation("modelviewMatrix"), 1, GL_FALSE, &modelviewMatrix[0][0]);
	glUniform3fv(shader.getUniformLocation("eyePosition"), 1, &eyePos[0]);

	assert(GL_NO_ERROR == glGetError());

	glVertexAttribPointer(shader.getAttribLocation("position"), 3, GL_FLOAT, GL_FALSE, 0, positions.data());
	glVertexAttribPointer(shader.getAttribLocation("normal"), 3, GL_FLOAT, GL_FALSE, 0, normals.data());
	//glVertexAttribPointer(shader.getAttribLocation("texCoord"), 3, GL_FLOAT, GL_FALSE, 0, texCoords.data());

	//glVertexAttribPointer(location.)
	assert(GL_NO_ERROR == glGetError());

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);
	assert(GL_NO_ERROR == glGetError());


	//glDrawArrays(GL_TRIANGLES, 0, static_cast<GLsizei>(positions.size() / 3));
	//glDrawElements(GL_TRIANGLES, static_cast<GLsizei>( indices.size()), GL_UNSIGNED_INT, indices.data());
	for (const auto& b : buffer.getBlocks()) {
		const auto& indices = b.getIndices();
		const auto m = b.getMaterial();
		const auto a = m.getAmbient();
		glUniform3fv(shader.getUniformLocation("material.Ka"), 1, &a[0]);
		glDrawElements(GL_TRIANGLES, static_cast<GLsizei>(indices.size()), GL_UNSIGNED_INT, indices.data());
	}


	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(2);


	glUseProgram(0);

	const GLenum error = glGetError();
	assert(GL_NO_ERROR == error);

	glDisable(GL_DEPTH_TEST);
}
