//
// Created by Jaspreet Singh on 25/09/24.
//

#ifndef GRAPHS_H
#define GRAPHS_H
#include <map>
#include <iostream>

class Graph {
  private:
  int numNodes;

public:
  bool *visited = nullptr;
  std::map<int, std::vector<int>> adjList;

  Graph() {}
  explicit Graph(int numNodes);
  ~Graph();
  void addEdge(int u, int v);
};

void TestDFS();

#endif //GRAPHS_H
