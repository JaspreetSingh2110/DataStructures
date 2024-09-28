//
// Created by Jaspreet Singh on 28/09/24.
//

#include <list>
#include <vector>

#include "Graphs.h"

class BridgeLocator {
  public:
  explicit BridgeLocator(int n)
  {
    this->numNodes = n;
    visited = new bool[n];
    low = new int[n];
    ids = new int[n];

    //Initialise arrays
    for (int i = 0; i < n; i++) {
      visited[i] = false;
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

  void PrintBridges()
  {
    if (bridges.empty()) {
      std::cout << "No bridges found!!!\n";
      return;
    }

    //Print bridges data.
    while (!bridges.empty()) {
      int node1 = bridges.front();
      bridges.pop_front();
      int node2 = bridges.front();
      bridges.pop_front();
      std::cout << "Bridge is present b/w nodes: " << node1 << " and " << node2 << std::endl;
    }
  }

  void DFS(int at, int parent)
  {
    //Mark node as visited.
    visited[at] = true;
    //Update Id and low for node.
    ids[at] = low[at] = ++id;

    //Iterate through each neighbor of given node
    for (int to : graph[at]) {
      //Because undirected graph are represented as nodes A->B and B<-A.
      // So, to avoid processing the edge back to parent node from where it came.
      if (parent == to) {
        continue;
      }

      //If neighbor is not yet visited, do DFS.
      if (!visited[to]) {
        //Traverse next neighbor
        DFS(to, at);
        low[at] = std::min(low[at], low[to]);

        //Bridge nodes.
        if (ids[at] < low[to]) {
          bridges.push_back(at);
          bridges.push_back(to);
        }
      }
      //If neighbor is already visited, update low value to min one.
      else {
        // Once scenario:
        // This is scenario when triangle A->B->C->A
        // A is already visited, but when B tries to visit A, it updates its low value.
        low[at] = std::min(low[at], low[to]);
      }
    }
  }

  void FindBridges()
  {
    //Go through each node, if there are disconnected components.
    for (int i = 0; i < numNodes; i++) {
      //If node is not visited yet, perform DFS traversal.
      if (!visited[i]) {
        DFS(i, -1);
      }
    }

    PrintBridges();
  }

  int id = 0;
  int numNodes = 0;
  std::list<int> bridges;
  int *ids = nullptr;
  int *low = nullptr;
  bool *visited = nullptr;
  std::vector<std::vector<int>> graph;
};

void TestBridges()
{
  BridgeLocator bridgeLocator(9);

  bridgeLocator.AddEdge(0, 1);
  bridgeLocator.AddEdge(0, 2);
  bridgeLocator.AddEdge(1, 2);
  bridgeLocator.AddEdge(2, 3);
  bridgeLocator.AddEdge(3, 4);
  bridgeLocator.AddEdge(2, 5);
  bridgeLocator.AddEdge(5, 6);
  bridgeLocator.AddEdge(6, 7);
  bridgeLocator.AddEdge(7, 8);
  bridgeLocator.AddEdge(8, 5);

  bridgeLocator.FindBridges();
}
