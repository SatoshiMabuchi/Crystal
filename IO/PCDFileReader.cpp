#include "PCDFileReader.h"
#include <fstream>
#include <sstream>
#include <vector>

using namespace Crystal::IO;

namespace {
	std::vector<std::string> split(const std::string& input, char delimiter)
	{
		std::istringstream stream(input);

		std::string field;
		std::vector<std::string> result;
		while (std::getline(stream, field, delimiter)) {
			result.push_back(field);
		}
		return result;
	}
}

bool PCDFileReader::read(const std::string& filename)
{
	std::ifstream stream(filename);
	if (!stream.is_open()) {
		return false;
	}
	return read(stream);
}

bool PCDFileReader::read(std::istream& stream)
{
	std::string str;
	//while (std::getline(stream, str)) {
	//	str << 
	//}
	return false;
}
