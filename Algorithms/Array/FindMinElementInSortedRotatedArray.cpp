/*
 * Description:
 * Program to find min element in rotated sorted array.
 * TC: O(logn) - Use binary search approach.
 *
 * Created on: 07/11/24
 * @author: Jaspreet Singh, mr.jaspreet2110@gmail.com.
 */


#include <iostream>
#include <vector>

int FindMinElement(std::vector<int>& nums)
{
  int start = 0;
  int end = nums.size() - 1;

  while (start < end) {
    if (nums[start] < nums[end]) {
      return nums[start];
    }

    int mid = start + (end - start) / 2;
    if (nums[mid] > nums[start]) {
      start = mid + 1;
    }
    else {
      end = mid;
    }
  }
  return nums[start];
}

void Test_FindMinElement()
{
  std::cout << "\nTest finding minimum element in array!!!\n";
  std::vector<int> arr1 = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
  std::vector<int> arr2 = {5,6,1,2,3,4};
  std::vector<int> arr3 = {4,5,6,1,2,3};

  std::cout << "Test case #1: Minimum element in given array is: " << FindMinElement(arr1) << std::endl;
  std::cout << "Test case #1: Minimum element in given array is: " << FindMinElement(arr2) << std::endl;
  std::cout << "Test case #1: Minimum element in given array is: " << FindMinElement(arr3) << std::endl;
}