//
// Created by Jaspreet Singh on 27/09/24.
//

#include <iostream>
#include <list>
#include <map>
#include <limits>

class BellmanFord_SingleSourceShortestPath {
public:
  class Edge {
  public:
    int from;
    int to;
    double weight;

    Edge(int src, int dest, double weight)
    {
      this->from = src;
      this->to = dest;
      this->weight = weight;
    }
  };

  explicit BellmanFord_SingleSourceShortestPath(int n)
  {
    this->numNodes = n;
  }

  void AddEdge(int src, int dest, double weight)
  {
    if ((src < 0) || (src >= numNodes) ||
        (dest < 0) || (dest >= numNodes) ||
        (src == dest)) {
      std::cerr << "Invalid Edge Input!!!" << std::endl;
      return;
    }
    numEdges++;
    graph[src].emplace_back(src, dest, weight);
  }

  //Get list of edges from graph.
  std::list<Edge> GetEdges()
  {
    std::list<Edge> edges;
    for (int i = 0; i < numNodes -1; i++) {
      for (auto edge : graph[i]) {
        edges.emplace_back(edge);
      }
    }
    return edges;
  }

  void BellManFord_SSSP(int source, double path[])
  {
    std::list<Edge> edges = GetEdges();

    //As per algorithm, relax each edge, V-1 times (nos of vertices/nodes -1)
    for (int i = 0; i < numNodes -1; i++) {
      for (auto edge : edges) {
        //Relax.
        if (path[edge.to] > (path[edge.from] + edge.weight)) {
          path[edge.to] = path[edge.from] + edge.weight;
        }
      }
    }

    //Re-run similar relaxation process, to find if negative cycles are present.
    //When we re-run, if the optimal path value, is further decreased, it means -ve cycle is present.
    for (int i = 0; i < numNodes -1; i++) {
      for (auto edge : edges) {
        //Relax.
        if (path[edge.to] > (path[edge.from] + edge.weight)) {
          path[edge.to] = -std::numeric_limits<double>::infinity();
        }
      }
    }
  }

  //data members.
  std::map<int, std::list<Edge>> graph;
  int numNodes = 0;
  int numEdges = 0;
};


void Test_BellmanFord_SingleSourceShortestPath()
{
  //Initialise graph.
  int vertices = 9;
  BellmanFord_SingleSourceShortestPath bf(vertices);
  bf.AddEdge(0, 1, 1);
  bf.AddEdge(1, 2, 1);
  bf.AddEdge(2, 4, 1);
  bf.AddEdge(4, 3, -3);
  bf.AddEdge(3, 2, 1);
  bf.AddEdge(1, 5, 4);
  bf.AddEdge(1, 6, 4);
  bf.AddEdge(5, 6, 5);
  bf.AddEdge(6, 7, 4);
  bf.AddEdge(5, 7, 3);

  double shortestPathCost[vertices];
  for (int i = 0; i < vertices; i++) {
    shortestPathCost[i] = std::numeric_limits<double>::infinity();
  }

  int source = 0;
  shortestPathCost[source] = 0;
  //Run the algorithm.
  bf.BellManFord_SSSP(source, shortestPathCost);

  //Print paths.
  for (int i = 0; i < vertices; i++) {
    std::cout << "Path from node: 0 -> node: " << i << " has cost: " << shortestPathCost[i] << std::endl;
  }
}

