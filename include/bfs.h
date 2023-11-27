#pragma once

#include "traversal.h"

class BfsTraversal : public Traversal
{
public:
    BfsTraversal(const Graph &graph);

    virtual void traverse(const Vertex& start) override;
};
