/*
 * Description:
 * Program to find the shortest path from src to dest.
 *
 * Approach 1: Using DFS.
 * TC: O(4^rows*cols)
 *
 * //Approach 2: Using BFS.
 * TC: O(rows*cols)
 *
 * Created on: 01/12/24
 * @author: Jaspreet Singh, mr.jaspreet2110@gmail.com.
 */

#include <iostream>
#include <queue>
#include <vector>

//Helper for DFS approach.
void DFS(std::vector<std::vector<int>>& matrix, int si, int sj, int di, int dj, std::vector<std::vector<int>>& visited, int& minDist, int dist)
{
  int rows = matrix.size();
  int cols = matrix[0].size();
  std::vector<int> rDir = {0, -1, 0, 1};
  std::vector<int> cDir = {-1, 0, 1, 0};

  //Check if cell is already visited.
  if (visited[si][sj] == 1) {
    return;
  }

  //If target cell is reached.
  if (si == di && sj == dj) {
    minDist = std::min(minDist, dist);
    return;
  }

  //Mark current cell as visited.
  visited[si][sj] = 1;

  //Do DFS on its neighbours.
  for (int r = 0; r < rDir.size(); r++) {
    int newR = si + rDir[r];
    int newC = sj + cDir[r];
    if (newR < 0 || newR >= rows || newC < 0 || newC >= cols || (matrix[newR][newC] == 0)) {
      continue;
    }
    DFS(matrix, newR, newC, di, dj, visited, minDist, dist + 1);
  }

  //On way back reset the visited.
  visited[si][sj] = 0;
}


//Approach 1: DFS approach.
int FindShortestPathInBinaryMaze_DFS(std::vector<std::vector<int>>& matrix, int si, int sj, int di, int dj)
{
  int rows = matrix.size();
  int cols = matrix[0].size();
  int minDist = INT_MAX;
  std::vector<std::vector<int>> visited(rows, std::vector<int>(cols, 0));

  DFS(matrix, si, sj, di, dj, visited, minDist, 0);
  return minDist;
}


//Approach 2: Using BFS.
int FindShortestPathInBinaryMaze_BFS(std::vector<std::vector<int>>& matrix, int si, int sj, int di, int dj)
{
  int rows = matrix.size();
  int cols = matrix[0].size();
  std::vector<std::vector<int>> visited(rows, std::vector<int>(cols, 0));
  std::vector<int> rDir = {0, -1, 0, 1};
  std::vector<int> cDir = {-1, 0, 1, 0};

  //Create q and initialise it with starting cell.
  std::queue<std::pair<std::pair<int, int>, int>> q;
  q.push(std::make_pair(std::make_pair(si, sj), 0));
  visited[si][sj] = 1;

  //Process the queue elements.
  while (!q.empty()) {
    int cr = q.front().first.first;
    int cc = q.front().first.second;
    int currentSteps = q.front().second;
    q.pop();

    //If target is reached.
    if (cr == di && cc == dj) {
      return currentSteps;
    }

    //Check and add adjacent cells to q.
    for (int r = 0; r < rDir.size(); r++) {
      int newR = cr + rDir[r];
      int newC = cc + cDir[r];
      if (newR < 0 || newR >= rows || newC < 0 || newC >= cols || (matrix[newR][newC] == 0)) {
        continue;
      }
      q.push(std::make_pair(std::make_pair(newR, newC), currentSteps + 1));
    }
  }

  return -1;
}


void Test_FindShortestPathInBinaryMaze()
{
  std::cout << "\nTest shortest path in binary maze\n";
  std::vector<std::vector<int>> matrix =
    {{1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
     {1, 0, 1, 0, 1, 1, 1, 0, 1, 1 },
     {1, 1, 1, 0, 1, 1, 0, 1, 0, 1 },
     {0, 0, 0, 0, 1, 0, 0, 0, 0, 1 },
     {1, 1, 1, 0, 1, 1, 1, 0, 1, 0 },
     {1, 0, 1, 1, 1, 1, 0, 1, 0, 0 },
     {1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
     {1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
     {1, 1, 0, 0, 0, 0, 1, 0, 0, 1 }};

  std::cout << "Testcase 1: (DFS) Shortest path from (0,0) -> (3,4): " << FindShortestPathInBinaryMaze_DFS(matrix, 0, 0, 3, 4) << std::endl;
  std::cout << "Testcase 1: (BFS) Shortest path from (0,0) -> (3,4): " << FindShortestPathInBinaryMaze_BFS(matrix, 0, 0, 3, 4) << std::endl;
}