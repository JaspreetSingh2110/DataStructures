//
// Created by Jaspreet Singh on 25/09/24.
//

#include <iostream>
#include <queue>

#include "Graphs.h"

void BFS(Graph &graph, int source)
{
  std::queue<int> q;
  q.push(source);
  graph.visited[source] = true;

  while (!q.empty()) {
    int node = q.front();
    std::cout << "Visited node: " << node << std::endl;
    q.pop();
    auto neighbours = graph.adjList[node];
    for (auto neighbour : neighbours) {
      if (graph.visited[neighbour] == false) {
        q.push(neighbour);
        graph.visited[neighbour] = true;
      }
    }
  }
}

void TestBFS()
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

  BFS(graph, 0);
}