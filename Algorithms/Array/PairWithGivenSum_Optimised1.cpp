/*
* Description:
 * Find a pair of numbers whose sum is target value.
 * Steps: Sort then binary search for remaining value.
 * TC: O(n*log(n))
 *
 * Created on: 11/6/2024
 * @author: Jaspreet Singh, mr.jaspreet2110@gmail.com.
 */

#include <algorithm>
#include <iostream>
#include <vector>

int BinarySearch(std::vector<int> &arr, int start, int target)
{
  int end = arr.size() - 1;
  while (start <= end) {
    int mid = start + (end - start) / 2;
    if (arr[mid] == target) {
      return mid;
    }

    if (arr[mid] < target) {
      start = mid + 1;
    } else {
      end = mid - 1;
    }
  }
  return -1;
}

bool FindPairSum_Optimised1(std::vector<int>& nums, int target)
{
  std::vector<int> result = std::vector<int>(2);

  //Sort the vector.
  std::sort(nums.begin(), nums.end());

  for (int i = 0; i < nums.size(); i++) {
    int remainderValue = target - nums[i];
    int ret = BinarySearch(nums, i+1, remainderValue);
    if (ret != -1) {
      result[0] = nums[i];
      result[1] = ret;
      return true;
    }
  }
  return false;
}


void Test_FindPairSum_Optimised1()
{
  std::vector<int> nums = {2, 3, 4, 5, 6, 7, 8, 9, 10};

  std::cout << "\nTest find pair sum (Optimised v1): " << std::endl;
  std::cout << "Test case #1: ";
  if (FindPairSum_Optimised1(nums, 10) == true) {
    std::cout << "Pair Sum Found" << std::endl;
  } else {
    std::cout << "Pair Sum Not Found" << std::endl;
  }

  std::cout << "Test case #2: ";
  if (FindPairSum_Optimised1(nums, 99) == true) {
    std::cout << "Pair Sum Found" << std::endl;
  } else {
    std::cout << "Pair Sum Not Found" << std::endl;
  }
}
