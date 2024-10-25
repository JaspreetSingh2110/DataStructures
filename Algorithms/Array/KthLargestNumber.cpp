/*
 * Description:
 * Find Kth largest number in array.
 * Brute force approach: Sort the array and then find the Kth value.
 *
 * Time complexity: O(n^2) Space complexity: O(1)
 *
 * Created on: 25/10/24
 * @author: Jaspreet Singh, mr.jaspreet2110@gmail.com.
 */

#include <iostream>
#include <vector>

int KthLargestNumber(std::vector<int>& nums, int k)
{
  //Check if finding Kth largest element is possible.
  if (k > nums.size()) {
    return -1;
  }

  //Sort the array.
  std::sort(nums.begin(), nums.end());

  return nums[nums.size() - k];
}


void Test_KthLargestNumber()
{
  std::cout << "\nTest find Kth largest element in array\n";
  std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int k = 3;

  std::cout << "\nOriginal array: ";
  for (int i = 0; i < nums.size(); ++i) {
    std::cout << nums[i] << " ";
  }
  std::cout << "\n3rd largest number in array is: " << KthLargestNumber(nums, k) << std::endl;
}