#include <iostream>

#include "graph.h"
#include "bfs.h"
#include "dfs.h"

int main()
{
  Graph graph = Graph();

  Vertex vertices[2] = {
      Vertex(0, 1),
      Vertex(1, 1)};

  graph.addVertex(vertices[0]);
  graph.addVertex(vertices[1]);

  graph.addEdge(0, 1, false);

  std::cout << graph << std::endl;

  BfsTraversal bfs = BfsTraversal(graph);
  DfsTraversal dfs = DfsTraversal(graph);

  bfs.traverse(vertices[0]);
  dfs.traverse(vertices[0]);

  std::cout << "BFS traversal: " << std::endl;
  for (Vertex v : bfs)
  {
    std::cout << v << std::endl;
  }

  std::cout << std::endl
            << "DFS traversal: " << std::endl;

  for (Vertex v : dfs)
  {
    std::cout << v << std::endl;
  }

  return 0;
}
