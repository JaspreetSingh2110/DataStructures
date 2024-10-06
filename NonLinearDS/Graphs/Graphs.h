//
// Created by Jaspreet Singh on 25/09/24.
//

#ifndef GRAPHS_H
#define GRAPHS_H
#include <map>
#include <vector>
#include <cstring>
#include <cstdint>
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
//Traversal algorithms.
void TestDFS();
void TestBFS();

//Shortest path algorithms.
void TestBFSShortestPath();
void Test_BFS_ShortestPathOnGrid();
void TestTopologicalSortAdjacencyList();
void Test_Dijkstra_SingleSourceShortestPath();
void Test_BellmanFord_SingleSourceShortestPath();
void Test_FloydWarshall_AllPairShortestPath();

//Eulerian path
void TestEulerianPath();

//Bridges and Articulation points.
void TestBridges();
void TestArticulationPoints();

///Strongly connected components.
void Test_Tarjans_StronglyConnectedComponents();

//Minimum spanning tree algorithms.
void Test_KruskalsMinSpanningTree();
void Test_PrimsMinSpanningTree_LazySolver();

//Network flows
void Test_NF_FordFulkerson();
void Test_NF_EdmondsKarp();

#endif //GRAPHS_H
