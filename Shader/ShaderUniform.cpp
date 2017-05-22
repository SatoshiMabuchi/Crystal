#include "ShaderUniform.h"
#include <cassert>

using namespace Crystal::Shader;

std::string ShaderUniform::getTypeName() const
{
	return type.toString();
	/*
	switch (type) {
	case GL_FLOAT:
		return "float";
	case GL_FLOAT_VEC2:
		return "float_vec_2";
	case GL_FLOAT_VEC3:
		return "float_vec_3";
	case GL_FLOAT_VEC4:
		return "float_vec_4";
	case GL_INT:
		return "int";
	case GL_INT_VEC2:
		return "int_vec_2";
	case GL_INT_VEC3:
		return "int_vec_3";
	case GL_INT_VEC4:
		return "int_vec_4";
	case GL_BOOL:
		return "bool";
	case GL_BOOL_VEC2:
		return "bool_vec_2";
	case GL_BOOL_VEC3:
		return "bool_vec_3";
	case GL_BOOL_VEC4:
		return "bool_vec_4";
	case GL_FLOAT_MAT2:
		return "float_mat_2";
	case GL_FLOAT_MAT3:
		return "float_mat_3";
	case GL_FLOAT_MAT4:
		return "float_mat_4";
	case GL_SAMPLER_2D:
		return "sampler_2d";
	case GL_SAMPLER_CUBE:
		return "sampler_cube";
	default:
		assert(false);
		return "";
	}
	*/
}
