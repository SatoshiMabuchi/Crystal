#include "DXFFileReader.h"

#include <iostream>
#include <string>
#include <fstream>

using namespace Crystal::Math;
using namespace Crystal::IO;

bool DXFFileReader::read(const std::string& filename)
{
	std::ifstream stream(filename);
	if (!stream.is_open()) {
		return false;
	}
	return read(stream);
}

bool DXFFileReader::read(std::istream& stream)
{
	std::string str;
	std::getline(stream, str);
	const int is0 = std::stoi(str);
	assert(is0 == 0);

	std::getline(stream, str);
	assert(str == "SECTION");

	std::getline(stream, str);
	const int is2 = std::stoi(str);
	assert(is2 == 2);

	std::getline(stream, str);
	assert(str == "ENTITIES");

	while (str != "EOF") {
		DXFFace f;
		std::getline(stream, str);
		std::vector<Vector3d<float>> positions;
		Vector3d<float> pos;
		if (str == "0") {
			std::getline(stream, str);
			if (str == "3DFACE") {
				;
			}
		}
		else if (str == "8") {
			std::getline(stream, str);
			f.setLayerName(str);
		}
		else if (str == "10") {
			std::getline(stream, str);
			pos.setX(std::stof(str));
		}
		else if (str == "20") {
			std::getline(stream, str);
			pos.setY(std::stof(str));
		}
		else if (str == "30") {
			std::getline(stream, str);
			pos.setZ(std::stof(str));
			positions.push_back(pos);
		}
	}
	return true;
}