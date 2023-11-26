#include "graph.h"

Graph::Graph()
    : _dimension(0),
      _vertices(),
      _adjacency()
{
}

void Graph::addVertex(const Vertex &vert)
{
    _vertices.emplace_back(vert);
    _adjacency.emplace_back(std::vector<int>());

    _dimension++;
}

void Graph::addEdge(int outgoing, int incoming, bool isUnidirectional)
{
    _adjacency[outgoing].emplace_back(incoming);

    if (!isUnidirectional)
    {
        _adjacency[incoming].emplace_back(outgoing);
    }
}

std::ostream &operator<<(std::ostream &os, const Graph &graph)
{
    os << "Graph:" << std::endl;

    for (int i = 0; i < graph._vertices.size(); i++)
    {
        os << "\t[" << i << "] " << graph._vertices[i];
        os << " => <";

        for (int j = 0; j < graph._adjacency[i].size(); j++)
        {
            os << graph._adjacency[i][j];

            if (j < graph._adjacency[i].size() - 1)
                os << ", ";
        }

        os << ">" << std::endl;
    }

    return os;
}
