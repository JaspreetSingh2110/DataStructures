//
// Created by Jaspreet Singh on 26/09/24.
//

#include <list>

#include "Graphs.h"

class TopologicalSortAdjacencyList {
public:
  TopologicalSortAdjacencyList() {}

  int DFS(std::map<int, std::list<Edge>> &graph, bool *visited, int tsOrder[], int nodeIndex, int orderIndex)
  {
    visited[nodeIndex] = true;

    auto neighbours = graph[nodeIndex];
    for (auto neighbour : neighbours) {
      if (visited[neighbour.to] == false) {
        orderIndex = DFS(graph, visited, tsOrder, neighbour.to, orderIndex);
      }
    }

    //Update orderArray when dfs traversal reaches last node.
    tsOrder[orderIndex] = nodeIndex;
    return (orderIndex - 1);
  }

  void Sort(std::map<int, std::list<Edge>> &graph, int numNodes, int sortArr[])
  {
    //Create an array to track nodes visit state.
    int tOrderIndex = numNodes -1;
    bool *visited = new bool[numNodes];

    //Iterate over loop because:
    //if any nodes are not connected through any other node, process it as independent node.
    for (int i = 0; i < numNodes; i++) {
      if (visited[i] == false) {
        tOrderIndex = DFS(graph, visited, sortArr, i, tOrderIndex);
      }
    }
  }

  void FindSingleSrcShortestPath(std::map<int, std::list<Edge>> &graph, int topSortedArr[], int shortestPath[], int numNodes)
  {
    for (int i = 0; i < numNodes; i++) {
      int nodeIndex = topSortedArr[i];

      auto neighbours = graph[nodeIndex];
      for (auto neighbour : neighbours) {
        int cost = neighbour.weight + shortestPath[nodeIndex];

        //If the path cost is not yet updated or is lesser than current cost, set it.
        if ((shortestPath[neighbour.to] == -1) || (cost < shortestPath[neighbour.to])) {
          shortestPath[neighbour.to] = cost;
        }
      }
    }
  }
};

void TestTopologicalSortAdjacencyList()
{
  int numNodes = 7;
  std::map<int, std::list<Edge>> graph;
  int sortedArray[7];
  int shortestPath[7];

  //Initialisation of array.
  memset(sortedArray, INT32_MAX, sizeof(sortedArray));
  memset(shortestPath, -1, sizeof(shortestPath));
  shortestPath[0] = 0;

  //Default initialisation of map.
  for (int i = 0; i < numNodes; i++) {
    graph[i] = std::list<Edge>();
  }
  //Insert edges
  graph[0].emplace_back(1, 3);
  graph[0].emplace_back(2, 2);
  graph[0].emplace_back(5, 3);
  graph[1].emplace_back(3, 1);
  graph[1].emplace_back(2, 6);
  graph[2].emplace_back(3, 1);
  graph[2].emplace_back(4, 10);
  graph[3].emplace_back(4, 5);
  graph[5].emplace_back(4, 7);

  TopologicalSortAdjacencyList topSort;
  topSort.Sort(graph, numNodes, sortedArray);

  for (int i = 0; i < numNodes; i++) {
    std::cout << sortedArray[i] << " ";
  }

  std::cout << "\nFinding single source shortest path!!!" << std::endl;
  topSort.FindSingleSrcShortestPath(graph, sortedArray, shortestPath, numNodes);

  //Print shortest path.
  std::cout << "Shortest path:" << std::endl;
  for (int i = 0; i < numNodes; i++) {
    std::cout << shortestPath[i] << " | ";
  }
  std::cout << std::endl;
  for (int i = 0; i < numNodes; i++) {
    std::cout << i << " | ";
  }
  std::cout << std::endl;
}
