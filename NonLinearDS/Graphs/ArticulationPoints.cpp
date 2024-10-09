//
// Created by Jaspreet Singh on 29/09/24.
//

#include <iostream>
#include <vector>
#include <list>

class ArticulationPoints {
  public:
  explicit ArticulationPoints(int n)
  {
    this->numNodes = n;
    visited = new bool[n];
    isArt = new bool[n];
    low = new int[n];
    ids = new int[n];

    //Initialise arrays
    for (int i = 0; i < n; i++) {
      visited[i] = false;
      isArt[i] = false;
      low[i] = 0;
      ids[i] = 0;
    }

    //Initialise empty graph.
    graph.resize(n);
    for (int i = 0; i < n; i++) {
      graph[i] = std::vector<int>();
    }
  }

  void AddEdge(int from, int to)
  {
    graph[from].push_back(to);
    graph[to].push_back(from);
  }

  void PrintArticulationPoints()
  {
    bool isArtPointFoind = false;
    std::cout << "Articulation points in given graph: ";
    for (int i = 0; i < numNodes; i++) {
      if (isArt[i]) {
        isArtPointFoind = true;
        std::cout << i << " ";
      }
    }

    if (!isArtPointFoind) {
      std::cout << " [NOT FOUND]";
    }
    std::cout << std::endl;
  }

  void DFS(int root, int at, int parent)
  {
    visited[at] = true;
    ids[at] = low[at] = id++;

    if (root == parent) {
      outEdgeCnt++;
    }

    //Iterate through all neighbours
    for (int to : graph[at]) {
      if (to == parent) {
        continue;
      }

      //If neighbor is not visited yet, do DFS on it.
      if (!visited[to]) {
        DFS(root, to, at);
        low[at] = std::min(low[at], low[to]);

        //if cycle found.
        if (ids[at] <= low[to]) {
          isArt[at] = true;
        }
      }
      else { //Update low value
        low[at] = std::min(low[at], ids[to]);
      }
    }
  }

  void FindArticulationPoints()
  {
    //Iterate through all nodes, if there is separate component in graph.
    for (int i = 0; i < numNodes; i++) {
      if (!visited[i]) {
        outEdgeCnt = 0;
        DFS(i, i, -1);

        //This to avoid starting node in a cyclic graph to become as art point.
        isArt[i] = (outEdgeCnt > 1);
      }
    }

    //Print Articulation Points.
    PrintArticulationPoints();
  }

  int id = 0;
  int numNodes = 0;
  int outEdgeCnt = 0;
  int *ids = nullptr;
  int *low = nullptr;
  bool *isArt = nullptr;
  bool *visited = nullptr;
  std::vector<std::vector<int>> graph;
};



void TestExample1()
{
  ArticulationPoints articulationPointsFinder(9);

  articulationPointsFinder.AddEdge(0, 1);
  articulationPointsFinder.AddEdge(0, 2);
  articulationPointsFinder.AddEdge(1, 2);
  articulationPointsFinder.AddEdge(2, 3);
  articulationPointsFinder.AddEdge(3, 4);
  articulationPointsFinder.AddEdge(2, 5);
  articulationPointsFinder.AddEdge(5, 6);
  articulationPointsFinder.AddEdge(6, 7);
  articulationPointsFinder.AddEdge(7, 8);
  articulationPointsFinder.AddEdge(8, 5);

  articulationPointsFinder.FindArticulationPoints();
}

void TestExample2()
{
  ArticulationPoints articulationPointsFinder(3);

  articulationPointsFinder.AddEdge(0, 1);
  articulationPointsFinder.AddEdge(1, 2);

  articulationPointsFinder.FindArticulationPoints();
}

void TestArticulationPoints()
{
  std::cout << "Testing graph1: " << std::endl;
  TestExample1();

  std::cout << "Testing graph2: " << std::endl;
  TestExample2();
}
