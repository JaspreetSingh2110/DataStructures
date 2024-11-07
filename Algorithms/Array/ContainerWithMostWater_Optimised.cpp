/*
 * Description:
 * Given n non-negative integers where each represents a point at coordinate. ‘ n ‘ vertical lines are drawn.
 * Find two lines, which together with x-axis forms a container, such that the container contains the most water
 * TC: O(n)
 *
 * Created on: 07/11/24
 * @author: Jaspreet Singh, mr.jaspreet2110@gmail.com.
 */

#include <iostream>
#include <vector>

int FindMaxWaterContained(std::vector<int> arr)
{
  int start = 0;
  int end = arr.size() - 1;
  int water = 0;

  while (start < end) {
    int minHeight = std::min(arr[start], arr[end]);
    water = std::max(water, minHeight*(end-start));

    if (arr[start] < arr[end]) {
      start = start + 1;
    }
    else {
      end = end - 1;
    }
  }
  return water;
}


void Test_FindMaxWaterContained()
{
 std::cout << "\nTest finding maximum water contained in array!!!\n";
 std::vector<int> arr1 = {1, 5, 4, 3};
 std::vector<int> arr2 = {3, 1, 2, 4, 5};
 std::vector<int> arr3 = {4,5,6,1,2,3};

 std::cout << "Test case #1: Max water contained is: " << FindMaxWaterContained(arr1) << std::endl;
 std::cout << "Test case #2: Max water contained is: " << FindMaxWaterContained(arr2) << std::endl;
 std::cout << "Test case #3: Max water contained is: " << FindMaxWaterContained(arr3) << std::endl;
}