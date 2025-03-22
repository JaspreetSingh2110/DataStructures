/*
 * Description:
 * Program to find smallest positive missing number.
 *
 * Approach 1: Sort and search.
 * TC: O(nlog)
 *
 * Created on: 24/11/24
 * @author: Jaspreet Singh, mr.jaspreet2110@gmail.com.
 */

#include <iostream>
#include <vector>
#include <algorithm>

//Approach 1: Sort and iterate to find.
//TC: O(nlogn)
int FindSmallestPositiveMissingNumber_v1(std::vector<int> nums)
{
  int positiveMissingNumber = 1;
  //Sort the array.
  std::sort(nums.begin(), nums.end());

  //Find missing positive number.
  for (int i = 0; i < nums.size(); i++) {
    if (nums[i] == positiveMissingNumber) {
      positiveMissingNumber++;
    }
  }
  return positiveMissingNumber;
}


//Approach #2: Using visited array.
//TC: O(n), SC: O(n)
int FindSmallestPositiveMissingNumber_v2(std::vector<int> nums)
{
  std::vector<bool> visited(nums.size(), false);

  //Process each element and create visited array.
  for (int i = 0; i < nums.size(); i++) {
    if (nums[i] > 0 && nums[i] <= nums.size()) {
      visited[nums[i] - 1] = true;
    }
  }

  //Find first missing number in range of 1-n.
  for (int i = 0; i < nums.size(); i++) {
    if (!visited[i]) {
      return i + 1;
    }
  }

  //Else size + 1 is missing number.
  return nums.size() + 1;
}


//Approach #3: Using cycle sort.
//TC: O(n), SC: O(1)
int FindSmallestPositiveMissingNumber_v3(std::vector<int> nums)
{
  //Check if each element is at correct index else move them to correct index.
  for (int i = 0; i < nums.size(); i++) {
    //Do not process out of range elements.
    if (nums[i] > 0 && nums[i] <= nums.size()) {
      int expectedIndex = nums[i] - 1;

      //Swap conditions:
      //1. current element is not out of range.
      //2. expected index is not out of bounds.
      //3. ith index is not the expected index and element needs to be moved.
      //4. Element at expected index is same as current element. So swap is not effective, skip. else swap.
      if ((expectedIndex < nums.size()) && (i != expectedIndex) && (nums[expectedIndex] != nums[i])) {
        std::swap(nums[i], nums[expectedIndex]);
      }
    }
  }

  //Iterate again to find the incorrect element.
  for (int i = 0; i < nums.size(); i++) {
    if (nums[i] != i + 1) {
      return i + 1;
    }
  }
  return nums.size() + 1;
}


void Test_FindSmallestPositiveMissingNumber()
{
  std::cout << "\nTest find smallest positive missing number\n";
  std::vector<std::vector<int>> nums = {{2, -3, 4, 1, 1, 7}, {5, 3, 2, 5, 1}, {-8, 0, -1, -4, -3}};

  //Test approach 1.
  for (int i = 0; i < nums.size(); i++) {
    std::cout << "TestCase " << i + 1 << ": (approach 1) Smallest positive missing number: " << FindSmallestPositiveMissingNumber_v1(nums[i]) << std::endl;
  }

  //Test approach 2.
  for (int i = 0; i < nums.size(); i++) {
    std::cout << "TestCase " << i + 1 << ": (approach 2) Smallest positive missing number: " << FindSmallestPositiveMissingNumber_v2(nums[i]) << std::endl;
  }

  //Test approach 3.
  for (int i = 0; i < nums.size(); i++) {
    std::cout << "TestCase " << i + 1 << ": (approach 3) Smallest positive missing number: " << FindSmallestPositiveMissingNumber_v3(nums[i]) << std::endl;
  }
}