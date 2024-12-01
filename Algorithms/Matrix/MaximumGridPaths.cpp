/*
 * Description:
 * Program to calculate max possible paths to reach from top left cell to bottom right.
 *
 * Created on: 01/12/24
 * @author: Jaspreet Singh, mr.jaspreet2110@gmail.com.
 */

#include <iostream>
#include <vector>

//Approach 1: Recursion with memoization.
int MaximumGridPaths(int row, int col, std::vector<std::vector<int>>& memo)
{
  //Base case.
  if (row == 1 || col == 1) {
    memo[row][col] = 1;
    return memo[row][col];
  }
  //If already computed value exists in memo.
  if (memo[row][col] != 0) {
    return memo[row][col];
  }

  //Calculate value for given cell.
  memo[row][col] = MaximumGridPaths(row, col - 1, memo) + MaximumGridPaths(row - 1, col, memo);
  return memo[row][col];
}

int MaximumGridPaths(int row, int col)
{
  std::vector<std::vector<int>> memo(row + 1, std::vector<int>(col + 1, 0));
  return MaximumGridPaths(row, col, memo);
}

void Test_FindMaximumGridPaths()
{
  std::cout << "\nTesting Find Maximum Grid Paths" << std::endl;


  std::cout << "Testcase1: Max path in cells (1x1) is : " << MaximumGridPaths(1, 1) << std::endl;
  std::cout << "Testcase2: Max path in cells (2x2) is : " << MaximumGridPaths(2, 2) << std::endl;
  std::cout << "Testcase3: Max path in cells (3x3) is : " << MaximumGridPaths(3, 3) << std::endl;
  std::cout << "Testcase4: Max path in cells (4x4) is : " << MaximumGridPaths(4, 4) << std::endl;
}
