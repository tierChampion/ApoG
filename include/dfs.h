#pragma once

#include <stack>
#include <unordered_map>

#include "traversal.h"

class DfsTraversal : public Traversal
{
public:
    DfsTraversal(const Graph &graph);

    virtual std::vector<Vertex> traverse(const Vertex& start) override;

private:
    std::stack<Vertex> _workStack;
    std::unordered_map<Vertex, bool> _visitedMap;
};

