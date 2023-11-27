#include "bfs.h"

#include <memory>

BfsTraversal::BfsTraversal(const Graph &graph)
    : Traversal(graph),
      _workQueue(std::queue<Vertex>()),
      _visitedMap(std::unordered_map<Vertex, bool>())
{
}

std::vector<Vertex> BfsTraversal::traverse(const Vertex &start)
{
    std::vector<Vertex> traversal = std::vector<Vertex>();

    _workQueue.push(start);

    while (!_workQueue.empty())
    {
        const Vertex &current = _workQueue.front();
        
        std::cout << current << std::endl;
        
        _workQueue.pop();

        traversal.emplace_back(current);
        _visitedMap[current] = true;

        // get the neighbors and add to the queue
        for (std::shared_ptr<Vertex> vert : _graph.getNeighbours(current))
        {
            if (!_visitedMap[*vert.get()])
            {
                _workQueue.push(*vert.get());
            }
        }
    }

    return traversal;
}