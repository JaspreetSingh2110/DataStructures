/*
* Description:
 * Find a pair of numbers whose sum is target value.
 * Steps: Sort then use double pointer to reach target value.
 * TC: O(n*log(n))
 *
 * Created on: 11/6/2024
 * @author: Jaspreet Singh, mr.jaspreet2110@gmail.com.
 */

#include <algorithm>
#include <iostream>
#include <vector>


bool FindPairSum_Optimised2(std::vector<int>& nums, int target)
{
  std::vector<int> result = std::vector<int>(2);

  //Sort the vector.
  std::sort(nums.begin(), nums.end());

  int start = 0;
  int end = nums.size() - 1;

  //Use double pointer approach to reach the target sum.
  while (start < end) {
    int sum = nums[start] + nums[end];
    if (sum == target) {
      result[0] = start;
      result[1] = end;
      return true;
    }

    if (sum < target) {
      start++;
    } else {
      end--;
    }
  }

  return false;
}


void Test_FindPairSum_Optimised2()
{
  std::vector<int> nums = {2, 3, 4, 5, 6, 7, 8, 9, 10};

  std::cout << "\nTest find pair sum (Optimised v2): " << std::endl;
  std::cout << "Test case #1: ";
  if (FindPairSum_Optimised2(nums, 10) == true) {
    std::cout << "Pair Sum Found" << std::endl;
  } else {
    std::cout << "Pair Sum Not Found" << std::endl;
  }

  std::cout << "Test case #2: ";
  if (FindPairSum_Optimised2(nums, 99) == true) {
    std::cout << "Pair Sum Found" << std::endl;
  } else {
    std::cout << "Pair Sum Not Found" << std::endl;
  }
}
