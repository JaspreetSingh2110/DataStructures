//
// Created by Jaspreet Singh on 27/09/24.
//

#include <vector>
#include <iostream>
#include <limits>
#include <list>

class FloydWarshall_AllPairShortestPath {
public:

  /* Returns:
   * a. Empty path:
   *      when path[i][j] = INFINITY, [No path exists b/w nodes i and j]
   * b. nullptr:
   *      when path[i][j] = -1, [Negative cycles present for path b/w nodes i and j]
   * c. Valid path.
   */
  std::list<int>* ConstructPath(std::vector<std::vector<double>> &path, std::vector<std::vector<double>> &dp, int src, int dest)
  {
    std::list<int> *fPath = new std::list<int>;

    //Path does not exist.
    if (dp[src][dest] == std::numeric_limits<double>::infinity()) {
      return fPath;
    }

    int i = src;
    for (; i != dest; i = path[i][dest]) {
      //Negative cycles if i==-1.
      if (i == -1) {
        return nullptr;
      }
      fPath->push_back(i);
    }
    //Check for negative cycle.
    if (path[i][dest] == -1) {
      return nullptr;
    }

    fPath->push_back(dest);
    return fPath;
  }

  void PrintAllPairShortestPath(std::vector<std::vector<double>> &next, std::vector<std::vector<double>> &dp, int n)
  {
    //Process all nodes combinations i->j and print its shortest path and cost.
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        std::list<int> *path = ConstructPath(next, dp, i, j);

        std::cout << "Path b/w node " << i << " and node " << j << " : ";
        if (path == nullptr) {
          std::cout << "contains negative cycles!!!" << " ";
        }
        else if (path->empty()) {
          std::cout << "does not exists!!!" << " ";
        }
        else {
          while (!path->empty()) {
            std::cout << path->front() << " -> ";
            path->pop_front();
          }
          std::cout << "[COST: " << dp[i][j] << "]";
        }
        std::cout << std::endl;
        delete path;
      }
    }
  }

  void PrintAllPairShortestPathCost(std::vector<std::vector<double>> &dp, int n)
  {
    std::cout << "Shorted path matrix:" << std::endl;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        std::cout << dp[i][j] << "\t|\t";
      }
      std::cout << std::endl;
    }
    std::cout << std::endl;
  }

  void FloydWarshall_APSS(std::vector<std::vector<double>> &m, std::vector<std::vector<double>> &dp, std::vector<std::vector<double>> &next, int n)
  {
    // Find optimal path using dp.
    for (int k = 0; k < n; k++) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          if (dp[i][k] + dp[k][j] < dp[i][j]) {
            dp[i][j] = dp[i][k] + dp[k][j];
            next[i][j] = next[i][k];
          }
        }
      }
    }

    // Rerun again to identify negative cycles.
    for (int k = 0; k < n; k++) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          if (dp[i][k] + dp[k][j] < dp[i][j]) {
            dp[i][j] = -std::numeric_limits<double>::infinity();
            next[i][j] = -1;
          }
        }
      }
    }
  }

  void FindAPSS(std::vector<std::vector<double>> &m, int n)
  {
    //Create n*n matrix for dynamic programming.
    std::vector<std::vector<double>> dp(n);
    for (int i = 0; i < n; i++) {
      dp[i] = std::vector<double>(n);
    }

    //Create n*n matrix for path recording.
    std::vector<std::vector<double>> next(n);
    for (int i = 0; i < n; i++) {
      next[i] = std::vector<double>(n);
    }

    //Initialise DP and next matrix.
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        dp[i][j] = m[i][j];
        if (m[i][j] != std::numeric_limits<double>::infinity()) {
          next[i][j] = j;
        }
      }
    }

    //Execute algorithm and update dp and next matrix.
    FloydWarshall_APSS(m, dp, next, n);

    //Log the shortest paths cost b/w all nodes.
    PrintAllPairShortestPathCost(dp, n);

    //Log the actual shortest paths b/w all nodes.
    PrintAllPairShortestPath(next, dp, n);
  }
};


void Test_FloydWarshall_AllPairShortestPath()
{
  // Initialise graph matrix.
  int n = 7;  //number of nodes.
  std::vector<std::vector<double>> matrix(n);
  for (int i = 0; i < n; i++) {
    matrix[i] = std::vector<double>(n);
  }

  //Default initialise to infinity.
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      matrix[i][j] = std::numeric_limits<double>::infinity();
      matrix[i][i] = 0;
    }
  }

  // Add edge values.
  matrix[0][1] = 2;
  matrix[0][2] = 5;
  matrix[0][6] = 10;
  matrix[1][2] = 2;
  matrix[1][4] = 11;
  matrix[2][6] = 2;
  matrix[6][5] = 11;
  matrix[4][5] = 1;
  matrix[5][4] = -2;

  //Run algorithm
  FloydWarshall_AllPairShortestPath fw;
  fw.FindAPSS(matrix, n);
}
