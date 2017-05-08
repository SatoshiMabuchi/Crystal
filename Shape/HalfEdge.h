#ifndef __CRYSTAL_SHAPE_HALF_EDGE_H__
#define __CRYSTAL_SHAPE_HALF_EDGE_H__

#include "../Util/UnCopyable.h"
#include "../Math/Vector3d.h"

namespace Crystal {
	namespace Shape {

class Vertex;
class Face;
class Edge;

class HalfEdge
{
public:
	HalfEdge(Vertex* start, Vertex* end, int id = -1);

	int getId() const { return id; }

	Math::Vector3d<float> getVector() const;

	float getLength() const;

	Vertex* getStart() const { return start; }

	Vertex* getEnd() const { return end; }

	void changeStart(Vertex* n) { this->start = n; }

	void changeEnd(Vertex* n) { this->end = n; }

	//Math::Point3d<float> getMidPoint() const;

	//Math::Line3d<float> toLine() const;

	void setId(const int id) { this->id = id; }

	HalfEdge* createReverse(const int id) const;

	bool isReverse(const HalfEdge& rhs) const;

	//void move(const Math::Vector3d<float>& v);

	bool isShared(const HalfEdge& rhs) const;

	bool isSame(const HalfEdge& rhs) const;

	void connect(HalfEdge* next);

	HalfEdge* getNext() const { return next; }

	HalfEdge* getPrev() const { return prev; }

	bool isCollapsed() const;

	void setFace(Face* f) { this->face = f; }

	Face* getFace() { return face; }

	bool isIsolated() const;

	float calculateCollapseCost() const;

	bool isDegenerated() const;

	bool isDegenerated(const float length) const;

	void toDenerate();

	bool has(Vertex* e);

	//Math::Line3d<float> getCurve() const;

	void reverse();

	HalfEdge* split(Vertex* v);

	HalfEdge* clone(const int id) const;

	void setPair(HalfEdge* pair);

	HalfEdge* getPair() const;

	int getHashKey() const;

	//float getEndAngle() const;

	bool isInner() const;

	bool isBoundary() const;

private:
	Vertex* start;
	Vertex* end;
	Face* face;
	HalfEdge* prev;
	HalfEdge* next;
	HalfEdge* pair;
	int id;
};


	}
}

#endif