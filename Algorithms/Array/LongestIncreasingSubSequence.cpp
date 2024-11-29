/*
 * Description:
 * Program for finding length of longest increasing sub-sequence.
 *
 * Created on: 29/11/24
 * @author: Jaspreet Singh, mr.jaspreet2110@gmail.com.
 */


#include <iostream>
#include <vector>

//Helper for approach 1.
int LongestIncreasingSubSequenceHelper(std::vector<int>& nums, int endIndex)
{
  //Base case.
  if (endIndex == 0) {
    return 1;
  }

  //Get max length of increasing sub sequence for portions of array.
  int maxLen = 1;
  for (int i = 0; i < endIndex; i++) {
    if (nums[i] < nums[endIndex]) {
      maxLen = std::max(maxLen, LongestIncreasingSubSequenceHelper(nums, i) + 1);
    }
  }

  return maxLen;
}

//Approach 1: Using recursion.
int LongestIncreasingSubSequence_v1(std::vector<int> nums)
{
  int result = 1;
  for(int i = 1; i < nums.size(); i++) {
    result = std::max(result, LongestIncreasingSubSequenceHelper(nums, i));
  }
  return result;
}


int LongestIncreasingSubSequenceHelper_v2(std::vector<int>& nums, int endIndex, std::vector<int>& memo)
{
  //Base condition.
  if (endIndex == 0) {
    return 1;
  }

  //Check if previously computed value exists.
  if (memo[endIndex] != -1) {
    return memo[endIndex];
  }

  //Calculate value if it does not exists.
  int maxLen = 1;
  for (int i = 0; i < endIndex; i++) {
    if (nums[i] < nums[endIndex]) {
      maxLen = std::max(maxLen, LongestIncreasingSubSequenceHelper_v2(nums, i, memo) + 1);
    }
  }

  //Update the memo.
  memo[endIndex] = maxLen;
  return memo[endIndex];
}

//Approach 2: Using recursion with memoization.
//TC: O(n^2)
int LongestIncreasingSubSequence_v2(std::vector<int> nums)
{
  int result = 1;
  std::vector<int> memo(nums.size(), -1);

  for(int i = 1; i < nums.size(); i++) {
    result = std::max(result, LongestIncreasingSubSequenceHelper_v2(nums, i, memo));
  }
  return result;
}


//Approach 3: Using binary search.
int LongestIncreasingSubSequence_v3(std::vector<int> nums)
{
  std::vector<int> result;
  result.push_back(nums[0]);

  for(int i = 1; i < nums.size(); i++) {
    //If current element is greater than last element in result vector, add it to end.
    if (nums[i] > result.back()) {
      result.push_back(nums[i]);
    }
    else {
      //Find proper position for current element in result vector.
      //Find first element in result that is greater than current element.
      int pos = std::lower_bound(result.begin(), result.end(), nums[i]) - result.begin();

      result[pos] = nums[i];
    }
  }

  return result.size();;
}

void Test_LongestIncreasingSubSequence()
{
  std::cout << "\nTest longest increasing sub sequence\n";
  std::vector<int> nums = { 10, 22, 9, 33, 21, 50, 41, 60 };

  std::cout << "Testcase 1: (approach 1) Longest increasing subsequence: " << LongestIncreasingSubSequence_v1(nums) << std::endl;
  std::cout << "Testcase 1: (approach 2) Longest increasing subsequence: " << LongestIncreasingSubSequence_v2(nums) << std::endl;
  std::cout << "Testcase 1: (approach 3) Longest increasing subsequence: " << LongestIncreasingSubSequence_v3(nums) << std::endl;
}