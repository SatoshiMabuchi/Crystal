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
			ShaderUniform(const std::string& name) :
				name(name)
			{}

			~ShaderUniform() {};

			std::string getName() const { return name; }

			virtual std::string getTypeName() const;

			virtual ShaderType getType() const = 0;

			virtual void render(ShaderObject& shader) = 0;

		private:
			std::string name;
			ShaderType type;
		};

		class ShaderUniformMatrix4d : public ShaderUniform
		{
		public:
			ShaderUniformMatrix4d(const std::string& name) :
				ShaderUniform(name)
			{}

			void render(ShaderObject& shader) override;

			ShaderType getType() const override;

			virtual std::string getTypeName() const;

			void setValue(const std::array<float, 16>& v) { this->value = v; }

		private:
			std::array<float,16> value;
		};
	}
}