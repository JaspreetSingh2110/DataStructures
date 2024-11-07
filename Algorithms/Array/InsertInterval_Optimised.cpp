/*
 * Description:
 * Insert Interval.
 *
 * Created on: 07/11/24
 * @author: Jaspreet Singh, mr.jaspreet2110@gmail.com.
 */


#include <iostream>
#include <vector>

std::vector<std::vector<int>>
InsertInterval_Optimised(std::vector<std::vector<int>> intervals, std::vector<int> interval)
{
  std::vector<std::vector<int>> result;
  int current = 0;

  //Till end value for current interval is lesser than start value of new interval, append it to result.
  while ((current < intervals.size()) && (intervals[current][1] < interval[0])) {
    result.push_back(intervals[current++]);
  }

  //Update the interval with proper values.
  //Update the lower value.
  interval[0] = std::min(interval[0], intervals[current][0]);

  //find the interval, till the end value of interval is >= lower val of current interval.
  while ((current < intervals.size()) && (interval[1] >= intervals[current][0])) {
    interval[1] = std::max(interval[1], intervals[current][1]);
    current++;
  }
  result.push_back(interval);

  while (current < intervals.size()) {
    result.push_back(intervals[current++]);
  }

  return result;
}

void Test_InsertInterval_Optimised()
{
  std::cout << "\nTesting insert interval\n";
  std::vector<std::vector<int>> intervals = {{1,3}, {4,5}, {6,7}, {8,10}};
  std::vector<int> newInterval = {5,6};

  std::vector<std::vector<int>> res = InsertInterval_Optimised(intervals, newInterval);
  std::cout << "Intervals after merge: ";
  for(auto interval : res) {
    std::cout << "[" << interval[0] << "-" << interval[1] << "]-";
  }
  std::cout << "END" << std::endl;
}