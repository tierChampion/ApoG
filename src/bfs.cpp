#include "bfs.h"

#include <memory>
#include <queue>
#include <unordered_map>

BfsTraversal::BfsTraversal(const Graph &graph)
    : Traversal(graph)
{
}

void BfsTraversal::traverse(const Vertex &start)
{
    std::queue<Vertex> workQueue;
    std::unordered_map<Vertex, bool> visitedMap;

    workQueue.push(start);

    while (!workQueue.empty())
    {
        const Vertex &current = workQueue.front();

        workQueue.pop();

        _traversal.emplace_back(current);
        visitedMap[current] = true;

        for (std::shared_ptr<Vertex> vert : _graph.getNeighbours(current))
        {
            if (!visitedMap[*vert.get()])
            {
                workQueue.push(*vert.get());
            }
        }
    }
}