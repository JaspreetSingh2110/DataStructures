/*
 * Description:
 *
 * Created on: 01/12/24
 * @author: Jaspreet Singh, mr.jaspreet2110@gmail.com.
 */


#include <iostream>
#include <vector>
#include <queue>

//Approach 1 DFS helper.
void DFS(std::vector<std::vector<int>> &matrix, int row, int col)
{
  int rows = matrix.size();
  int cols = matrix[0].size();
  std::vector<int> dirR = { -1, -1, -1, 0, 0, 1, 1, 1};
  std::vector<int> dirC = { -1, 0, 1, -1, 1, -1, 0, 1};

  //If current cell is 1, reset it to 0.
  matrix[row][col] = 0;

  //Process all directions from given cells.
  for (int i = 0; i < dirR.size(); i++) {
    int newR = row + dirR[i];
    int newC = col + dirC[i];
    if (newR < 0 || newR >= rows || newC < 0 || newC >= cols || matrix[newR][newC] == 0) {
      continue;
    }
    DFS(matrix, newR, newC);
  }
}

//Approach 1: Using DFS.
//We can use separate matrix to keep track of visited cells, or we can modify existing matrix itself.
int CountIslands_DFS(std::vector<std::vector<int>>& matrix)
{
  int islands = 0;
  int rows = matrix.size();
  int cols = matrix[0].size();

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (matrix[i][j] == 1) {
        islands++;
        DFS(matrix, i, j);
      }
    }
  }

  return islands;
}


//Approach 2: BFS helper.
void BFS(std::vector<std::vector<int>> &matrix, int row, int col)
{
  int rows = matrix.size();
  int cols = matrix[0].size();
  std::queue<int> sRow;
  std::queue<int> sCol;
  std::vector<int> dirR = { -1, -1, -1, 0, 0, 1, 1, 1};
  std::vector<int> dirC = { -1, 0, 1, -1, 1, -1, 0, 1};

  sRow.push(row);
  sCol.push(col);

  //Process stack.
  while (!sRow.empty()) {
    int currRow = sRow.front();
    int currCol = sCol.front();
    sRow.pop();
    sCol.pop();
    //Reset the current cell value.
    matrix[currRow][currCol] = 0;

    for (int i = 0; i < dirR.size(); i++) {
      int newR = currRow + dirR[i];
      int newC = currCol + dirC[i];
      //Check bounds.
      if (newR < 0 || newR >= rows || newC < 0 || newC >= cols || (matrix[newR][newC] == 0)) {
        continue;
      }
      sRow.push(newR);
      sCol.push(newC);
    }
  }
}

//Approach 2: Using BFS.
int CountIslands_BFS(std::vector<std::vector<int>>& matrix)
{
  int islands = 0;
  int rows = matrix.size();
  int cols = matrix[0].size();

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (matrix[i][j] == 1) {
        islands++;
        BFS(matrix, i, j);
      }
    }
  }
  return islands;
}

void Test_CountIslands()
{
  std::cout << "\nTest count islands matrix\n";
  std::vector<std::vector<int>> matrix1 =
  { { 1, 1, 0, 0, 0 },
    { 0, 1, 0, 0, 1 },
    { 1, 0, 0, 1, 1 },
    { 0, 0, 0, 0, 0 },
    { 1, 0, 1, 1, 0 } };

  std::vector<std::vector<int>> matrix2 = matrix1;

  std::cout << "DFS: Numbers of islands in given matrix is: " << CountIslands_DFS(matrix1) << std::endl;
  std::cout << "BFS: Numbers of islands in given matrix is: " << CountIslands_BFS(matrix2) << std::endl;
}