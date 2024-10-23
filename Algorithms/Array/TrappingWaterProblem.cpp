/*
 * Description:
 * Algorithm to calculate the amount of water being trapped.
 *
 * Created on: 23/10/24
 * @author: Jaspreet Singh, mr.jaspreet2110@gmail.com.
 */

#include <iostream>
#include <vector>

/*
 * Algorithm:
 * For any given index, find the max heights on right and left sides.
 * As water can be stored only till the height of min of left and right heights,
 * get the mon of right and left.
 * Subtract height of current index with min value of right and left heights.
 *
 * NOTE: Since, there is no wall to left of index 0, we start our loop from index 1.
 */

int CalculateTrappedWater(std::vector<int> &heights)
{
  int left = -1;
  int right = -1;
  int totalWater = 0;

  for (int i = 1; i < heights.size() -1; i++) {
    //Include height at current index for calculation because
    //height at current index might be greater of all.

    //Find max height on left of index i.
    left = heights[i];
    for (int hl = 0; hl < i; hl++) {
      left = std::max(left, heights[hl]);
    }

    //Calculate max height on right side of index i.
    right = heights[i];
    for (int hr = i + 1; hr < heights.size(); hr++) {
      right = std::max(right, heights[hr]);
    }

    //Calculate water being stored at index i.
    //Subtract height of current index with min value of right and left heights.
    totalWater += std::min(left, right) - heights[i];
  }
  return totalWater;
}

int Test_CalculateTrappedWater()
{
  std::cout << "\nTest Calculate Trapped water\n";
  std::vector<int> arr = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
  int totalWaterTrapped = CalculateTrappedWater(arr);
  std::cout << "Total water trapped: " << totalWaterTrapped << std::endl;
}