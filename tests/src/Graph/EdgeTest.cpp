#include <gtest/gtest.h>
#include "Graph/Edge.h"

using namespace graphs;

TEST(UndirectedEdge, Simple) {
	UndirectedEdge edge(1, 2, 3);

	ASSERT_EQ(1, edge.either());
	ASSERT_EQ(2, edge.other(edge.either()));
	ASSERT_EQ(3, edge.weigth());
}

TEST(UndirectedEdge, DefaultWeight) {
	UndirectedEdge edge(3, 4);

	ASSERT_EQ(3, edge.either());
	ASSERT_EQ(4, edge.other(edge.either()));
	ASSERT_EQ(0, edge.weigth());
}

TEST(UndirectedEdge, Compare) {
	UndirectedEdge edge1(1, 2, 3);
	UndirectedEdge edge2(1, 2, 3);

	ASSERT_EQ(edge1, edge2);
}

TEST(UndirectedEdge, CopyConstructor) {
	UndirectedEdge edge1(1, 2, 3);
	UndirectedEdge edge2(edge1);

	ASSERT_EQ(edge1, edge2);
}

TEST(DirectedEdge, Simple) {
	DirectedEdge edge(1, 2, 3);

	ASSERT_EQ(1, edge.to());
	ASSERT_EQ(2, edge.from());
	ASSERT_EQ(3, edge.weigth());
}

