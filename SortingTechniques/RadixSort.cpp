//
// Created by Jaspreet Singh on 01/09/24.
//

#include <iostream>
#include <vector>

int GetMaxElementInArray(std::vector<int> nums)
{
  int max = nums[0];
  for (int i = 1; i < nums.size(); i++) {
    if (nums[i] > max) {
      max = nums[i];
    }
  }
  return max;
}

void CountSort(std::vector<int> &nums, int exp)
{
  int cntArr[10] = {0};
  std::vector<int> output(nums.size(), 0);

  //Populate count array.
  for (int num : nums) {
    cntArr[(num / exp) % 10]++;
  }

  //Create cumulative CntArr.
  for (int i = 1; i < 10; i++) {
    cntArr[i] += cntArr[i - 1];
  }

  for (int i = nums.size() - 1; i >= 0; i--) {
    int idx = cntArr[(nums[i] / exp) % 10] - 1;
    output[idx] = nums[i];
    cntArr[(nums[i] / exp) % 10]--;
  }

  //Move elements from output to nums.
  nums.clear();
  for (int i : output) {
    nums.push_back(i);
  }
}

void RadixSort(std::vector<int> &nums)
{
  int max = GetMaxElementInArray(nums);

  //Execute the loop for each decimal position
  for (int idx = 1; max/idx > 0 ; idx*=10) {
    CountSort(nums, idx);
  }
}