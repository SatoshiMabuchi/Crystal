#include "STLBinaryFileWriter.h"

#include <fstream>

using namespace Crystal::Math;
using namespace Crystal::IO;

bool STLBinaryFileWriter::write(const std::string& filename)
{
	std::ofstream stream(filename, std::ios::binary);
	if (stream.is_open()) {
		return false;
	}
	return write(stream);
}

namespace {
	std::array<float, 3> toArrayf(const Vector3dd& v) {
		auto x = (float)(v.x);
		auto y = (float)(v.y);
		auto z = (float)(v.z);
		return { x, y, z };
	}

}

bool STLBinaryFileWriter::write(std::ostream& stream)
{
	const char* head = title.c_str();
	stream.write(head, 80);

	const auto howMany = faces.size();
	stream.write((char *)&howMany, sizeof(unsigned int));

	for (const auto& cell : faces) {
		const auto& normal = toArrayf(cell.getNormal());
		stream.write((char *)&(normal.front()), sizeof(float) * 3);
		const auto& vertices = cell.getVertices();
		for (const auto& pos : vertices) {
			const auto& p = toArrayf(pos);
			stream.write((char *)&(p.front()), sizeof(float) * 3);
		}
		char padding[2];
		padding[0] = '0';
		padding[1] = '0';
		stream.write(padding, sizeof(char) * 2);
	}

	return stream.good();
}