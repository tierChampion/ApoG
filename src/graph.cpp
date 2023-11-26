#include "graph.h"

#include <algorithm>
#include <stdexcept>

Graph::Graph()
    : _vertexDimension(0),
      _edgeDimension(0),
      _vertices(),
      _adjacency()
{
}

void Graph::addVertex(const Vertex &vert)
{
    _vertices.emplace_back(vert);
    _adjacency.emplace_back(std::vector<int>());

    _vertexDimension++;
}

void Graph::addEdge(int outgoing, int incoming, bool isUnidirectional)
{
    if ((outgoing < 0 || outgoing >= _vertexDimension) ||
        (incoming < 0 || incoming >= _vertexDimension))
        throw std::runtime_error("Vertices of the edge must be in the graph.");

    _adjacency[outgoing].emplace_back(incoming);

    if (!isUnidirectional)
    {
        _adjacency[incoming].emplace_back(outgoing);
    }

    _edgeDimension++;
}

void Graph::removeEdge(int outgoing, int incoming, bool isUnidirectional)
{
    if ((outgoing < 0 || outgoing >= _vertexDimension) ||
        (incoming < 0 || incoming >= _vertexDimension))
        throw std::runtime_error("Vertices of the edge must be in the graph.");

    std::remove(_adjacency[outgoing].begin(), _adjacency[outgoing].end(), incoming);
    std::remove(_adjacency[incoming].begin(), _adjacency[incoming].end(), outgoing);

    _edgeDimension++;
}

std::ostream &operator<<(std::ostream &os, const Graph &graph)
{
    os << "Graph {" << graph._vertexDimension << ", " << graph._edgeDimension << "}:" << std::endl;

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
