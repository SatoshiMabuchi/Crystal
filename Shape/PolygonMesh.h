#ifndef __CRYSTAL_SHAPE_POLYGON_MESH_H__
#define __CRYSTAL_SHAPE_POLYGON_MESH_H__

#include "../Util/UnCopyable.h"
#include "Vertex.h"
#include "Face.h"
#include "../Math/Quaternion.h"

#include <list>

namespace Crystal {
	namespace Shape {

class Vertex;
class Face;

class PolygonMesh : private UnCopyable
{
public:
	PolygonMesh()
	{}

	PolygonMesh(const std::list<Face*>& faces);

	~PolygonMesh();

	std::list<Face*> getFaces() const { return faces; }

	std::list<Vertex*> getVertices() const;

	std::list<HalfEdge*> getEdges() const;

	void clear();

	void add(Face* f);

	bool has(Face* f);

	bool has(HalfEdge* e);

	bool has(Vertex* v);

	void remove(Face* f);

	PolygonMesh* clone();

	HalfEdge* getShortestEdge();

	void mergeDouble(PolygonMesh* rhs, float distance);

	Math::Vector3df getCenter() const;

	void move(const Math::Vector3df& v);

	//void scale(const Math::Vector3df& s);

	//void rotate(const Math::Quaternion<float>& quaternion);

	void merge(PolygonMesh& rhs);

	void reverse();

	std::list<Vertex*> findInnerVertices();

	std::list<Vertex*> findBoundaryVertices();

	std::list<HalfEdge*> findBoundaryEdges();

	void updateNormals();

private:
	std::list<Face*> faces;
};

	}
}

#endif