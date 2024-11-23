/*
 * Description:
 * Program to sort 0,1,and 2 in array using Dutch National Flag Algorithm.
 * TC: O(n)
 *
 * Created on: 23/11/24
 * @author: Jaspreet Singh, mr.jaspreet2110@gmail.com.
 */

#include <iostream>
#include <vector>

void Sort012_DutchNationalFlagAlgo(std::vector<int>& nums)
{
  int start = 0;
  int mid = 0;
  int end = nums.size() - 1;

  while (mid <= end) {
    if (nums[mid] == 0) {
      std::swap(nums[start], nums[mid]);
      start++;
      mid++;
    }
    else if (nums[mid] == 1) {
      mid++;
    }
    else if (nums[mid] == 2) {
      std::swap(nums[mid], nums[end]);
      end--;
    }
  }
}


void Test_Sort012_DutchNationalFlagAlgo()
{
  std::cout << "\nTest Sort 012 using Dutch National Flag Algorithm\n";
  std::vector<int> nums{ 0, 1, 2, 0, 1, 2 };

  Sort012_DutchNationalFlagAlgo(nums);
  std::cout << "Sorted numbers: ";
  for (auto num : nums) {
    std::cout << num << " ";
  }
  std::cout << std::endl;
}
