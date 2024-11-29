/*
 * Description:
 * Program to minimize the height difference.
 *
 * Created on: 29/11/24
 * @author: Jaspreet Singh, mr.jaspreet2110@gmail.com.
 */

#include <iostream>
#include <vector>

//TC: O(nlogn)
int FindMinimumHeightDifference(std::vector<int> heights, int factor)
{
  int result = 0;
  int n = heights.size();

  //First sort the array
  std::sort(heights.begin(), heights.end());
  //Initial result would be difference b/w smallest and tallest buildings.
  result = heights[n-1] - heights[0];

  //Apply factor and get optimal result
  for (int i = 1; i < n; i++) {
    //If min goes negative, that is invalid case. Skip.
    if (heights[i] - factor < 0) {
      continue;
    }
    //Minimum hieght is smallest height i.e. (heights[0] + factor) or (heights[i] - factor).
    int minH = std::min(heights[0] + factor, heights[i] - factor);

    //Max height is either tallest height i.e. (heights[n-1] - factor) or ith building with increased height.
    // i.e. heights[i - 1] + factor.
    int maxH = std::max(heights[i-1] + factor, heights[n-1] - factor);

    result = std::min(result, maxH - minH);
  }

  return result;
}


void Test_MinimizeHeightDifference()
{
  std::cout << "\nTesting minimize the heights difference" << std::endl;
  std::vector<int> heights = {12, 6, 4, 15, 17, 10};
  int factor = 6;

  std::cout << "Test case 1: minimum height difference: " << FindMinimumHeightDifference(heights, factor) << std::endl;
}
