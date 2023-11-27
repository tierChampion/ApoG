#pragma once

#include "traversal.h"

class DfsTraversal : public Traversal
{
public:
    DfsTraversal(const Graph &graph);

    virtual void traverse(const Vertex& start) override;
};

