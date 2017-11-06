#include "gtest/gtest.h"

#include "../Math/Vector3d.h"
#include "../IO/STLAsciiFileReader.h"

using namespace Crystal::Math;
using namespace Crystal::IO;

using T = float;

namespace {
	std::stringstream getSampleAscii() {
		std::stringstream stream;
		stream
			<< "solid cube-ascii" << std::endl
			<< "facet normal  0.0  0.0 1.0" << std::endl
			<< "	outer loop" << std::endl
			<< "		vertex  0.0  0.0  1.0" << std::endl
			<< "		vertex  1.0  0.0  1.0" << std::endl
			<< "		vertex  0.0  1.0  1.0" << std::endl
			<< "endloop" << std::endl
			<< "endfacet" << std::endl
			<< "facet normal 0.0 0.0 1.0" << std::endl
			<< "	outer loop" << std::endl
			<< "		vertex  1.0  1.0  1.0" << std::endl
			<< "		vertex  0.0  1.0  1.0" << std::endl
			<< "		vertex  1.0  0.0  1.0" << std::endl
			<< "	endloop" << std::endl
			<< "endfacet" << std::endl
			<< "endsolid" << std::endl;
		return stream;
	}
}

TEST(STLAsciiFileReaderTest, TestReadAscii)
{
	std::stringstream stream = getSampleAscii();

	STLAsciiFileReader reader;
	EXPECT_TRUE(reader.read(stream));
	const auto& faces = reader.getFaces();

	EXPECT_EQ(2, faces.size());

	const auto& face1 = faces[0];
	EXPECT_EQ( Vector3dd(0,0,1), face1.getNormal() );
	EXPECT_EQ( Vector3dd(0,0,1), face1.getVertices()[0]);
	EXPECT_EQ( Vector3dd(1,0,1), face1.getVertices()[1]);
	EXPECT_EQ( Vector3dd(0,1,1), face1.getVertices()[2]);

	const auto& face2 = faces[1];
	EXPECT_EQ( Vector3dd(0,0,1), face2.getNormal());
	EXPECT_EQ( Vector3dd(1,1,1), face2.getVertices()[0]);
	EXPECT_EQ( Vector3dd(0,1,1), face2.getVertices()[1]);
	EXPECT_EQ( Vector3dd(1,0,1), face2.getVertices()[2]);

	/*
	const Vector3dd normal2(0.0, 0.0, 1.0);
	const std::vector< Vector3dd > positions2 = {
		Vector3dd(1.0, 1.0, 1.0),
		Vector3dd(0.0, 1.0, 1.0),
		Vector3dd(1.0, 0.0, 1.0)
	};
	STLFile expected(cells, " cube-ascii");
	EXPECT_EQ(expected, file);
	*/
}
