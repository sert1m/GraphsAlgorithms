#ifndef GRPAH_EDGE_H_
#define GRPAH_EDGE_H_

#include <stdint.h>

namespace graphs {

typedef int32_t Vertex;

class Edge {
public:
	Edge(Vertex v, Vertex w, int32_t weight = 0);
	Edge(const Edge& edge);
	virtual ~Edge()=0;

	Vertex either() const { return v;}
	Vertex other(Vertex vertex) const;

	int32_t weigth() const {return weight;}

	bool operator==(const Edge &edge) const;
protected:
	Vertex v;
	Vertex w;
	int32_t weight;
};

class UndirectedEdge : public Edge {
public:
	UndirectedEdge(Vertex v, Vertex w, Vertex weight = 0) : Edge(v, w, weight) {};
	virtual ~UndirectedEdge() {};
};

class DirectedEdge : public Edge {
public:
	DirectedEdge(Vertex v, Vertex w, Vertex weight = 0) : Edge(v, w, weight) {};
	virtual ~DirectedEdge();

	Vertex from() const { return v; }
	Vertex to() const { return w; }
};
} /* namespace graphs */

#endif /* GRPAH_EDGE_H_ */
