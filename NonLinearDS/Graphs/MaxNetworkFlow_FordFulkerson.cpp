#include <vector>

#include "Graphs.h"
//
// Created by Jaspreet Singh on 03/10/24.
//

class NF_FordFulkerson {
  public:

  class Edge {
    public:
    explicit Edge(int from, int to, int capacity)
    {
      this->from = from;
      this->to = to;
      this->capacity = capacity;
    }

    bool IsResidualEdge()
    {
      return (capacity == 0);
    }

    void Augment(int bottleneckVal)
    {
      flow += bottleneckVal;
      residualEdge->flow -= bottleneckVal;
    }

    int RemainingCapacity()
    {
      return capacity - flow;
    }

    int from;
    int to;
    int capacity = 0;
    int flow = 0;
    Edge *residualEdge = nullptr;
  };

  void AddEdge(int from, int to, int capacity)
  {
    Edge *e1 = new Edge(from, to, capacity);
    Edge *e2 = new Edge(to, from, 0);
    e1->residualEdge = e2;
    e2->residualEdge = e1;
    graph[from].push_back(e1);
    graph[to].push_back(e2);
  }

  void VisitNode(int node)
  {
    visited[node] = VISITED;
  }

  bool IsVisited(int node)
  {
    return (visited[node] == VISITED);
  }

  void MarkAllNodesAsUnvisited()
  {
    VISITED++;
  }

  explicit NF_FordFulkerson(int n, int source, int sink)
  {
    this->numNodes = n;
    this->source = source;
    this->sink = sink;
    visited = new int[n];
    graph.resize(n);

    //Initialise empty graph.
    for (int i = 0; i < n; i++) {
      visited[i] = 0;
      graph[i] = std::vector<Edge *>();
    }
  }

  ~NF_FordFulkerson()
  {
    delete[] visited;
    for (int i = 0; i < numNodes; i++) {
      for (auto edge : graph[i]) {
        delete edge;
      }
    }
  }

  void Solve()
  {
    int bottleNeckValue = 0;
    do {
      //Mark all nodes as unvisited.
      MarkAllNodesAsUnvisited();

      //Use DFS to find a path from source to sink and get bottleneck value.
      bottleNeckValue = DFS_GetBottleNeckValue(source, INFINITY);

      //Update the max flow using the bottleneck value.
      maxFlow += bottleNeckValue;
    } while(bottleNeckValue != 0);
  }

  int DFS_GetBottleNeckValue(int node, double flow)
  {
    //If we have reached the sink node, return the flow value.
    if (node == sink) {
      return flow;
    }

    //Mark this node as visited.
    visited[node] = VISITED;

    //Get the neighbor edges of node.
    for (auto edge : graph[node]) {
      //If neighbor node is already visited, skip that neighbor
      if (visited[edge->to] == VISITED) {
        continue;
      }

      //If remaining capacity of edge to neighbor node is full, skip it.
      double remainingCapacity = edge->RemainingCapacity();
      if (remainingCapacity == 0) {
        continue;
      }

      // NOTES for 'std::min(flow, remaingCapacity)'
      // Bottleneck value is minimum of: current flow (to reach this node) and remaining capacity of edge we are going to next.
      int bottleNeckValue = DFS_GetBottleNeckValue(edge->to, std::min(flow, remainingCapacity));

      if (bottleNeckValue > 0) {
        edge->Augment(bottleNeckValue);
        return bottleNeckValue;
      }
    }
    return 0;
  }

  int GetMaxFlow()
  {
    return maxFlow;
  }

  int numNodes = 0;
  int VISITED = 1;
  int maxFlow = 0;
  int source;
  int sink;
  int *visited = nullptr;
  std::vector<std::vector<Edge *>> graph;
};


void Test_NF_FordFulkerson1()
{
  int n = 6;
  int source = n - 2;
  int sink = n - 1;

  NF_FordFulkerson nfFordFulkerson(n, source, sink);

  nfFordFulkerson.AddEdge(source, 0, 10);
  nfFordFulkerson.AddEdge(source, 1, 10);
  nfFordFulkerson.AddEdge(0, 2, 25);
  nfFordFulkerson.AddEdge(1, 3, 15);
  nfFordFulkerson.AddEdge(3, 0, 6);
  nfFordFulkerson.AddEdge(2, sink, 10);
  nfFordFulkerson.AddEdge(3, sink, 10);

  //Solve
  nfFordFulkerson.Solve();
  std::cout << "Max flow for given graph is: " << nfFordFulkerson.GetMaxFlow() << std::endl;
}

void Test_NF_FordFulkerson2()
{
  int n = 12;
  int source = n - 2;
  int sink = n - 1;

  NF_FordFulkerson nfFordFulkerson(n, source, sink);

  //Edges from source.
  nfFordFulkerson.AddEdge(source, 0, 7);
  nfFordFulkerson.AddEdge(source, 1, 2);
  nfFordFulkerson.AddEdge(source, 2, 1);

  //Intermediate edges.
  nfFordFulkerson.AddEdge(0, 3, 2);
  nfFordFulkerson.AddEdge(0, 4, 4);
  nfFordFulkerson.AddEdge(1, 4, 5);
  nfFordFulkerson.AddEdge(1, 5, 6);
  nfFordFulkerson.AddEdge(2, 3, 4);
  nfFordFulkerson.AddEdge(2, 7, 8);
  nfFordFulkerson.AddEdge(3, 6, 7);
  nfFordFulkerson.AddEdge(3, 7, 1);
  nfFordFulkerson.AddEdge(4, 5, 8);
  nfFordFulkerson.AddEdge(4, 8, 3);
  nfFordFulkerson.AddEdge(5, 8, 3);


  //Edges to sink.
  nfFordFulkerson.AddEdge(6, sink, 1);
  nfFordFulkerson.AddEdge(7, sink, 3);
  nfFordFulkerson.AddEdge(8, sink, 4);

  //Solve
  nfFordFulkerson.Solve();
  std::cout << "Max flow for given graph is: " << nfFordFulkerson.GetMaxFlow() << std::endl;
}

void Test_NF_FordFulkerson()
{
  std::cout << "Testing NF_FordFulkerson example1" << std::endl;
  Test_NF_FordFulkerson1(); //Small graph

  std::cout << "Testing NF_FordFulkerson example2" << std::endl;
  Test_NF_FordFulkerson2(); //Bigger graph
}
