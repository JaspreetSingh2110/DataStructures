//
// Created by Jaspreet Singh on 04/10/24.
//

#include <iostream>
#include <map>
#include <stack>

class Tarjans_StronglyConnectedComponents {
  public:

  class Edge {
    public:
    int from;
    int to;

    explicit Edge (int _from, int _to) : from(_from), to(_to) {}
  };

  explicit Tarjans_StronglyConnectedComponents(int n)
  {
    this->numNodes = n;
    ids = new int[n];
    low = new int[n];
    onStack = new bool[n];
    graph.resize(n);

    //Initialise arrays.
    for (int i = 0; i < n; i++) {
      onStack[i] = false;
      ids[i] = -1;
      low[i] = 0;
      graph[i] = std::vector<int>();
    }
  }

  void AddEdge(int from, int to)
  {
    graph[from].push_back(to);
  }

  int GetSccCount()
  {
    return sccCount;
  }

  void PrintScc()
  {
    std::map<int, std::vector<int>> sccMap;

    for (int i = 0; i < numNodes; i++) {
      int sccGroup = low[i];
      sccMap[sccGroup].push_back(i);
    }

    for (int i = 0; i < sccMap.size(); i++) {
      if (sccMap[i].empty()) {
        continue;
      }
      std::cout << "Scc group is formed by nodes: ";
      for (int node : sccMap[i]) {
        std::cout << " -> "<< node;
      }
      std::cout << std::endl;
    }
  }

  void Solve()
  {
    //Iterate over each node, in case there is independent component.
    for (int i = 0; i < numNodes; i++) {
      //if node is unvisited, do DFS.
      if (ids[i] == -1) {
        dfs(i);
      }
    }
  }

  void dfs(int at)
  {
    //Initialise id and low value for node being visited
    low[at] = ids[at] = id++;

    //Push node on stack.
    s.push(at);
    onStack[at] = true;

    //DFS
    for (int to : graph[at]) {
      //if neighbor is currently not visited, do dfs on it.
      if (ids[to] == -1) {
        dfs(to);
      }
      // If neighbour node is already on stack, update the low value of current node.
      if (onStack[to]) {
        low[at] = std::min(low[at], low[to]);
      }
    }

    //If it is same node as start node
    if (ids[at] == low[at]) {
      sccCount++;

      //Pop all elements from stack till current node.
      for (int top = s.top(); ; top = s.top()) {
        s.pop();
        onStack[top] = false;
        low[top] = low[at];
        if (top == at) {
          break;
        }
      }
    }
  }

  int numNodes = 0;
  int id = 0;
  int sccCount = 0;
  std::stack<int> s;
  int *ids = nullptr;
  int *low = nullptr;
  bool *onStack = nullptr;
  std::vector<std::vector<int>> graph;
};


void Test_Tarjans_StronglyConnectedComponents()
{
  int n = 8;

  Tarjans_StronglyConnectedComponents tSCC(n);

  //Initialise graph.
  tSCC.AddEdge(6, 0);
  tSCC.AddEdge(6, 2);
  tSCC.AddEdge(3, 4);
  tSCC.AddEdge(6, 4);
  tSCC.AddEdge(2, 0);
  tSCC.AddEdge(0, 1);
  tSCC.AddEdge(4, 5);
  tSCC.AddEdge(5, 6);
  tSCC.AddEdge(3, 7);
  tSCC.AddEdge(7, 5);
  tSCC.AddEdge(1, 2);
  tSCC.AddEdge(7, 3);
  tSCC.AddEdge(5, 0);

  //Trigger solver.
  tSCC.Solve();

  //Print values.
  std::cout << "Nos of strongly connected components: " << tSCC.GetSccCount() << std::endl;
  std::cout << "Details of SCCs in graph: \n";
  tSCC.PrintScc();
}
