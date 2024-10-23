/*
* Description:
 * This is optimised approach to calculate amount of trapped water.
 * It uses double pointers.
 *
 * Algorithm:
 * Even though for any given index we calculate the max heights on left and right, but,
 * we use the min of both to calculate stored water.
 * So, using double pointers on left and right, we will use the of both values and
 * calculate stored water.
 *
 * Created on: 23/10/24
 * @author: Jaspreet Singh, mr.jaspreet2110@gmail.com.
 */

#include <iostream>
#include <vector>

int CalculateTrappedWater_OptimisedDoublePointers(std::vector<int> &heights)
{
  int left = 0;
  int right = heights.size() -1;

  int maxLeft = heights[left];
  int maxRight = heights[right];
  int totalTrappedWater = 0;

  while (left <= right) {
    // If height on left is less than right, we can process heights[left].
    if (heights[left] < heights[right]) {
      // If height at current index is less than maxLeft height, water can be stored.
      // Calculate amount of stored water.
      if (maxLeft > heights[left]) {
        totalTrappedWater += maxLeft - heights[left];
      }

      // Calc new maxLeft.
      maxLeft = std::max(maxLeft, heights[left]);
      // Increment left pointer.
      left += 1;
    } else {  //If height on left is less than right, we can process heights[left].
      //If maxRight is greater than current height, water can be stored.
      //Calculate amount of water stored.
      if (maxRight > heights[right]) {
        totalTrappedWater += maxRight - heights[right];
      }
      // Calc new maxRight.
      maxRight = std::max(maxRight, heights[right]);
      //Decrement right pointer.
      right -= 1;
    }
  }
  return totalTrappedWater;
}

void Test_CalculateTrappedWater_OptimisedDoublePointers()
{
  std::cout << "\nTest Calculate Trapped water (optimised using double pointers)\n";
  std::vector<int> arr = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
  int totalWaterTrapped = CalculateTrappedWater_OptimisedDoublePointers(arr);
  std::cout << "Total water trapped: " << totalWaterTrapped << std::endl;
}