#include <iostream>

#include "graph.h"
#include "bfs.h"

int main()
{
  Graph graph = Graph();

  Vertex vertices[2] = {
    Vertex(0, 1),
    Vertex(1, 1)
  };

  graph.addVertex(vertices[0]);
  graph.addVertex(vertices[1]);

  graph.addEdge(0, 1, false);

  std::cout << graph << std::endl;

  BfsTraversal bfs = BfsTraversal(graph);

  std::vector<Vertex> trav = bfs.traverse(vertices[0]);

  std::cout << "BFS traversal: " << std::endl;
  for (Vertex v : trav) {
    std::cout << v << std::endl;
  }

  std::cout << graph << std::endl;

  return 0;
}
