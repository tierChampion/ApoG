#include "dfs.h"

#include <memory>
#include <stack>
#include <unordered_map>

DfsTraversal::DfsTraversal(const Graph &graph)
    : Traversal(graph)
{
}

void DfsTraversal::traverse(const Vertex &start)
{
    std::stack<Vertex> workStack;
    std::unordered_map<Vertex, bool> visitedMap;

    workStack.push(start);

    while (!workStack.empty())
    {
        const Vertex &current = workStack.top();

        workStack.pop();

        _traversal.emplace_back(current);
        visitedMap[current] = true;

        for (std::shared_ptr<Vertex> vert : _graph.getNeighbours(current))
        {
            if (!visitedMap[*vert.get()])
            {
                workStack.push(*vert.get());
            }
        }
    }
}