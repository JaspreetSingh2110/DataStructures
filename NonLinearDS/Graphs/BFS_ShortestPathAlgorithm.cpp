//
// Created by Jaspreet Singh on 26/09/24.
//

#include <iostream>
#include <queue>

#include "Graphs.h"

std::vector<int> BFS_GetPathArr(Graph &graph, int source)
{
  std::vector<int> path(graph.GetNodeCount(), -1);
  std::queue<int> q;
  q.push(source);
  graph.visited[source] = true;

  while (!q.empty()) {
    int node = q.front();
    q.pop();
    //std::cout << "Visited node: " << node << std::endl;
    auto neighbours = graph.adjList[node];
    for (auto neighbour : neighbours) {
      if (graph.visited[neighbour] == false) {
        q.push(neighbour);
        graph.visited[neighbour] = true;

        //Path to reach this neighbor node is via parent 'node' node.
        path[neighbour] = node;
      }
    }
  }
  return path;
}

void FindAndPrintShortestPath(std::vector<int> &path, int src, int dest)
{
  std::vector<int> fPath;
  for (int i = dest; i != -1; i = path[i]) {
    fPath.push_back(i);
  }

  if (fPath[fPath.size() - 1] != src) {
    std::cout << "No valid path found b/w src: " << src << " dest: " << dest << std::endl;
    return;
  }
  std::cout << "Shortest path from " << src << " to " << dest << std::endl;
  for (auto it = fPath.rbegin(); it != fPath.rend(); it++) {
    std::cout << *it << " -> ";
  }
  std::cout << std::endl;
}

void TestBFSShortestPath()
{
  Graph graph(8);
  graph.addEdge(0, 1);
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
  graph.addEdge(6,7);

  std::vector<int> pathArr = BFS_GetPathArr(graph, 0);
  FindAndPrintShortestPath(pathArr, 0, 3);
  FindAndPrintShortestPath(pathArr, 0, 6);

  graph.ResetVisited();
  pathArr = BFS_GetPathArr(graph, 1);
  FindAndPrintShortestPath(pathArr, 1, 4);

  graph.ResetVisited();
  pathArr = BFS_GetPathArr(graph, 5);
  FindAndPrintShortestPath(pathArr, 5, 4);
}