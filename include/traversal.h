#pragma once

#include "graph.h"

class Traversal
{
public:
    Traversal(const Graph &graph)
        : _graph(graph)
    {
    }

    virtual void traverse(const Vertex &start) = 0;

    std::vector<Vertex>::iterator begin() { return _traversal.begin(); }
    std::vector<Vertex>::iterator end() { return _traversal.end(); }

protected:
    const Graph _graph;
    std::vector<Vertex> _traversal;
};
