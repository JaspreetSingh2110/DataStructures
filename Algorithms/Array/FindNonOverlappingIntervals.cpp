/*
* Description:
 *
 * Created on: 07/11/24
 * @author: Jaspreet Singh, mr.jaspreet2110@gmail.com.
 */

#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::vector<int>> FindNonOverlappingIntervals(std::vector<std::vector<int>>& intervals)
{
  //First sort the intervals.
  std::sort(intervals.begin(), intervals.end());
  std::vector<std::vector<int>> result;

  for (int i = 1; i < intervals.size(); i++) {
    if (intervals[i][0] > intervals[i - 1][1]) {
      result.push_back({intervals[i-1][1], intervals[i][0]});
    }
  }

  return result;
}

void Test_FindNonOverlappingIntervals()
{
  std::cout << "\nTesting find non overlapping intervals\n";
  std::vector<std::vector<int>> intervals = { {1, 3}, {9, 12}, {2, 4}, {6, 8} };

  std::vector<std::vector<int>> result = FindNonOverlappingIntervals(intervals);
  std::cout << "\nResult: ";
  for (int i = 0; i < result.size(); i++) {
    std::cout << "[" << result[i][0] << "," << result[i][1] << "]-";
  }
  std::cout << std::endl;
}