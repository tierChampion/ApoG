#pragma once

#include <queue>
#include <unordered_map>

#include "traversal.h"

class BfsTraversal : public Traversal
{
public:
    BfsTraversal(const Graph &graph);

    virtual std::vector<Vertex> traverse(const Vertex& start) override;

private:
    std::queue<Vertex> _workQueue;
    std::unordered_map<Vertex, bool> _visitedMap;
};
