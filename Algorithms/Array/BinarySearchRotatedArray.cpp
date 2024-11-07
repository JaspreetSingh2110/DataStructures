/*
* Description:
 * Program to search for element in rotated sorted array.
 *
 * Created on: 07/11/24
 * @author: Jaspreet Singh, mr.jaspreet2110@gmail.com.
 */


#include <iostream>
#include <vector>

int BinarySearchRotatedArray(std::vector<int>& nums, int key)
{
  int start = 0;
  int end = nums.size() - 1;

  while (start <= end) {
    int mid = start + (end - start) / 2;

    if (nums[mid] == key) {
      return mid;;
    }

    //Check if left portion is sorted.
    if (nums[start] < nums[mid]) {
      //Check if key, falls in this bucket or other.
      if ((key >= nums[start]) && (key < nums[mid])) {
        end = mid;
      }
      else {
        //This will make search to happen on right partition in next iteration.
        start = mid + 1;
      }
    }
    else {  //Right partition is sorted.
      //Check if key is in right partition.
      if ((key > nums[mid]) && (key <= nums[end])) {
        start = mid + 1;
      }
      else {
        //This will make search to happen on left partition in next iteration.
        end = mid;
      }
    }
  }
  return -1;
}

void Test_BinarySearchRotatedArray()
{
  std::cout << "\nTest Binary search of element in sorted rotated array!!!\n";
  std::vector<int> arr1 = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
  std::vector<int> arr2 = {5,6,1,2,3,4};
  std::vector<int> arr3 = {4,5,6,1,2,3};

  std::cout << "Test case #1: Binary search in rotated sorted array. Index: " << BinarySearchRotatedArray(arr1, 5) << std::endl;
  std::cout << "Test case #2: Binary search in rotated sorted array. Index: " << BinarySearchRotatedArray(arr1, 14) << std::endl;
  std::cout << "Test case #3: Binary search in rotated sorted array. Index: " << BinarySearchRotatedArray(arr1, 2) << std::endl;
  std::cout << "Test case #4: Binary search in rotated sorted array. Index: " << BinarySearchRotatedArray(arr2, 6) << std::endl;
  std::cout << "Test case #5: Binary search in rotated sorted array. Index: " << BinarySearchRotatedArray(arr2, 3) << std::endl;
  std::cout << "Test case #6: Binary search in rotated sorted array. Index: " << BinarySearchRotatedArray(arr2, 4) << std::endl;
  std::cout << "Test case #7: Binary search in rotated sorted array. Index: " << BinarySearchRotatedArray(arr3, 2) << std::endl;
  std::cout << "Test case #8: Binary search in rotated sorted array. Index: " << BinarySearchRotatedArray(arr3, 5) << std::endl;
}