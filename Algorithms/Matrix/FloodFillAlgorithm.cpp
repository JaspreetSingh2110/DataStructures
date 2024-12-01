/*
 * Description:
 * Program for implementation of flood fill algorithm using BFS and DFS.
 *
 * Created on: 01/12/24
 * @author: Jaspreet Singh, mr.jaspreet2110@gmail.com.
 */

#include <iostream>
#include <vector>
#include <queue>

//Helper
void PrintMatrix(std::vector<std::vector<int>> &matrix)
{
  for (int i = 0; i < matrix.size(); i++) {
    for (int j = 0; j < matrix[0].size(); j++) {
      std::cout << matrix[i][j] << " ";
    }
    std::cout << std::endl;
  }
}

//Approach 1: Helper DFS.
void DFS(std::vector<std::vector<int>>& matrix, int row, int col, int newVal)
{
  int rows = matrix.size();
  int cols = matrix[0].size();
  std::vector<int> dirR = {0, -1, 0, 1};
  std::vector<int> dirC = {-1, 0, 1, 0};

  if (row < 0 || row >= rows || col < 0 || col >= cols) {
    return;
  }
  if (matrix[row][col] == 1) {
    //Update current cell value.
    matrix[row][col] = newVal;

    //Process adjacent cells.
    for (int i = 0; i < dirR.size(); i++) {
      int newR = row + dirR[i];
      int newC = col + dirC[i];
      DFS(matrix, newR, newC, newVal);
    }
  }
}

//Approach 1: Using DFS and inplace replacement.
void FloodFill_DFS(std::vector<std::vector<int>>& matrix, int newVal, int i, int j)
{
  if (matrix[i][j] == 1) {
    DFS(matrix, i, j, newVal);
  }
}


//Approach 2: Helper BFS.
void BFS(std::vector<std::vector<int>>& matrix, int row, int col, int newVal)
{
  int rows = matrix.size();
  int cols = matrix[0].size();
  std::vector<int> dirR = {0, -1, 0, 1};
  std::vector<int> dirC = {-1, 0, 1, 0};

  std::queue<int> sRow;
  std::queue<int> sCol;
  sRow.push(row);
  sCol.push(col);

  //Process stack elements.
  while (!sRow.empty()) {
    int r = sRow.front();
    int c = sCol.front();
    sRow.pop();
    sCol.pop();

    //Update color of current cell.
    matrix[r][c] = newVal;

    //Add adjacent cells to stack.
    for (int i = 0; i < dirR.size(); i++) {
      int newR = r + dirR[i];
      int newC = c + dirC[i];

      //Check bounds.
      if (newR < 0 || newR >= rows || newC < 0 || newC >= cols) {
        continue;
      }

      if (matrix[newR][newC] == 1) {
        sRow.push(newR);
        sCol.push(newC);
      }
    }
  }
}

//Approach 2: Using DFS and inplace replacement.
void FloodFill_BFS(std::vector<std::vector<int>>& matrix, int newVal, int i, int j)
{
  if (matrix[i][j] == 1) {
    BFS(matrix, i, j, newVal);
  }
}


void Test_FloodFillAlgorithm()
{
  std::cout << "\nTest Flood fill algorithm\n";
  std::vector<std::vector<int>> matrix1 =
  { {1, 1, 1},
    {1, 1, 0},
    {1, 0, 1} };

  std::vector<std::vector<int>> matrix2 = matrix1;

  std::cout << "Approach 1: DFS: \n";
  FloodFill_DFS(matrix1, 3, 1, 1);
  PrintMatrix(matrix1);

  std::cout << "Approach 2: BFS: \n";
  FloodFill_BFS(matrix2, 3, 1, 1);
  PrintMatrix(matrix2);
}
