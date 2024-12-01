/*
 * Description:
 * Program to calculate island perimeter.
 *
 * Created on: 02/12/24
 * @author: Jaspreet Singh, mr.jaspreet2110@gmail.com.
 */

#include <iostream>
#include <vector>
#include <queue>

//Approach 1 DFS helper.
static void DFS(std::vector<std::vector<int>> &matrix, int row, int col, int& isLandPerimeter)
{
  int rows = matrix.size();
  int cols = matrix[0].size();
  std::vector<int> dirR = { 0, -1, 0, 1};
  std::vector<int> dirC = { -1, 0, 1, 0};

  //If current cell is 1, reset it to 0.
  matrix[row][col] = 0;
  isLandPerimeter++;

  //Process all directions from given cells.
  for (int i = 0; i < dirR.size(); i++) {
    int newR = row + dirR[i];
    int newC = col + dirC[i];
    if (newR < 0 || newR >= rows || newC < 0 || newC >= cols || matrix[newR][newC] == 0) {
      continue;
    }
    DFS(matrix, newR, newC, isLandPerimeter);
  }
}

//Approach 1: Using DFS.
//We can use separate matrix to keep track of visited cells, or we can modify existing matrix itself.
int IslandsPerimeter_DFS(std::vector<std::vector<int>>& matrix)
{
  int islands = 0;
  int rows = matrix.size();
  int cols = matrix[0].size();
  std::vector<int> perimeters;

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (matrix[i][j] == 1) {
        islands++;
        int isLandPerimeter = 0;
        DFS(matrix, i, j, isLandPerimeter);
        perimeters.push_back(isLandPerimeter);
      }
    }
  }

  //Print the islands perimeters.
  for (int i = 0; i < perimeters.size(); i++) {
    std::cout << "Island " << i+1 << " has perimeter: " << perimeters[i] << std::endl;
  }
  return islands;
}


//Approach 2: BFS helper.
static int BFS(std::vector<std::vector<int>> &matrix, int row, int col)
{
  int rows = matrix.size();
  int cols = matrix[0].size();
  std::queue<int> sRow;
  std::queue<int> sCol;
  std::vector<int> dirR = { 0, -1, 0, 1};
  std::vector<int> dirC = { -1, 0, 1, 0};
  int isLandsPerimeter = 0;

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

    //Increase the perimeter by 1.
    isLandsPerimeter++;

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
  return isLandsPerimeter;
}

//Approach 2: Using BFS.
int IslandsPerimeter_BFS(std::vector<std::vector<int>>& matrix)
{
  int islands = 0;
  int rows = matrix.size();
  int cols = matrix[0].size();
  std::vector<int> perimeters;

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (matrix[i][j] == 1) {
        islands++;
        int isLandPerimeter = BFS(matrix, i, j);
        perimeters.push_back(isLandPerimeter);
      }
    }
  }

  //Print the islands perimeters.
  for (int i = 0; i < perimeters.size(); i++) {
    std::cout << "Island " << i+1 << " has perimeter: " << perimeters[i] << std::endl;
  }
  return islands;
}


void Test_IslandsPerimeter()
{
  std::cout << "\nTest count islands matrix\n";
  std::vector<std::vector<int>> matrix1 =
  { { 1, 1, 0, 0, 0 },
    { 0, 1, 0, 0, 1 },
    { 1, 1, 0, 1, 1 },
    { 0, 1, 0, 0, 1 },
    { 1, 1, 1, 1, 0 } };

  std::vector<std::vector<int>> matrix2 = matrix1;

  int resultDFS = IslandsPerimeter_DFS(matrix1);
  std::cout << "DFS: Numbers of islands in given matrix is: " << resultDFS << std::endl;

  int resultBFS = IslandsPerimeter_BFS(matrix2);
  std::cout << "BFS: Numbers of islands in given matrix is: " << resultBFS << std::endl;
}
