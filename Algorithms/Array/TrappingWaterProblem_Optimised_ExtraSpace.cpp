/*
 * Description:
 * This is optimised approach to calculate amount of trapped water.
 * It uses extra space O(n) to first calculate max left and right heights and
 * then calculate trapped water amount.
 *
 * Created on: 23/10/24
 * @author: Jaspreet Singh, mr.jaspreet2110@gmail.com.
 */

#include <iostream>
#include <vector>

int CalculateTrappedWater_OptimisedUsingSpace(std::vector<int> &heights)
{
  //Extra memory.
  std::vector<int> left = std::vector<int>(heights.size(), 0);
  std::vector<int> right = std::vector<int>(heights.size(), 0);

  //First calculate left max heights for each index.
  left[0] = heights[0];
  for (int i = 1; i < heights.size(); i++) {
    left[i] = std::max(left[i-1], heights[i]);
  }

  //Calculate right max heights for each index.
  right[heights.size() - 1] = heights[heights.size() - 1];
  for (int i = heights.size() -2; i >=0; i--) {
    right[i] = std::max(right[i+1], heights[i]);
  }

  //Calculate trapped water.
  int totalTrappedWater = 0;
  for (int i = 0; i < heights.size(); i++) {
    //totalTrappedWater += std::min(left[i], right[i]) - heights[i];
    int minHeight = std::min(left[i], right[i]);
    if (minHeight > heights[i]) {
      totalTrappedWater += (minHeight - heights[i]);
    }
  }
  return totalTrappedWater;
}

void Test_CalculateTrappedWater_OptimisedUsingSpace()
{
 std::cout << "\nTest Calculate Trapped water (optimised using extra space)\n";
 std::vector<int> arr = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
 int totalWaterTrapped = CalculateTrappedWater_OptimisedUsingSpace(arr);
 std::cout << "Total water trapped: " << totalWaterTrapped << std::endl;
}