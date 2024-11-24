/*
 * Description:
 * Program to find longest consecutive subsequence.
 *
 * Created on: 24/11/24
 * @author: Jaspreet Singh, mr.jaspreet2110@gmail.com.
 */

#include <iostream>
#include <vector>
#include <unordered_set>

//TC: O(n)
int FindLongestConsecutiveSubSequence(const std::vector<int>& nums)
{
  std::unordered_set<int> set;
  int maxLen = 0;

  //Create set to avoid duplicate elements.
  for (int i = 0; i < nums.size(); i++) {
    set.insert(nums[i]);
  }

  //Process elements in set.
  for (int i = 0; i <= nums.size(); i++) {
    //If current element is start element.
    if (set.find(nums[i] - 1) == set.end()) {
      //Find possible consecutive elements.
      int j = nums[i];
      while (set.find(j) != set.end()) {
        j++;
      }
      maxLen = std::max(maxLen, j - nums[i]);
    }
  }

  return maxLen;
}


void Test_FindLongestConsecutiveSubSequence()
{
  std::cout << "\nTest find longest consecutive subsequence\n";
  std::vector<std::vector<int>> nums = {{ 1, 9, 3, 10, 4, 20, 2 }, {36, 41, 56, 35, 44, 33, 34, 92, 43, 32, 42}};

  for (int i = 0; i < nums.size(); i++) {
    std::cout << "TestCase " << i + 1 << ": longest consecutive subsequence is: " << FindLongestConsecutiveSubSequence(nums[i]) << std::endl;
  }
}
