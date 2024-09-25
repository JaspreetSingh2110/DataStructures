//
// Created by Jaspreet Singh on 25/09/24.
//

#include "Graphs.h"

Graph::Graph(int numNodes)
{
  this->numNodes = numNodes;
  visited = new bool[numNodes];
}

Graph::~Graph()
{
  if (visited) {
    delete[] visited;
  }
}


void Graph::addEdge(int u, int v)
{
  if (u >= numNodes || v >= numNodes) {
    return;
  }
  adjList[u].push_back(v);
}
