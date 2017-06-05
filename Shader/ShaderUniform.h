#pragma once

#include <string>
#include "GL/glew.h"
#include "ShaderType.h"

#include "../Math/Matrix4d.h"

namespace Crystal {
	namespace Shader {
		class ShaderObject;

		class IShaderUniform
		{
		public:
			IShaderUniform(const std::string& name, const ShaderType& type) :
				name(name),
				type(type)
			{}

			virtual ~IShaderUniform() {};

			std::string getName() const { return name; }

			std::string getTypeName() const { return type.toString(); }

			ShaderType getType() const { return type; }

			virtual void render(ShaderObject& shader) = 0;

		private:
			std::string name;
			ShaderType type;
		};

		class ShaderUniform1f : public IShaderUniform
		{
		public:
			explicit ShaderUniform1f(const std::string& name) :
				IShaderUniform(name, ShaderType(GL_FLOAT))
			{}

			void render(ShaderObject& shader) override;

		private:
			float value;
		};

		class ShaderUniform2f : public IShaderUniform
		{
		public:
			explicit ShaderUniform2f(const std::string& name) :
				IShaderUniform(name, ShaderType(GL_FLOAT_VEC2))
			{}

			void render(ShaderObject& shader) override;

		private:
			std::array<float, 2> value;
		};

		class ShaderUniform3f : public IShaderUniform
		{
		public:
			explicit ShaderUniform3f(const std::string& name) :
				IShaderUniform(name, ShaderType(GL_FLOAT_VEC3))
			{}

			void render(ShaderObject& shader) override;

		private:
			std::array<float, 3> value;
		};

		class ShaderUniform4f : public IShaderUniform
		{
		public:
			explicit ShaderUniform4f(const std::string& name) :
				IShaderUniform(name, ShaderType(GL_FLOAT_VEC4))
			{}

			void render(ShaderObject& shader) override;

		private:
			std::array<float, 4> value;
		};

		class ShaderUniform1i : public IShaderUniform
		{
		public:
			explicit ShaderUniform1i(const std::string& name) :
				IShaderUniform(name, ShaderType(GL_INT))
			{}

			void render(ShaderObject& shader) override;

		private:
			int value;
		};

		class ShaderUniform2i : public IShaderUniform
		{
		public:
			explicit ShaderUniform2i(const std::string& name) :
				IShaderUniform(name, ShaderType(GL_INT_VEC2))
			{}

			void render(ShaderObject& shader) override;

		private:
			std::array<int,2> value;
		};

		class ShaderUniform3i : public IShaderUniform
		{
		public:
			explicit ShaderUniform3i(const std::string& name) :
				IShaderUniform(name, ShaderType(GL_INT_VEC3))
			{}

			void render(ShaderObject& shader) override;

		private:
			std::array<int, 3> value;
		};

		class ShaderUniform4i : public IShaderUniform
		{
		public:
			explicit ShaderUniform4i(const std::string& name) :
				IShaderUniform(name, ShaderType(GL_INT_VEC4))
			{}

			void render(ShaderObject& shader) override;

		private:
			std::array<int, 4> value;
		};


		class ShaderUniformMatrix2d : public IShaderUniform
		{
		public:
			explicit ShaderUniformMatrix2d(const std::string& name) :
				IShaderUniform(name, ShaderType(GL_FLOAT_MAT2))
			{}

			void render(ShaderObject& shader) override;

			void setValue(const std::array<float, 4>& v) { this->value = v; }

		private:
			std::array<float, 4> value;
		};


		class ShaderUniformMatrix3d : public IShaderUniform
		{
		public:
			explicit ShaderUniformMatrix3d(const std::string& name) :
				IShaderUniform(name, ShaderType(GL_FLOAT_MAT3))
			{}

			void render(ShaderObject& shader) override;

			void setValue(const std::array<float, 9>& v) { this->value = v; }

		private:
			std::array<float, 9> value;
		};

		class ShaderUniformMatrix4d : public IShaderUniform
		{
		public:
			explicit ShaderUniformMatrix4d(const std::string& name) :
				IShaderUniform(name, ShaderType(GL_FLOAT_MAT4))
			{}

			void render(ShaderObject& shader) override;

			void setValue(const std::array<float, 16>& v) { this->value = v; }

		private:
			std::array<float,16> value;
		};

		class ShaderUniformSampler2d : public IShaderUniform
		{
		public:
			explicit ShaderUniformSampler2d(const std::string& name) :
				IShaderUniform(name, ShaderType(GL_SAMPLER_2D))
			{}

			void render(ShaderObject& shader) override;

			void setValue(const int id) { this->id = id; }

		private:
			int id;
		};

	}
}