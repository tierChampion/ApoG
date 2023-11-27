#pragma once

#include <vector>
#include <map>
#include <memory>

#include "vertex.h"

class Graph
{
public:
    Graph();

    void addVertex(const Vertex& vert);

    void addEdge(int outgoing, int incoming, bool isUnidirectional);
    void removeEdge(int outgoing, int incoming);

    std::vector<std::shared_ptr<Vertex>> getNeighbours(const Vertex& vert) const;

    friend std::ostream& operator<<(std::ostream& os, const Graph& graph);

private:
    int _vertexDimension;
    int _edgeDimension;
    std::vector<Vertex> _vertices;
    std::map<uint64_t, std::vector<int>> _adjacency;
};
