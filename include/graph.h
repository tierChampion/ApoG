#pragma once

#include <vector>
#include "vertex.h"

class Graph
{
public:
    Graph();

    friend std::ostream& operator<<(std::ostream& os, const Graph& graph);

private:
    int _dimension;
    std::vector<Vertex> _vertices;
    std::vector<std::vector<int>> _adjacency;
};
