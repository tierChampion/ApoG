#pragma once

#include "graph.h"

class Traversal
{

public:
    Traversal(const Graph &graph) : _graph(graph) {}

    virtual std::vector<Vertex> traverse(const Vertex& start) = 0;

protected:
    Graph _graph;
};
