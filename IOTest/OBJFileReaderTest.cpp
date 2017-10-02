#include "gtest\gtest.h"
#include "../IO/OBJFileReader.h"

using namespace Crystal::IO;

// from http://www.martinreddy.net/gfx/3d/OBJ.spec
TEST(OBJFileReaderTest, TestExampleSquare)
{
	std::stringstream stream;
	stream
		<< "v 0.000000 2.000000 0.000000" << std::endl
		<< "v 0.000000 0.000000 0.000000" << std::endl
		<< "v 2.000000 0.000000 0.000000" << std::endl
		<< "v 2.000000 2.000000 0.000000" << std::endl
		<< "f 1 2 3 4" << std::endl;
	OBJFileReader reader;
	reader.read(stream);
	EXPECT_EQ(4, reader.getPositions().size());
}

TEST(OBJFileReaderTest, TestExampleCube)
{
	std::stringstream stream;
	stream
		<< "v 0.000000 2.000000 2.000000" << std::endl
		<< "v 0.000000 0.000000 2.000000" << std::endl
		<< "v 2.000000 0.000000 2.000000" << std::endl
		<< "v 2.000000 2.000000 2.000000" << std::endl
		<< "v 0.000000 2.000000 0.000000" << std::endl
		<< "v 0.000000 0.000000 0.000000" << std::endl
		<< "v 2.000000 0.000000 0.000000" << std::endl
		<< "v 2.000000 2.000000 0.000000" << std::endl
		<< "f 1 2 3 4" << std::endl
		<< "f 8 7 6 5" << std::endl
		<< "f 4 3 7 8" << std::endl
		<< "f 5 1 4 8" << std::endl
		<< "f 5 6 2 1" << std::endl
		<< "f 2 6 7 3" << std::endl;

	OBJFileReader reader;
	reader.read(stream);
	EXPECT_EQ(8, reader.getPositions().size());
	EXPECT_EQ(0, reader.getNormals().size());
	EXPECT_EQ(6, reader.getFaces().size());
}

TEST(OBJFileReaderTest, TestNegativeReferenceNumber)
{
	std::stringstream stream;
	stream
		<< "v 0.000000 2.000000 2.000000" << std::endl
		<< "v 0.000000 0.000000 2.000000" << std::endl
		<< "v 2.000000 0.000000 2.000000" << std::endl
		<< "v 2.000000 2.000000 2.000000" << std::endl
		<< "f -4 -3 -2 -1" << std::endl;
	OBJFileReader reader;
	reader.read(stream);
	//EXPECT_EQ(1, file.getGroups().size());
	//EXPECT_EQ(4, file.getGroups().front().getPositions().size());
	//EXPECT_EQ(1, file.getGroups().front().getFaces().size());
	//std::vector<int> expected{ -4, - 3, -2, -1 };
	auto actual = reader.getFaces().size();
	EXPECT_EQ( 1, actual );
}

TEST(OBJFileReaderTest, TestExampleGroups)
{
	std::stringstream stream;
	stream
		<< "v 0.000000 2.000000 2.000000" << std::endl
		<< "v 0.000000 0.000000 2.000000" << std::endl
		<< "v 2.000000 0.000000 2.000000" << std::endl
		<< "v 2.000000 2.000000 2.000000" << std::endl
		<< "v 0.000000 2.000000 0.000000" << std::endl
		<< "v 0.000000 0.000000 0.000000" << std::endl
		<< "v 2.000000 0.000000 0.000000" << std::endl
		<< "v 2.000000 2.000000 0.000000" << std::endl
		<< "# 8 vertices" << std::endl
		<< "g front cube" << std::endl
		<< "f 1 2 3 4" << std::endl
		<< "g back cube" << std::endl
		<< "f 8 7 6 5" << std::endl
		<< "g right cube" << std::endl
		<< "f 4 3 7 8" << std::endl
		<< "g top cube" << std::endl
		<< "f 5 1 4 8" << std::endl
		<< "g left cube" << std::endl
		<< "f 5 6 2 1" << std::endl
		<< "g bottom cube" << std::endl
		<< "f 2 6 7 3" << std::endl
		<< "# 6 elements" << std::endl;

	OBJFileReader reader;
	reader.read(stream);
	EXPECT_EQ(6, reader.getFaces().size());
}

TEST(OBJFileReaderTest, TestExampleSmoothingGroup)
{
	std::stringstream stream;
	stream
		<< "v 0.000000 2.000000 0.000000" << std::endl
		<< "v 0.000000 0.000000 0.000000" << std::endl
		<< "v 2.000000 0.000000 0.000000" << std::endl
		<< "v 2.000000 2.000000 0.000000" << std::endl
		<< "v 4.000000 0.000000 -1.255298" << std::endl
		<< "v 4.000000 2.000000 -1.255298" << std::endl
		<< "# 6 vertices" << std::endl
		<< "g all" << std::endl
		<< "s 1" << std::endl
		<< "f 1 2 3 4" << std::endl
		<< "f 4 3 5 6" << std::endl
		<< "# 2 elements" << std::endl;

	OBJFileReader reader;
	reader.read(stream);
	EXPECT_EQ(2, reader.getFaces().size());
	EXPECT_EQ(6, reader.getPositions().size());
}

TEST(OBJFileReaderTest, TestExampleTextureMappedSquare)
{
	std::stringstream stream;
	stream
		<< "mtllib master.mtl" << std::endl
		<< "v 0.000000 2.000000 0.000000" << std::endl
		<< "v 0.000000 0.000000 0.000000" << std::endl
		<< "v 2.000000 0.000000 0.000000" << std::endl
		<< "v 2.000000 2.000000 0.000000" << std::endl
		<< "vt 0.000000 1.000000 0.000000" << std::endl
		<< "vt 0.000000 0.000000 0.000000" << std::endl
		<< "vt 1.000000 0.000000 0.000000" << std::endl
		<< "vt 1.000000 1.000000 0.000000" << std::endl
		<< "# 4 vertices" << std::endl
		<< "usemtl wood" << std::endl
		<< "f 1/1 2/2 3/3 4/4" << std::endl
		<< "# 1 element" << std::endl;

	OBJFileReader reader;
	reader.read(stream);
	EXPECT_EQ(1, reader.getFaces().size());
	EXPECT_EQ(4, reader.getPositions().size());
	EXPECT_EQ(4, reader.getTexCoords().size());
}
