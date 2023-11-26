#pragma once

#include <vector>
#include "vertex.h"

class Graph
{
public:
    Graph();

    void addVertex(const Vertex& vert);

    void addEdge(int outgoing, int incoming, bool isUnidirectional);
    void removeEdge(int outgoing, int incoming, bool isUnidirectional);

    friend std::ostream& operator<<(std::ostream& os, const Graph& graph);

private:
    int _vertexDimension;
    int _edgeDimension;
    std::vector<Vertex> _vertices;
    std::vector<std::vector<int>> _adjacency;
};
