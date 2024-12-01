/*
 * Description:
 * Program to search for words in given matrix.
 *
 * Created on: 01/12/24
 * @author: Jaspreet Singh, mr.jaspreet2110@gmail.com.
 */

#include <iostream>
#include <vector>

bool SearchWord(std::vector<std::vector<int>>& matrix, int row, int col, std::string& str)
{
  int rows = matrix.size();
  int cols = matrix[0].size();
  int len = str.size();

  //If first character does not match.
  if (matrix[row][col] != str[0]) {
    return false;
  }

  //All possible directions.
  std::vector<int> dirR = {-1, -1, -1, 0,  0,  1, 1, 1};
  std::vector<int> dirC = {-1,  0,  1, -1, 1, -1, 0, 1};

  //Iterate in all 8 directions.
  for (int dir = 0; dir < 8; dir++) {
    int currX = row + dirR[dir];
    int currY = col + dirC[dir];

    int k = 1;  //First character is already matched at current index
    for (k = 1; k < len; k++) {
      //Check invalid indexes - out of bounds.
      if (currX < 0 || currX >= rows || currY < 0 || currY >= cols) {
        break;
      }
      if (str[k] != matrix[currX][currY]) {
        break;
      }

      //Traverse next cell in same direction.
      currX = currX + dirR[dir];
      currY = currY + dirC[dir];
    }

    if (k == len) {
      return true;
    }
  }

  return false;
}

std::vector<std::pair<int,int>> FindWords(std::vector<std::vector<int>>& matrix, std::string& str)
{
  int rows = matrix.size();
  int cols = matrix[0].size();
  std::vector<std::pair<int,int>> result;

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (SearchWord(matrix, i, j, str))
      {
        result.push_back(std::make_pair(i, j));
      }
    }
  }
  return result;
}


void Test_FindWords()
{
  std::cout << "\nTest find words in matrix\n";
  std::vector<std::vector<int>> matrix =
    {{'a','b','a','b'},
     {'a','b','e','b'},
     {'e','b','e','b'}};
  std::string searchStr = "abe";

  std::vector<std::pair<int,int>> result = FindWords(matrix, searchStr);
  std::cout << "Result: ";
  for (int i = 0; i < result.size(); i++) {
    std::cout << "(" << result[i].first << ", " << result[i].second << ") ";
  }
  std::cout << std::endl;
}