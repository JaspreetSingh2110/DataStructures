/*
 * Description:
 * Program to find leaders in array.
 * Leaders are those elements for which it is greatest of all elements to its right.
 * NOTE: Right most element is always a leader.
 * This is brute force approach.
 *
 * Time complexity: O(n^2), Space complexity: O(1)
 *
 * Created on: 24/10/24
 * @author: Jaspreet Singh, mr.jaspreet2110@gmail.com.
 */

#include <iostream>
#include <vector>

std::vector<int> FindLeaders(std::vector<int>& nums)
{
  std::vector<int> leaders;

  //Iterate over all numbers.
  for (int i = 0; i < nums.size(); i++) {
    bool isLeader = true;
    //Iterate over all to the right of element at index 'i'.
    //Check if it greatest of all right element. Mark it as leader.
    for (int j = i + 1; j < nums.size(); j++) {
      if (nums[j] > nums[i]) {
        isLeader = false;
        break;
      }
    }
    //Right most element is always a leader.
    if (isLeader || (i == nums.size() - 1)) {
      leaders.push_back(nums[i]);
    }
  }
  return leaders;
}


void Test_FindLeaders()
{
  std::cout << "\nTest Find leaders in array\n";
  std::vector<int> nums = {16, 17, 4, 3, 5, 2};

  std::vector<int> leaders = FindLeaders(nums);
  for (int i = 0; i < leaders.size(); i++) {
    std::cout << leaders[i] << " ";
  }
  std::cout << std::endl;
}