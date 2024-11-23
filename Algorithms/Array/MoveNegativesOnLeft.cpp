/*
* Description:
 * Program to move all negatives on left.
 *
 * Approach #1: Using partition process of quick sort.
 * Approach #2: Using 2 pointer.
 * TC: O(n)
 *
 * Created on: 23/11/24
 * @author: Jaspreet Singh, mr.jaspreet2110@gmail.com.
 */

#include <iostream>
#include <vector>

//Approach #1: Using partition approach of quick sort.
//TC: O(n)
void MoveNegativesToLeft_v1(std::vector<int>& nums)
{
  int j = 0;
  for (int i = 0; i < nums.size(); i++) {
    if (nums[i] < 0) {
      if (i != j) {
        std::swap(nums[i], nums[j]);
      }
      //After reaching first positive integer, it will always point to positive integer.
      j++;
    }
  }
}


//Approach #2: Using 2 pointer.
//TC: O(n)
void MoveNegativesToLeft_v2(std::vector<int>& nums)
{
  int left = 0;
  int right = nums.size() - 1;

  while (left < right) {
    if (nums[left] < 0) {
      left++;
    }
    else if (nums[right] >= 0) {
      right--;
    }
    else {
      std::swap(nums[left], nums[right]);
      left++;
      right--;
    }
  }
}


void Test_MoveNegativesToLeft()
{
  std::cout << "\nTest move negatives elements on left.\n";
  std::vector<int> nums{ -1, -2, 2, 1, -3, 4 };

  MoveNegativesToLeft_v1(nums);
  std::cout << "Result vector (Approach #1): ";
  for (auto num : nums) {
    std::cout << num << " ";
  }
  std::cout << std::endl;

  nums = { -1, -2, 2, 1, -3, 4 };
  MoveNegativesToLeft_v2(nums);
  std::cout << "Result vector (Approach #2): ";
  for (auto num : nums) {
    std::cout << num << " ";
  }
  std::cout << std::endl;
}
