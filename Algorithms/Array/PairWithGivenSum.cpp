/*
 * Description:
 * Find a pair of numbers whose sum is target value.
 * TC: O(n2)
 *
 * Created on: 11/6/2024
 * @author: Jaspreet Singh, mr.jaspreet2110@gmail.com.
 */

#include <iostream>
#include <vector>

bool FindPairSum(std::vector<int>& nums, int target)
{
  std::vector<int> result = std::vector<int>(2);

  for (int i = 0; i < nums.size(); i++) {
    for (int j = i + 1; j < nums.size(); j++) {
      if (nums[i] + nums[j] == target) {
        result[0] = i;
        result[1] = j;
        return true;
      }
    }
  }
  return false;
}


void Test_FindPairSum()
{
  std::vector<int> nums = {2, 3, 4, 5, 6, 7, 8, 9, 10};

  std::cout << "\nTest find pair sum: " << std::endl;
  std::cout << "Test case #1: ";
  if (FindPairSum(nums, 10) == true) {
    std::cout << "Pair Sum Found" << std::endl;
  } else {
    std::cout << "Pair Sum Not Found" << std::endl;
  }

  std::cout << "Test case #2: ";
  if (FindPairSum(nums, 99) == true) {
    std::cout << "Pair Sum Found" << std::endl;
  } else {
    std::cout << "Pair Sum Not Found" << std::endl;
  }
}
