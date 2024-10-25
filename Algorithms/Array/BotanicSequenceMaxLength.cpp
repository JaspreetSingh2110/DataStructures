/*
 * Description:
 *
 * Created on: 25/10/24
 * @author: Jaspreet Singh, mr.jaspreet2110@gmail.com.
 */

#include <iostream>
#include <vector>

int FindMaxLengthBotanicSequence(std::vector<int>& nums)
{
  int maxLength = 0;
  std::vector<int> incr = std::vector<int>(nums.size(), 0);
  std::vector<int> decr = std::vector<int>(nums.size(), 0);

  incr[0] = 1;
  for (int i = 1; i < nums.size(); i++) {
    incr[i] = 1;
    if (nums[i] > nums[i - 1]) {
      incr[i] = incr[i - 1] + 1;
    }
  }

  decr[nums.size() - 1] = 1;
  for (int i = nums.size() - 2; i >= 0; i--) {
    decr[i] = 1;
    if (nums[i] > nums[i + 1]) {
      decr[i] = decr[i + 1] + 1;
    }
  }

  int max = 0;
  int maxIndex = 0;
  int current = 0;
  for (int i = 0; i < nums.size(); i++) {
    current = incr[i] + decr[i];
    if (current > max) {
      max = current;
      maxIndex = i;
    }
  }
  return max -1;
}


void Test_BotanicSequenceMaxLength()
{
  std::vector<int> nums1 = {12, 4, 78, 90, 45, 23};
  std::vector<int> nums2 = {20, 4, 1, 2, 3, 4, 2, 10};
  std::vector<int> nums3 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::vector<int> nums4 = {0};

  int maxBLen = FindMaxLengthBotanicSequence(nums1);
  std::cout << "Test case #1: Max length botanic sequence: " << maxBLen << std::endl;

  maxBLen = FindMaxLengthBotanicSequence(nums2);
  std::cout << "Test case #2: Max length botanic sequence: " << maxBLen << std::endl;

  maxBLen = FindMaxLengthBotanicSequence(nums3);
  std::cout << "Test case #3: Max length botanic sequence: " << maxBLen << std::endl;

  maxBLen = FindMaxLengthBotanicSequence(nums4);
  std::cout << "Test case #4: Max length botanic sequence: " << maxBLen << std::endl;
}
