#include "graph.h"

Graph::Graph()
    : _dimension(0),
      _vertices(),
      _adjacency()
{
}

std::ostream &operator<<(std::ostream &os, const Graph &graph)
{
    for (const Vertex &vert : graph._vertices)
    {
        os << vert;
        os << std::endl;
    }

    return os;
}
