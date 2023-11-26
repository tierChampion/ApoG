#include <iostream>

#include "graph.h"

int main()
{
  Graph graph = Graph();

  graph.addVertex(Vertex(0, 1));
  graph.addVertex(Vertex(1, 1));

  graph.addEdge(0, 1, false);

  std::cout << graph << std::endl;

  return 0;
}
