/*
 * Description:
 * Program for finding length of longest alternating sub-sequence.
 *
 * Created on: 29/11/24
 * @author: Jaspreet Singh, mr.jaspreet2110@gmail.com.
 */


#include <iostream>
#include <vector>

int LongestAlternatingSubSequence(std::vector<int> nums)
{
  int inc = 1;
  int dec = 1;

  //Process all elements.
  for (int i = 1; i < nums.size(); i++) {
    if (nums[i] > nums[i - 1]) {
      inc = dec + 1;
    }
    else {
      dec = inc + 1;
    }
  }

  return std::max(inc, dec);
}


void Test_LongestAlternatingSubSequence()
{
  std::cout << "\nTest longest alternating sub sequence\n";
  std::vector<int> nums = {10, 22, 9, 33, 49, 50, 31, 60};

  std::cout << "Testcase 1: Longest alternating subsequence: " << LongestAlternatingSubSequence(nums) << std::endl;
}