#pragma once

#include <string>
#include "GL/glew.h"
#include "ShaderType.h"

#include "../Math/Matrix4d.h"

namespace Crystal {
	namespace Shader {
		class ShaderObject;

		class ShaderUniform
		{
		public:
			ShaderUniform(const std::string& name, const ShaderType& type) :
				name(name),
				type(type)
			{}

			~ShaderUniform() {};

			std::string getName() const { return name; }

			std::string getTypeName() const { return type.toString(); }

			ShaderType getType() const { return type; }

			virtual void render(ShaderObject& shader) = 0;

		private:
			std::string name;
			ShaderType type;
		};

		class ShaderUniform1f : public ShaderUniform
		{
		public:
			explicit ShaderUniform1f(const std::string& name) :
				ShaderUniform(name, ShaderType(GL_FLOAT))
			{}

			void render(ShaderObject& shader) override {};
		};

		class ShaderUniform2f : public ShaderUniform
		{
		public:
			explicit ShaderUniform2f(const std::string& name) :
				ShaderUniform(name, ShaderType(GL_FLOAT_VEC2))
			{}

			void render(ShaderObject& shader) override {};
		};

		class ShaderUniform3f : public ShaderUniform
		{
		public:
			explicit ShaderUniform3f(const std::string& name) :
				ShaderUniform(name, ShaderType(GL_FLOAT_VEC3))
			{}

			void render(ShaderObject& shader) override {};
		};

		class ShaderUniform4f : public ShaderUniform
		{
		public:
			explicit ShaderUniform4f(const std::string& name) :
				ShaderUniform(name, ShaderType(GL_FLOAT_VEC4))
			{}

			void render(ShaderObject& shader) override {};
		};

		class ShaderUniformMatrix4d : public ShaderUniform
		{
		public:
			explicit ShaderUniformMatrix4d(const std::string& name) :
				ShaderUniform(name, ShaderType(GL_FLOAT_MAT4))
			{}

			void render(ShaderObject& shader) override;

			void setValue(const std::array<float, 16>& v) { this->value = v; }

		private:
			std::array<float,16> value;
		};
	}
}