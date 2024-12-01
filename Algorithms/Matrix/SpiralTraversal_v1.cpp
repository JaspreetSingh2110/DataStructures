/*
 * Description:
 * Spiral traversal of matrix.
 * TC: O(m*n), SC: O(m*n)
 *
 * Created on: 08/11/24
 * @author: Jaspreet Singh, mr.jaspreet2110@gmail.com.
 */

#include <iostream>
#include <vector>

void SpiralTraversal_v1(std::vector< std::vector<int> > &matrix)
{
  int rows = matrix.size();
  int cols = matrix[0].size();

  //direction vectors Right, Down, Left, Up.
  int tr[] = {0, 1, 0, -1};
  int tc[] = {1, 0 , -1, 0};

  // For trace.
  std::vector< std::vector<int> > spiral(rows, std::vector<int>(cols, 0));

  int row = 0;
  int col = 0;
  int di = 0; // initial direction index.

  //Iterate till all cells are processed.
  for (int i = 0; i < rows*cols; i++) {
    //Print the element.
    std::cout << matrix[row][col] << " ";

    //Update trace matrix
    spiral[row][col] = 1;

    //Get new row and col index.
    int nrow = row + tr[di];
    int ncol = col + tc[di];

    //If new row and col are within bounds.
    if ((nrow >=0 && nrow < rows && ncol >=0 && ncol < cols) && (spiral[nrow][ncol] != 1)) {
      row = nrow;
      col = ncol;
    }
    else { //When it crosses bounds, update to next direction index.
      di = (di + 1) % 4;
      row = row + tr[di];
      col = col + tc[di];
    }
  }
}

void Test_SpiralTraversal_v1()
{
  std::cout << "\nTest Spiral traversal of matrix:" << std::endl;
  std::vector< std::vector<int> > matrix =
    {
    {1,  2,  3,  4,  5,  6},
    {7,  8,  9,  10, 11, 12},
    {13, 14, 15, 16, 17, 18},
    {19, 20, 21, 22, 23, 24},
    {25, 26, 27, 28, 29, 30},
    };

  std::cout << "Matrix:" << std::endl;
  for (int i = 0; i < matrix.size(); i++) {
    for (int j = 0; j < matrix[i].size(); j++) {
      std::cout << matrix[i][j] << "\t";
    }
    std::cout << std::endl;
  }

  std::cout << "Spiral traversal\n";
  SpiralTraversal_v1(matrix);
  std::cout << std::endl;
}