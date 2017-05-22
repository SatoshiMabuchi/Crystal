#include "ShaderNode.h"
#include "ShaderSlot.h"

#include "../Shader/PointRenderer.h"
#include "../Shader/ShaderObject.h"

using namespace Crystal::Shader;
using namespace Crystal::UI;

namespace {
	std::string getBuildinVertexShaderSource()
	{
		std::ostringstream stream;
		stream
			<< "#version 150" << std::endl
			<< "in vec3 position;" << std::endl
			<< "in int id;" << std::endl
			<< "in float pointSize;" << std::endl
			<< "in vec4 color;" << std::endl
			<< "out vec4 vColor;" << std::endl
			<< "uniform mat4 projectionMatrix;" << std::endl
			<< "uniform mat4 modelviewMatrix;" << std::endl
			<< "void main(void) {" << std::endl
			<< "	gl_Position = projectionMatrix * modelviewMatrix * vec4(position, 1.0);" << std::endl
			<< "	gl_PointSize = pointSize / gl_Position.w;" << std::endl
			<< "	vColor = color;" << std::endl
			<< "}" << std::endl;
		return stream.str();
	}

	std::string getBuildinFragmentShaderSource()
	{
		std::ostringstream stream;
		stream
			<< "#version 150" << std::endl
			<< "in vec4 vColor;" << std::endl
			<< "out vec4 fragColor;" << std::endl
			<< "void main(void) {" << std::endl
			<< "	vec2 coord = gl_PointCoord * 2.0 - 1.0;" << std::endl
			<< "	float distSquared = 1.0 - dot(coord, coord);" << std::endl
			<< "	if (distSquared < 0.0) {" << std::endl
			<< "		discard;" << std::endl
			<< "	}" << std::endl
			<< "	fragColor.rgba = vColor;" << std::endl
			<< "	fragColor.a = sqrt(distSquared) * vColor.a;" << std::endl
			<< "	fragColor.a = 0.1;//sqrt(distSquared);" << std::endl
			<< "}" << std::endl;
		return stream.str();
	}
}


void ShaderNode::build()
{
	const auto vsSource = getBuildinVertexShaderSource();
	const auto fsSource = getBuildinFragmentShaderSource();
	bool b = shader.build(vsSource, fsSource);
	const auto& uniforms = shader.getActiveUniforms();
	for (const auto u : uniforms) {
		createInputSlot(u.getTypeName());
	}
	const auto& attrs = shader.getActiveAttributes();
	for (const auto a : attrs) {
		createInputSlot(a.getTypeName());
	}
	//shader.getActiveAttributes();
}

ShaderInputSlot* ShaderNode::createInputSlot(const std::string& name)
{
	auto slot = new ShaderInputSlot(name, this, inputSlots.size());
	std::cout << name << std::endl;
	inputSlots.push_back(slot);
	return slot;
}

ShaderOutputSlot* ShaderNode::createOutputSlot()
{
	auto slot = new ShaderOutputSlot(this, outputSlots.size());
	outputSlots.push_back(slot);
	return slot;
}

void ShaderNode::clear() {
	for (auto s : inputSlots) {
		delete s;
	}
	inputSlots.clear();
	for (auto s : outputSlots) {
		delete s;
	}
	outputSlots.clear();
}

