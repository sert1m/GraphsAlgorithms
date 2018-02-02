#include <stdexcept>

#include "Graph/Edge.h"

namespace graphs {

Edge::Edge(Vertex v, Vertex w, int32_t weight) : v(v), w(w), weight(0) {

}
Edge::Edge(const Edge& edge) : v(edge.v), w(edge.w), weight(edge.weight) {

}

Vertex Edge::other(int32_t vertex) const {
	if (vertex == v) return w;
	else if (vertex == w)return v;

	throw std::invalid_argument("Invalid vertex");
}

bool Edge::operator==(const Edge &edge) const {
	return edge.v == v && edge.w == w && edge.weight == weight;
}

}


