//
// Created by Jaspreet Singh on 26/09/24.
//

#include "Graphs.h"

void DFS(Graph &graph, int node)
{
  if (graph.visited[node]) {
    return;
  }
  graph.visited[node] = true;
  std::cout << "Visited node: " << node << std::endl;

  auto neighbours = graph.adjList[node];
  for (auto neighbour : neighbours) {
    DFS(graph, neighbour);
  }
}


void TestDFS()
{
  Graph graph(6);
  graph.addEdge(0, 1);
  graph.addEdge(0, 3);
  graph.addEdge(0, 4);
  graph.addEdge(1,2);
  graph.addEdge(1,3);
  graph.addEdge(1,5);
  graph.addEdge(2,1);
  graph.addEdge(2,4);
  graph.addEdge(3,2);
  graph.addEdge(3,5);
  graph.addEdge(4,2);
  graph.addEdge(5,1);
  graph.addEdge(5,3);

  DFS(graph, 0);
}
