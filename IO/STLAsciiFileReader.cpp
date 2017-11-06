#include "STLAsciiFileReader.h"

#include "Helper.h"

using namespace Crystal::Math;
using namespace Crystal::Shape;
using namespace Crystal::IO;

bool STLAsciiFileReader::read(const std::string& filename)
{
	std::ifstream stream(filename);
	if (!stream.is_open()) {
		return false;
	}
	return read(stream);
}

bool STLAsciiFileReader::read(std::istream& stream)
{
	std::string str = Helper::read<std::string>(stream);

	if (str != "solid") {
		return false;
	}

	std::getline(stream, str);

	this->title = str;

	str = Helper::read<std::string>(stream);
	while (str != "endsolid") {
		if (str != "facet") {
			return false;
		}
		str = Helper::read<std::string>(stream);
		if (str != "normal") {
			return false;
		}

		const auto& normal = Helper::readVector<double>(stream);

		stream >> str;
		if (str != "outer") {
			return false;
		}

		stream >> str;
		if (str != "loop") {
			return false;
		}

		std::array<Vector3dd, 3> vertices;
		for (int i = 0; i < 3; ++i) {
			stream >> str;
			if (str != "vertex") {
				return false;
			}

			vertices[i] = Helper::readVector<double>(stream);
		}

		faces.push_back(TriangleFace(vertices, normal));

		str = Helper::read<std::string>(stream);
		if (str != "endloop") {
			return false;
		}

		str = Helper::read<std::string>(stream);
		if (str != "endfacet") {
			return false;
		}

		str = Helper::read<std::string>(stream);
	}

	return stream.good();
}
