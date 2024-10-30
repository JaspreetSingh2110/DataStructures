//
// Created by Jaspreet Singh on 27/09/24.
//

#include <iostream>
#include <map>
#include <list>
#include <queue>
#include <cstdint>
#include <cstring>

#define MAX 100000

class Dijkstra_SingleSourceShortestPath {
public:
  class Edge {
    public:
    int from;
    int to;
    int weight;

    Edge(int src, int dest, int weight)
    {
      this->from = src;
      this->to = dest;
      this->weight = weight;
    }
  };

  class Node {
    public:
    int id;
    int weight;
    Node(int id, int weight)
    {
      this->id = id;
      this->weight = weight;
    }
  };

  class Comparator {
    public:
    bool operator()(const Node &n1, const Node &n2)
    {
      return n1.weight > n2.weight;
    }
  };

  void AddEdge(int src, int dest, int weight)
  {
    if ((src < 0) || (src >= numNodes) ||
        (dest < 0) || (dest >= numNodes) ||
        (src == dest)) {
      std::cerr << "Invalid Edge Input!!!" << std::endl;
      return;
    }

    graph[src].emplace_back(src, dest, weight);
  }

  Dijkstra_SingleSourceShortestPath() = default;
  explicit Dijkstra_SingleSourceShortestPath(int n)
  {
    if (n <=0) {
      std::cerr << "Invalid node count!!!" << std::endl;
      return;
    }
    this->numNodes = n;
  }

  void FindSSSP(int src, int dest)
  {
    int32_t dist[numNodes];
    int32_t prev[numNodes];

    memset(prev, -1, sizeof(prev));
    for (int i = 0; i < numNodes; i++) {
      dist[i] = MAX;
    }
    dist[src] = 0;

    //Run the algorithm implementation.
    Dijkstra(src, dist, prev);

    //Check if valid path present.
    if (prev[dest] == -1) {
      std::cerr << "No valid path found b/w node: " << src << ", dest: " << dest << " !!!" << std::endl;
      return;
    }

    //Construct path.
    std::list<int> path;
    int cost = 0;
    for (int i = dest; i != -1; i = prev[i]) {
      path.push_back(i);
      cost += dist[i];
    }
    path.reverse();

    //Print path
    for (int &node : path) {
      std::cout << node << "  ";
    }
    std::cout << " [COST: " << cost << "]" << std::endl;
  }

  void Dijkstra(int src, int32_t dist[], int32_t prev[])
  {
    bool visited[numNodes];
    std::priority_queue<Node, std::vector<Node>, Comparator> pq;

    memset(visited, false, sizeof(visited));
    pq.push({src, 0});

    //Iterate over all elements in priority queue
    while (!pq.empty()) {
      //Get the first optimal edge
      Node node = pq.top();
      pq.pop();
      visited[node.id] = true;

      //If the node being popped is duplicate entry of already visited node
      //and has optimal path found, skip processing it.
      if (dist[node.id] < node.weight) {
        continue;
      }

      //Iterate over neighbour nodes of current node.
      for (auto &edge : graph[node.id]) {
        //If already visited, skip processing.
        if (visited[edge.to]) {
          continue;
        }

        //Weight to reach neighbor node is current wight + edge weight to reach next node.
        int newWeight = dist[edge.from] + edge.weight;
        if (dist[edge.to] > newWeight) {
          dist[edge.to] = newWeight;
          prev[edge.to] = edge.from;
          pq.push({edge.to, newWeight});
        }
      }
    }
  }

  //Data members
  int numNodes = 0;
  std::map<int, std::list<Edge>> graph;
};

void Test_Dijkstra_SingleSourceShortestPath()
{
  //Initialise graph.
  Dijkstra_SingleSourceShortestPath dijkstra(5);
  dijkstra.AddEdge(0, 1, 2);
  dijkstra.AddEdge(0, 2, 1);
  dijkstra.AddEdge(1, 3, 3);
  dijkstra.AddEdge(2, 1, 2);
  dijkstra.AddEdge(2, 4, 4);
  dijkstra.AddEdge(3, 4, 4);

  //Run Algorithm.
  std::cout << "Find shortest path b/w node 0 and 1 !!!" << std::endl;
  dijkstra.FindSSSP(0, 1);
  std::cout << "Find shortest path b/w node 0 and 4 !!!" << std::endl;
  dijkstra.FindSSSP(0, 4);

}