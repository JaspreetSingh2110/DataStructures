//
// Created by Jaspreet Singh on 30/09/24.
//

#include <iostream>
#include <queue>

class PrimsMinSpanningTree_Lazy {
  public:
  class Edge {
    public:
    Edge(int from, int to, int cost)
    {
      this->from = from;
      this->to = to;
      this->cost = cost;
    }

    int from;
    int to;
    int cost;
  };

  class EdgeComparator {
    public:
    bool operator()(const Edge& e1, const Edge& e2)
    {
      return e1.cost > e2.cost;
    }
  };

  void AddEdge(int from, int to, int cost)
  {
    graph[from].push_back(Edge(from, to, cost));
    graph[to].push_back(Edge(to, from, cost));
  }

  explicit PrimsMinSpanningTree_Lazy(int n)
  {
    numNodes = n;
    visited = new bool[n];
    graph.resize(n);

    for (int i = 0; i < n; i++) {
      visited[i] = false;
      graph[i] = std::vector<Edge>();
    }
  }

  void VisitNode(int at)
  {
    //Mark this node as visited.
    visited[at] = true;

    //Iterate over edges from this node and add it to priority queue.
    for (Edge &e : graph[at]) {
      if (!visited[e.to]) {
        pq.push(e);
      }
    }
  }

  void Solve(int startNode = 0)
  {
    int mstCost = 0;
    int currentEdgeCnt = 0;
    int expEdgeCnt = numNodes -1;
    std::vector<int> msTree;
    msTree.push_back(startNode);

    //Add edges of starting node to queue.
    VisitNode(startNode);

    while (!pq.empty() && (currentEdgeCnt != expEdgeCnt)) {
      Edge e = pq.top();
      pq.pop();

      //If next node from this edge is already visited, continue.
      if (visited[e.to]) {
        continue;
      }
      //Visit next node.
      VisitNode(e.to);

      //Update min span tree cost and update visited node to list.
      mstCost += e.cost;
      msTree.push_back(e.to);
      currentEdgeCnt++;
    }

    if (currentEdgeCnt != expEdgeCnt) {
      std::cout << "No minimum spanning tree exists in graph\n";
      return;
    }

    //Print Min spanning tree data.
    std::cout << "Minimum spanning tree cost: " << mstCost << "\n";
    //Print MST nodes
    std::cout << "Min spanning tree nodes list: ";
    for (int node : msTree) {
      std::cout << " -> " << node;
    }
    std::cout << std::endl;
  }

  int numNodes = 0;
  bool *visited;
  std::priority_queue<Edge, std::vector<Edge>, EdgeComparator> pq;
  std::vector<std::vector<Edge>> graph;
};

void Test_PrimsMinSpanningTree_LazySolver()
{
  PrimsMinSpanningTree_Lazy primsMST(10);

  //Add edges.
  primsMST.AddEdge(0, 1, 5);
  primsMST.AddEdge(1, 2, 4);
  primsMST.AddEdge(2, 9, 2);
  primsMST.AddEdge(0, 4, 1);
  primsMST.AddEdge(0, 3, 4);
  primsMST.AddEdge(1, 3, 2);
  primsMST.AddEdge(2, 7, 4);
  primsMST.AddEdge(2, 8, 1);
  primsMST.AddEdge(9, 8, 0);
  primsMST.AddEdge(4, 5, 1);
  primsMST.AddEdge(5, 6, 7);
  primsMST.AddEdge(6, 8, 4);
  primsMST.AddEdge(4, 3, 2);
  primsMST.AddEdge(5, 3, 5);
  primsMST.AddEdge(3, 6, 11);
  primsMST.AddEdge(6, 7, 1);
  primsMST.AddEdge(3, 7, 2);
  primsMST.AddEdge(7, 8, 6);

  //Trigger solver.
  primsMST.Solve();
}
