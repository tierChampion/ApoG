#include "dfs.h"

#include <memory>

DfsTraversal::DfsTraversal(const Graph &graph)
    : Traversal(graph),
      _workStack(std::stack<Vertex>()),
      _visitedMap(std::unordered_map<Vertex, bool>())
{
}

std::vector<Vertex> DfsTraversal::traverse(const Vertex &start)
{
    std::vector<Vertex> traversal = std::vector<Vertex>();

    _workStack.push(start);

    while (!_workStack.empty())
    {
        const Vertex &current = _workStack.top();
        
        std::cout << current << std::endl;
        
        _workStack.pop();

        traversal.emplace_back(current);
        _visitedMap[current] = true;

        // get the neighbors and add to the queue
        for (std::shared_ptr<Vertex> vert : _graph.getNeighbours(current))
        {
            if (!_visitedMap[*vert.get()])
            {
                _workStack.push(*vert.get());
            }
        }
    }

    return traversal;
}