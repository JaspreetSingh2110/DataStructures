//
// Created by Jaspreet Singh on 25/09/24.
//

#include "Graphs.h"

Graph::Graph(int numNodes)
{
  this->numNodes = numNodes;
  visited = new bool[numNodes];
  memset(visited, false, sizeof(bool) * numNodes);
}

Graph::~Graph()
{
  delete[] visited;
}


void Graph::addEdge(int u, int v)
{
  if (u >= numNodes || v >= numNodes) {
    return;
  }

  // For undirected graph, node A is neighbour of B and vice versa.
  adjList[u].push_back(v);
  adjList[v].push_back(u);
}
