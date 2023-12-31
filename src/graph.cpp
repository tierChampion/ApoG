#include "graph.h"

#include <algorithm>
#include <stdexcept>

Graph::Graph()
    : _vertexDimension(0),
      _edgeDimension(0)
{
}

void Graph::addVertex(const Vertex &vert)
{
    _vertices.emplace_back(vert);
    _adjacency[vert] = std::vector<int>();

    _vertexDimension++;
}

void Graph::addEdge(int outgoing, int incoming, bool isUnidirectional)
{
    if ((outgoing < 0 || outgoing >= _vertexDimension) ||
        (incoming < 0 || incoming >= _vertexDimension))
        throw std::runtime_error("Vertices of the edge must be in the graph.");

    _adjacency[_vertices[outgoing]].emplace_back(incoming);

    if (!isUnidirectional)
    {
        _adjacency[_vertices[incoming]].emplace_back(outgoing);
    }

    _edgeDimension++;
}

void Graph::removeEdge(int outgoing, int incoming)
{
    if ((outgoing < 0 || outgoing >= _vertexDimension) ||
        (incoming < 0 || incoming >= _vertexDimension))
        throw std::runtime_error("Vertices of the edge must be in the graph.");

    std::remove(_adjacency[_vertices[outgoing]].begin(), _adjacency[_vertices[outgoing]].end(), incoming);
    std::remove(_adjacency[_vertices[incoming]].begin(), _adjacency[_vertices[incoming]].end(), outgoing);

    _edgeDimension++;
}

std::vector<std::shared_ptr<Vertex>> Graph::getNeighbours(const Vertex &vert) const
{
    std::vector<std::shared_ptr<Vertex>> neighbours = std::vector<std::shared_ptr<Vertex>>();

    for (int i = 0; i < _adjacency.at(vert).size(); i++)
    {
        neighbours.emplace_back(std::make_shared<Vertex>(_vertices[_adjacency.at(vert)[i]]));
    }

    return neighbours;
}

std::ostream &operator<<(std::ostream &os, const Graph &graph)
{
    os << "Graph {" << graph._vertexDimension << ", " << graph._edgeDimension << "}:" << std::endl;

    for (int i = 0; i < graph._vertices.size(); i++)
    {
        os << "\t[" << i << "] " << graph._vertices[i];
        os << " => <";

        for (int j = 0; j < graph._adjacency.at(graph._vertices[i]).size(); j++)
        {
            os << graph._adjacency.at(graph._vertices[i])[j];

            if (j < graph._adjacency.at(graph._vertices[i]).size() - 1)
                os << ", ";
        }

        os << ">" << std::endl;
    }

    return os;
}
