//
// Created by Jaspreet Singh on 25/09/24.
//

#ifndef GRAPHS_H
#define GRAPHS_H
#include <map>
#include <iostream>

class Edge {
  public:
  int to;
  int weight;

  Edge() {}
  Edge(int to, int weight)
  {
    this->to = to;
    this->weight = weight;
  }
};

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

  int GetNodeCount() const;
  void ResetVisited() const;
};


//Test functions from other files.
void TestDFS();
void TestBFS();
void TestBFSShortestPath();
void Test_BFS_ShortestPathOnGrid();
void TestTopologicalSortAdjacencyList();
void Test_Dijkstra_SingleSourceShortestPath();

#endif //GRAPHS_H
