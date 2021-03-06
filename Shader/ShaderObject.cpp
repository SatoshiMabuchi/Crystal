#include "ShaderObject.h"
//#include "TextureObject.h"

#include <cassert>
#include <stdlib.h>

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

#include "gl/glew.h"

using namespace Crystal::Math;
using namespace Crystal::Shader;

namespace {
	std::string getShaderString() {
		const GLubyte* str = glGetString(GL_RENDERER);
		const GLubyte* vendor = glGetString(GL_VENDOR);
		const GLubyte* glVersion = glGetString(GL_VERSION);
		const GLubyte* glslVersion = glGetString(GL_SHADING_LANGUAGE_VERSION);
		std::stringstream stream;
		stream << str;
		stream << vendor;
		stream << glVersion;
		stream << glslVersion;
		return stream.str();
	}
}

namespace {
	std::string getStrFromFile(const std::string& file)
	{
		std::ifstream stream(file);
		if (stream.fail()) {
			assert(false);
			return "";
		}
		std::istreambuf_iterator<char> it(stream);
		std::istreambuf_iterator<char> last;
		return std::string(it, last);
	}
}


ShaderUnit::ShaderUnit(void) :
	id(-1)
{
}

ShaderUnit::~ShaderUnit(void)
{
	clear();
}

void ShaderUnit::clear()
{
	if (id != -1) {
		glDeleteShader(id);
	}
}

bool ShaderUnit::compile(const std::string& source, const ShaderUnit::Stage stage)
{
	clear();
	if (stage == ShaderUnit::Stage::VERTEX) {
		id = glCreateShader(GL_VERTEX_SHADER);
	}
	else if (stage == ShaderUnit::Stage::FRAGMENT) {
		id = glCreateShader(GL_FRAGMENT_SHADER);
	}
	else if (stage == ShaderUnit::Stage::GEOMETRY) {
		id = glCreateShader(GL_GEOMETRY_SHADER);
	}
	else {
		assert(false);
		return false;
	}
	const GLchar *strPtr[1];
	strPtr[0] = source.c_str();
	glShaderSource(id, 1, strPtr, NULL);

	glCompileShader(id);

	GLint success;
	glGetShaderiv(id, GL_COMPILE_STATUS, &success);
	GLchar infoLog[2048];
	glGetShaderInfoLog(id, 2048, NULL, infoLog);
	log += infoLog;
	//assert( success != 0 );
	//return ( success != 0 );

	if (success == 0) {
		return false;
	}

	if (glGetError() != GL_NO_ERROR) {
		return false;
	}
	return true;
}

bool ShaderUnit::compileFromFile(const std::string& file, const ShaderUnit::Stage stage)
{
	return compile(::getStrFromFile(file), stage);
}

/*
bool ShaderUnit::dump(const std::string& filename)
{
std::ofstream stream(filename);
stream <<
}
*/


ShaderObject::ShaderObject(void) :
	id(-1)
{
}

ShaderObject::ShaderObject(const std::string& vFile, const std::string& fFile) :
	id(-1)
{
	assert(glGetError() == GL_NO_ERROR);
	build(vFile, fFile);
}


ShaderObject::~ShaderObject(void)
{
	clear();
}

void ShaderObject::clear()
{
	glUseProgram(0);
	if (id != -1) {
		glDeleteProgram(id);
	}
}

bool ShaderObject::link(const ShaderUnit& vertexShader, const ShaderUnit& fragmentShader)
{
	clear();

	assert(glGetError() == GL_NO_ERROR);

	id = glCreateProgram();
	glAttachShader(id, vertexShader.getID());
	glAttachShader(id, fragmentShader.getID());

	GLint success;
	glLinkProgram(id);
	glGetProgramiv(id, GL_LINK_STATUS, &success);

	GLchar infoLog[2048];
	glGetProgramInfoLog(id, 2048, NULL, infoLog);
	log += infoLog;

	if (success == 0) {
		return false;
	}

	assert(glGetError() == GL_NO_ERROR);

	return true;
}

bool ShaderObject::link(const ShaderUnit& vertexShader, const ShaderUnit& fragmentShader, const ShaderUnit& geometryShader)
{
	clear();

	assert(glGetError() == GL_NO_ERROR);

	id = glCreateProgram();
	glAttachShader(id, vertexShader.getID());
	glAttachShader(id, fragmentShader.getID());
	glAttachShader(id, geometryShader.getID());

	GLint success;
	glLinkProgram(id);
	glGetProgramiv(id, GL_LINK_STATUS, &success);

	GLchar infoLog[2048];
	glGetProgramInfoLog(id, 2048, NULL, infoLog);
	log += infoLog;

	if (success == 0) {
		return false;
	}

	assert(glGetError() == GL_NO_ERROR);

	return true;
}

bool ShaderObject::build(const std::string& vSource, const std::string& fSource)
{
	ShaderUnit vShader;
	ShaderUnit fShader;

	assert(glGetError() == GL_NO_ERROR);

	if (!vShader.compile(vSource, ShaderUnit::Stage::VERTEX)) {
		log += vShader.getLog();
		return false;
	}
	assert(glGetError() == GL_NO_ERROR);

	if (!fShader.compile(fSource, ShaderUnit::Stage::FRAGMENT)) {
		log += fShader.getLog();
		return false;
	}
	assert(glGetError() == GL_NO_ERROR);

	if (!link(vShader, fShader)) {
		return false;
	}

	return true;
	//positionLocation = glGetUniformLocation( shader.getId(), "position" );
}


bool ShaderObject::build(const std::string& vSource, const std::string& gSource, const std::string& fSource)
{
	ShaderUnit vShader;
	ShaderUnit gShader;
	ShaderUnit fShader;
	if (!vShader.compile(vSource, ShaderUnit::Stage::VERTEX)) {
		log += vShader.getLog();
		return false;
	}
	if (!gShader.compile(gSource, ShaderUnit::Stage::GEOMETRY)) {
		log += gShader.getLog();
		return false;
	}
	if (!fShader.compile(fSource, ShaderUnit::Stage::FRAGMENT)) {
		log += fShader.getLog();
		return false;
	}
	if (!link(vShader, fShader, gShader)) {
		return false;
	}

	return true;
	//positionLocation = glGetUniformLocation( shader.getId(), "position" );
}

bool ShaderObject::buildFromFile(const std::string& vFile, const std::string& fFile)
{
	return build(::getStrFromFile(vFile), ::getStrFromFile(fFile));
}

bool ShaderObject::buildFromFile(const std::string& vFile, const std::string& gFile, const std::string& fFile)
{
	return build(::getStrFromFile(vFile), ::getStrFromFile(gFile), ::getStrFromFile(fFile));
}


void ShaderObject::findUniformLocation(const std::string& str)
{
	const auto location = glGetUniformLocation(id, str.c_str());
	assert(location != -1);
	uniformMap[str] = location;
}


void ShaderObject::findAttribLocation(const std::string& str)
{
	const auto location = glGetAttribLocation(id, str.c_str());
	assert(location != -1);
	attribMap[str] = location;
}

std::vector<IShaderUniform*> ShaderObject::getActiveUniforms()
{
	GLsizei maxLength = 0;
	glGetProgramiv(id, GL_ACTIVE_ATTRIBUTE_MAX_LENGTH, &maxLength);
	int count = 0;
	glGetProgramiv(id, GL_ACTIVE_UNIFORMS, &count);
	GLchar* name = (GLchar*)malloc(maxLength);
	std::vector<IShaderUniform*> uniforms;
	for (auto i = 0; i < count; ++i) {
		GLsizei written;
		GLint size;
		GLenum type;
		glGetActiveUniform(id, i, maxLength, &written, &size, &type, name);
		switch (type) {
		case GL_FLOAT:
			uniforms.push_back(new ShaderUniform1f(name));
			break;
		case GL_FLOAT_VEC2:
			uniforms.push_back(new ShaderUniform2f(name));
			break;
		case GL_FLOAT_VEC3:
			uniforms.push_back(new ShaderUniform3f(name));
			break;
		case GL_FLOAT_VEC4:
			uniforms.push_back(new ShaderUniform4f(name));
			break;
		case GL_INT:
			uniforms.push_back(new ShaderUniform1i(name));
			break;
		case GL_INT_VEC2:
			uniforms.push_back(new ShaderUniform2i(name));
			break;
		case GL_INT_VEC3:
			uniforms.push_back(new ShaderUniform3i(name));
			break;
		case GL_INT_VEC4:
			uniforms.push_back(new ShaderUniform4i(name));
			break;
		case GL_BOOL:
			uniforms.push_back(new ShaderUniform1b(name));
			break;
		case GL_BOOL_VEC2:
			uniforms.push_back(new ShaderUniform2b(name));
			break;
		case GL_BOOL_VEC3:
			uniforms.push_back(new ShaderUniform3b(name));
			break;
		case GL_BOOL_VEC4:
			uniforms.push_back(new ShaderUniform4b(name));
			break;
		case GL_FLOAT_MAT2:
			uniforms.push_back(new ShaderUniformMatrix2d(name));
			break;
		case GL_FLOAT_MAT3:
			uniforms.push_back(new ShaderUniformMatrix3d(name));
			break;
		case GL_FLOAT_MAT4:
			uniforms.push_back(new ShaderUniformMatrix4d(name));
			break;
		case GL_SAMPLER_2D:
			uniforms.push_back(new ShaderUniformSampler2d(name));
			break;
		case GL_SAMPLER_CUBE:
			uniforms.push_back(new ShaderUniformCubeSampler(name));
			break;
		default:
			assert(false);
		}
	}
	free(name);
	return uniforms;
}

std::vector<IShaderAttribute*> ShaderObject::getActiveAttributes()
{
	GLsizei maxLength = 0;
	glGetProgramiv(id, GL_ACTIVE_ATTRIBUTE_MAX_LENGTH, &maxLength);
	int count = 0;
	glGetProgramiv(id, GL_ACTIVE_ATTRIBUTES, &count);
	GLchar* name = (GLchar*)malloc(maxLength);
	std::vector<IShaderAttribute*> attributes;
	for (auto i = 0; i < count; ++i) {
		GLsizei written;
		GLint size;
		GLenum type;
		glGetActiveAttrib(id, i, maxLength, &written, &size, &type, name);
		switch (type) {
		case GL_FLOAT:
			attributes.push_back(new ShaderAttribute1f(name));
			break;
		case GL_FLOAT_VEC2:
			attributes.push_back(new ShaderAttribute2f(name));
			break;
		case GL_FLOAT_VEC3:
			attributes.push_back(new ShaderAttribute3f(name));
			break;
		case GL_FLOAT_VEC4:
			attributes.push_back(new ShaderAttribute4f(name));
			break;
		case GL_FLOAT_MAT2:
			attributes.push_back(new ShaderAttributeMatrix2d(name));
			break;
		case GL_FLOAT_MAT3:
			attributes.push_back(new ShaderAttributeMatrix3d(name));
			break;
		case GL_FLOAT_MAT4:
			attributes.push_back(new ShaderAttributeMatrix4d(name));
			break;
		default:
			assert(false);
		}
	}
	free(name);
	return attributes;
}

unsigned int ShaderObject::getUniformLocation(const std::string& str)
{
	assert(uniformMap.find(str) != uniformMap.end());
	return uniformMap[str];
}

unsigned int ShaderObject::getAttribLocation(const std::string& str)
{
	assert(attribMap.find(str) != attribMap.end());
	return attribMap[str];
}
