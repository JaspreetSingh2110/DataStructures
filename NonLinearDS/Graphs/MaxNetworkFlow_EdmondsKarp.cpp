//
// Created by Jaspreet Singh on 03/10/24.
//

#include <vector>
#include <cmath>
#include <iostream>
#include <queue>

class NF_EdmondsKarp {
  public:

  class Edge {
    public:
    Edge() {}
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
    double flow = 0;
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

  explicit NF_EdmondsKarp(int n, int source, int sink)
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

  ~NF_EdmondsKarp()
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
      bottleNeckValue = BFS_GetBottleNeckValue();

      //Update the max flow using the bottleneck value.
      maxFlow += bottleNeckValue;
    } while(bottleNeckValue != 0);
  }

  int BFS_GetBottleNeckValue()
  {
    //Create array for path tracking.
    Edge **prev = new Edge*[numNodes];
    for (int i = 0; i < numNodes; i++) {
      prev[i] = nullptr;
    }

    //Create queue for BFS search.
    std::queue<int> q;
    q.push(source);
    visited[source] = VISITED;

    //Repeat below block till q is not empty.
    while (!q.empty()) {
      int node = q.front();
      q.pop();

      //If sink node is reached, break loop.
      if (node == sink) {
        break;
      }

      for (auto edge : graph[node]) {
        if ((visited[edge->to] != VISITED) && (edge->RemainingCapacity() > 0)) {
          visited[edge->to] = VISITED;
          q.push(edge->to);
          prev[edge->to] = edge;
        }
      }
    }

    //If we are not able to reach sink, no path be found, return 0.
    if (prev[sink] == nullptr) {
      return 0;
    }

    double bottleneckValue = INFINITY;
    //Iterate over path and find the bottleneck value.
    for (Edge *edge = prev[sink]; edge != nullptr; edge = prev[edge->from]) {
      bottleneckValue = std::min(bottleneckValue, (double)edge->RemainingCapacity());
    }

    //Once bottleneck value is found, augment the path.
    //Update the flow with augment value.
    for (Edge *edge = prev[sink]; edge != nullptr; edge = prev[edge->from]) {
      edge->Augment(bottleneckValue);
    }

    return bottleneckValue;
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


void Test_NF_EdmondsKarp1()
{
  int n = 6;
  int source = n - 2;
  int sink = n - 1;

  NF_EdmondsKarp nfFordFulkerson(n, source, sink);

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

void Test_NF_EdmondsKarp2()
{
  int n = 6;
  int source = n - 2;
  int sink = n - 1;

  NF_EdmondsKarp nfFordFulkerson(n, source, sink);

  //Edges from source nodes.
  nfFordFulkerson.AddEdge(source, 0, 10);
  nfFordFulkerson.AddEdge(source, 1, 10);

  //Intermediate edges.
  nfFordFulkerson.AddEdge(0, 1, 2);
  nfFordFulkerson.AddEdge(0, 2, 4);
  nfFordFulkerson.AddEdge(0, 3, 8);
  nfFordFulkerson.AddEdge(1, 3, 9);
  nfFordFulkerson.AddEdge(3, 2, 6);

  //Edges to sink.
  nfFordFulkerson.AddEdge(2, sink, 10);
  nfFordFulkerson.AddEdge(3, sink, 10);

  //Solve
  nfFordFulkerson.Solve();
  std::cout << "Max flow for given graph is: " << nfFordFulkerson.GetMaxFlow() << std::endl;
}

void Test_NF_EdmondsKarp3()
{
  int n = 12;
  int source = n - 2;
  int sink = n - 1;

  NF_EdmondsKarp nfFordFulkerson(n, source, sink);

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

void Test_NF_EdmondsKarp()
{
  std::cout << "Testing NF_EdmondsKarp example1" << std::endl;
  Test_NF_EdmondsKarp1(); //Small graph1

  std::cout << "Testing NF_EdmondsKarp example2" << std::endl;
  Test_NF_EdmondsKarp2(); //Small graph2

  std::cout << "Testing NF_EdmondsKarp example2" << std::endl;
  Test_NF_EdmondsKarp3(); //Bigger graph
}
