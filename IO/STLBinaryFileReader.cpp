#include "STLBinaryFileReader.h"

#include <cassert>

using namespace Crystal::Math;
using namespace Crystal::Shape;
using namespace Crystal::IO;

bool STLBinaryFileReader::read(const std::string& filename)
{
	std::ifstream stream(filename, std::ios::binary);
	if (!stream.is_open()) {
		return false;
	}
	return read(stream);
}

bool STLBinaryFileReader::read(std::istream& stream)
{
	char head[80];
	stream.read(head, 80);

	unsigned int howMany;
	stream.read((char *)&howMany, sizeof(unsigned int));

	for (size_t i = 0; i < howMany; ++i) {
		float normal[3];
		stream.read((char *)&normal, sizeof(float) * 3);
		float pos0[3];
		stream.read((char *)&pos0, sizeof(float) * 3);
		float pos1[3];
		stream.read((char *)&pos1, sizeof(float) * 3);
		float pos2[3];
		stream.read((char *)&pos2, sizeof(float) * 3);
		char padding[2];
		stream.read((char *)padding, sizeof(char) * 2);

		if (!stream.good()) {
			assert(false);
		}

		Vector3dd fn(normal[0], normal[1], normal[2]);
		std::array< Vector3dd, 3 > vertices = {
			Vector3dd(pos0[0], pos0[1], pos0[2]),
			Vector3dd(pos1[0], pos1[1], pos1[2]),
			Vector3dd(pos2[0], pos2[1], pos2[2]),
		};
		TriangleFace face(vertices, fn);
		faces.push_back(face);
	}
	return stream.good();
}
