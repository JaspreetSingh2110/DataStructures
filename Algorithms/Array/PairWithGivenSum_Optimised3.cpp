/*
* Description:
 * Find a pair of numbers whose sum is target value.
 * Steps: Use hash table.
 * TC: O(n)
 * SC: O(n)
 *
 * Created on: 11/6/2024
 * @author: Jaspreet Singh, mr.jaspreet2110@gmail.com.
 */

#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>


bool FindPairSum_Optimised3(std::vector<int>& nums, int target)
{
  std::vector<int> result = std::vector<int>(2);

  std::unordered_set<int> set;

  for (int i = 0; i < nums.size(); i++) {
    int remValue = target - nums[i];

    //Search for remaining value in hash set.
    auto it = set.find(remValue);
    if (it != set.end()) {
      result[0] = i;
      result[1] = *it;
      return true;
    }

    //If not found, add this value as entry in hash.
    set.insert(nums[i]);
  }

  return false;
}


void Test_FindPairSum_Optimised3()
{
  std::vector<int> nums = {2, 3, 4, 5, 6, 7, 8, 9, 10};

  std::cout << "\nTest find pair sum (Optimised v3): " << std::endl;
  std::cout << "Test case #1: ";
  if (FindPairSum_Optimised3(nums, 10) == true) {
    std::cout << "Pair Sum Found" << std::endl;
  } else {
    std::cout << "Pair Sum Not Found" << std::endl;
  }

  std::cout << "Test case #2: ";
  if (FindPairSum_Optimised3(nums, 99) == true) {
    std::cout << "Pair Sum Found" << std::endl;
  } else {
    std::cout << "Pair Sum Not Found" << std::endl;
  }
}
