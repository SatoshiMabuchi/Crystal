#include "gtest/gtest.h"

#include "../IO/DXFFileReader.h"

using namespace Crystal::IO;

TEST(DXFFileTest, TestRead)
{
	std::stringstream stream;
	DXFFileReader reader;
	stream << "0" << std::endl;
	stream << "SECTION" << std::endl;
	stream << "2" << std::endl;
	stream << "ENTITIES" << std::endl;
	stream << "0" << std::endl;
	stream << "ENDSEC" << std::endl;
	stream << "0" << std::endl;
	stream << "EOF" << std::endl;

	EXPECT_TRUE( reader.read(stream) );
}
