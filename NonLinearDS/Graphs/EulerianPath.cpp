//
// Created by Jaspreet Singh on 28/09/24.
// Eulerian path for given graph is:
// To traverse complete graph by going through each edge exactly once.
//

#include <iostream>
#include <list>

class EulerianPath {
  public:
  explicit EulerianPath(int n)
  {
    this->numNodes = n;
    in = new int[n];
    out = new int[n];
    graph.resize(n);

    //Initialise empty vector
    for (int i = 0; i < n; i++) {
      graph[i] = std::vector<int>();
    }
  }

  ~EulerianPath()
  {
    delete[] in;
    delete[] out;
  }

  void AddEdge(int from, int to)
  {
    graph[from].push_back(to);
    this->edgeCnt++;
  }

  void CalculateInOutOrder()
  {
    for (int from = 0; from < numNodes; from++) {
      for (int to : graph[from]) {
        //std::cout << "Edge found from: " << from << " to: " << to << std::endl;
        out[from]++;
        in[to]++;
      }
    }

    std::string inOrder;
    std::string outOrder;
    for (int i = 0; i < numNodes; i++) {
      inOrder.append(std::to_string(in[i]) + " ");
      outOrder.append(std::to_string(out[i]) + " ");
    }
    std::cout << "InOrder:  " << inOrder << std::endl;
    std::cout << "OutOrder: " << outOrder << std::endl;
  }

  bool GraphHasEulerianPath()
  {
    int startNodes = 0;
    int endNodes = 0;

    // Go though inOrder outOrder arrays and
    // check if condition for eularian path is satisfied.
    for (int idx = 0; idx < numNodes; idx++) {
      if (((in[idx] - out[idx]) > 1) || ((out[idx] - in[idx]) > 1)) {
        return false;
      }

      //Condition for start nodes.
      if (out[idx] - in[idx] == 1) {
        startNodes++;
      }

      //Condition for end nodes.
      if (in[idx] - out[idx] == 1) {
        endNodes++;
      }
    }

    if ((startNodes == 0 && endNodes == 0) || //Condition for eulerian circuit
        (startNodes == 1 && endNodes == 1)) { //Eulerian path
      return true;
    }
    return false;
  }

  int GetStartNode()
  {
    int start = 0; //default

    for (int idx = 0; idx < numNodes; idx++) {
      // For eulerian path.
      if (out[idx] - in[idx] == 1) {
        return idx;
      }

      // For eulerian circuit,
      // any node is start node for which there is any one outgoing edge.
      if (out[idx] > 1) {
        start = idx;
      }
    }
    return start;
  }

  void dfs(int at)
  {
    //Till a node has an outgoing edge, it is needed to be traversed.
    while (out[at] != 0) {
      int nextNode = graph[at][--out[at]];
      dfs(nextNode);
    }

    //Once dfs on given node is completed, or
    //there is no way to go further on end node, add it to path.
    eulerianPath.push_front(at);
  }

  void PrintEulerianPath()
  {
    std::cout << "Eulerian path for given path: ";
    while (!eulerianPath.empty()) {
      int node = eulerianPath.front();
      eulerianPath.pop_front();
      std::cout << " -> " << node;
    }
  }

  void FindEulerianPath()
  {
    //Perform setup, calculate In-out order for each node.
    CalculateInOutOrder();

    //Check if graph has eulerial path.
    if (!GraphHasEulerianPath())
    {
      std::cout << "Graph has no eulerian path" << std::endl;
      return;
    }

    //Get the start node and then get the path.
    int startNode = GetStartNode();
    dfs(startNode);

    //All edges are traversed exactly once.
    if (eulerianPath.size() == edgeCnt + 1) {
      PrintEulerianPath();
      return;
    }
    //Graph has disconnected components...
    std::cout << "Eulerian path not exists... Probably graph has disconnected components..!!!" << std::endl;
  }

  //Data members
  int numNodes = 0;
  int edgeCnt = 0;
  int *in;
  int *out;
  std::vector<std::vector<int>> graph;
  std::list<int> eulerianPath;
};



void TestEulerianPath()
{
  EulerianPath p(7);

  //Initialise graph
  p.AddEdge(1, 2);
  p.AddEdge(1, 3);
  p.AddEdge(2, 2);
  p.AddEdge(2, 4);
  p.AddEdge(2, 4);
  p.AddEdge(3, 1);
  p.AddEdge(3, 2);
  p.AddEdge(3, 5);
  p.AddEdge(4, 3);
  p.AddEdge(4, 6);
  p.AddEdge(5, 6);
  p.AddEdge(6, 3);

  //Find eulerian path for given graph.
  p.FindEulerianPath();
}
