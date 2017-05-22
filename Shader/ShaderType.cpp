#include "ShaderType.h"
#include <cassert>

using namespace Crystal::Shader;

std::string ShaderType::toString(const GLenum e)
{
	switch (e) {
	case GL_FLOAT:
		return "float";
	case GL_FLOAT_VEC2:
		return "float_vec2";
	case GL_FLOAT_VEC3:
		return "float_vec3";
	case GL_FLOAT_VEC4:
		return "float_vec4";
	case GL_FLOAT_MAT2:
		return "float_mat2";
	case GL_FLOAT_MAT3:
		return "float_mat3";
	case GL_FLOAT_MAT4:
		return "float_mat4";
	case GL_FLOAT_MAT2x3 :
		return "float_mat2x3";
	case GL_FLOAT_MAT2x4 :
		return "float_mat2x4";
	case GL_FLOAT_MAT3x2 :
		return "float_mat3x2";
	case GL_FLOAT_MAT3x4 :
		return "float_mat3x4";
	case GL_FLOAT_MAT4x2 :
		return "float_mat4x2";
	case GL_FLOAT_MAT4x3 :
		return "float_mat4x3";
	case GL_INT:
		return "int";
	case GL_INT_VEC2:
		return "int_vec2";
	case GL_INT_VEC3:
		return "int_vec3";
	case GL_INT_VEC4:
		return "int_vec4";
	case GL_UNSIGNED_INT:
		return "unsigned_int";
	case GL_UNSIGNED_INT_VEC2:
		return "unsigned_int_vec2";
	case GL_UNSIGNED_INT_VEC3:
		return "unsigned_int_vec3";
	case GL_UNSIGNED_INT_VEC4:
		return "unsigned_int_vec4";
	case GL_DOUBLE:
		return "double";
	case GL_DOUBLE_VEC2:
		return "double_vec2";
	case GL_DOUBLE_VEC3:
		return "double_vec3";
	case GL_DOUBLE_VEC4:
		return "double_vec4";
	case GL_DOUBLE_MAT2:
		return "double_mat2";
	case GL_DOUBLE_MAT3:
		return "double_mat3";
	case GL_DOUBLE_MAT4:
	case GL_DOUBLE_MAT2x3:
	case GL_DOUBLE_MAT2x4:
	case GL_DOUBLE_MAT3x2:
	case GL_DOUBLE_MAT3x4:
	case GL_DOUBLE_MAT4x2:
	case GL_DOUBLE_MAT4x3:
	case GL_BOOL:
		return "bool";
	case GL_BOOL_VEC2:
		return "bool_vec_2";
	case GL_BOOL_VEC3:
		return "bool_vec_3";
	case GL_BOOL_VEC4:
		return "bool_vec_4";
	case GL_SAMPLER_2D:
		return "sampler_2d";
	case GL_SAMPLER_CUBE:
		return "sampler_cube";
	default:
		assert(false);
		return "";
	}
}