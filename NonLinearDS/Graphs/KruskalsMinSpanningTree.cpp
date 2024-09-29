//
// Created by Jaspreet Singh on 29/09/24.
//

#include <iostream>

#include "../../UnionFind/UnionFind.h"

class KruskalsMinSpanningTree {
public:

  class Edge {
    public:
    int from;
    int to;
    int cost;

    Edge(int from, int to, int cost)
    {
      this->from = from;
      this->to = to;
      this->cost = cost;
    }
  };

  explicit KruskalsMinSpanningTree(int n)
  {
    numNodes = n;
  }

  void AddEdge(int from, int to, int cost)
  {
    edges.push_back(Edge(from, to, cost));
  }

  void Solve()
  {
    UnionFind uf(numNodes);
    int totalCost = 0;

    auto edgeComparator = [](const Edge &e1, const Edge &e2) ->bool {
      return e1.cost < e2.cost;
    };

    //Sort edge list.
    std::sort(edges.begin(), edges.end(), edgeComparator);

    for (Edge &edge : edges) {
      //If node of edges belongs to same component, skip processing.
      if (uf.IsConnected(edge.from, edge.to)) {
        continue;
      }

      uf.Unite(edge.from, edge.to);
      totalCost += edge.cost;

      //Exit early
      if (uf.GetComponentsCount() == 1) {
        break;
      }
    }

    //Check if min span tree was found, and print its cost.
    if (uf.GetComponentsCount() == 1) {
      std::cout << "Total min cost for MST: " << totalCost << std::endl;
    }
    else {
      std::cout << "No Minimum Spanning Tree exist!!!\n";
    }
  }

  int numNodes = 0;
  std::vector<Edge> edges;
};


void Test_KruskalsMinSpanningTree()
{
  KruskalsMinSpanningTree kMST(10);

  //Add edges.
  kMST.AddEdge(0, 1, 5);
  kMST.AddEdge(1, 2, 4);
  kMST.AddEdge(2, 9, 2);
  kMST.AddEdge(0, 4, 1);
  kMST.AddEdge(0, 3, 4);
  kMST.AddEdge(1, 3, 2);
  kMST.AddEdge(2, 7, 4);
  kMST.AddEdge(2, 8, 1);
  kMST.AddEdge(9, 8, 0);
  kMST.AddEdge(4, 5, 1);
  kMST.AddEdge(5, 6, 7);
  kMST.AddEdge(6, 8, 4);
  kMST.AddEdge(4, 3, 2);
  kMST.AddEdge(5, 3, 5);
  kMST.AddEdge(3, 6, 11);
  kMST.AddEdge(6, 7, 1);
  kMST.AddEdge(3, 7, 2);
  kMST.AddEdge(7, 8, 6);

  //Trigger solver.
  kMST.Solve();
}
