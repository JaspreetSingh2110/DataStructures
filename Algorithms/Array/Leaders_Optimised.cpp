/*
* Description:
 * Program to find leaders in array.
 * Leaders are those elements for which it is greatest of all elements to its right.
 * NOTE: Right most element is always a leader.
 * This is optimised approach.
 *
 * Time complexity: O(n), Space complexity: O(1)
 *
 * Created on: 24/10/24
 * @author: Jaspreet Singh, mr.jaspreet2110@gmail.com.
 */

#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> FindLeaders_Optimised(std::vector<int>& nums)
{
  std::vector<int> leaders;

  if (nums.empty()) {
    return leaders;
  }
  //In this optimised approach, traverse the array from right to left.
  //Keep track of highest element, and whenever high element is found, add it into leaders.

  //Set rightmost element as current high and push it in leaders array.
  int currentHigh = nums[nums.size() - 1];
  leaders.push_back(currentHigh);

  for (int i = nums.size()-2; i>=0; i--) {
    if (nums[i] > currentHigh) {
      currentHigh = nums[i];
      leaders.push_back(currentHigh);
    }
  }

  //reverse the leaders as we iterated backwards.
  std::reverse(leaders.begin(), leaders.end());
  return leaders;
}


void Test_FindLeaders_Optimised()
{
  std::cout << "\nTest Find leaders in array\n";
  std::vector<int> nums = {16, 17, 4, 3, 5, 2};

  std::vector<int> leaders = FindLeaders_Optimised(nums);
  for (int i = 0; i < leaders.size(); i++) {
    std::cout << leaders[i] << " ";
  }
  std::cout << std::endl;
}