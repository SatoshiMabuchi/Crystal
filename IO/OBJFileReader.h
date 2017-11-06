#ifndef __CRYSTAL_IO_OBJ_FILE_READER_H__
#define __CRYSTAL_IO_OBJ_FILE_READER_H__

#include "../Math/Vector2d.h"
#include "../Math/Vector3d.h"
#include "../Shape/PolygonMesh.h"

namespace Crystal {
	namespace IO {

class OBJFace
{
public:
	std::vector<int> positionIndex;
	std::vector<int> normalIndex;
	std::vector<int> texCoordIndex;
};

class OBJFileReader
{
public:
	OBJFileReader()
	{}

	std::string getComment() const { return comment; }

	bool read(const std::string& filename);

	bool read(std::istream& stream);

	std::vector< Math::Vector3df > getPositions() const { return positions; }

	std::vector< Math::Vector3df > getNormals() const { return normals; }

	std::vector< Math::Vector2df > getTexCoords() const { return texCoords; }

	Shape::PolygonMesh* toPolygonObject();

	std::vector< std::pair< std::string, unsigned int > > getGroups() const { return groups; }

	std::vector< std::string > getMaterialFiles() const { return mtllibs; }

	std::vector< std::pair< std::string, unsigned int > > getMaterials() const { return useMtlNames; }

	//OBJMaterialCollection getMaterials() const { return materialMap; }

	//std::vector<OBJFace> getFaces(const std::string& str) 

	std::vector< OBJFace > getFaces() const { return faces; }

private:
	std::string comment;

	std::vector< Math::Vector3df > positions;
	std::vector< Math::Vector3df > normals;
	std::vector< Math::Vector2df > texCoords;

	std::vector< OBJFace > faces;

	Math::Vector3df readVertices(const std::string& str);

	Math::Vector3df readVector3d(const std::string& str);

	Math::Vector2df readVector2d(const std::string& str);

	//unsigned int readFaces(const std::string& str);

	std::vector< std::pair< std::string, unsigned int > > groups;
	std::vector< std::string > mtllibs;
	std::vector< std::pair< std::string, unsigned int> > useMtlNames;
	//OBJMaterialCollection materialMap;

};

	}
}

#endif