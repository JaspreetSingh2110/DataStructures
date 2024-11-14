/*
 * Description:
 *
 * Created on: 07/11/24
 * @author: Jaspreet Singh, mr.jaspreet2110@gmail.com.
 */

#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::vector<int>> MergeIntervals(std::vector<std::vector<int>>& intervals)
{
  //First sort the intervals.
  std::sort(intervals.begin(), intervals.end());
  std::vector<std::vector<int>> result;

  int current = 0;
  result.push_back(intervals[0]);

  for (int i = 1; i < intervals.size(); i++) {
    //Check if ith interval in index needs to be merged with last element in result.
    if (intervals[i][0] < result[current][1]) {
      result[current][1] = intervals[i][1];
    }
    else {
      result.push_back(intervals[i]);
      current++;
    }
  }

  return result;
}

void Test_MergeIntervals()
{
  std::cout << "\nTesting merging of intervals\n";
  std::vector<std::vector<int>> intervals = {{1,3},{2,4},{5,6},{7,9}, {8,12}};

  std::vector<std::vector<int>> result = MergeIntervals(intervals);
  std::cout << "\nResult: ";
  for (int i = 0; i < result.size(); i++) {
    std::cout << "[" << result[i][0] << "," << result[i][1] << "]-";
  }
  std::cout << std::endl;
}