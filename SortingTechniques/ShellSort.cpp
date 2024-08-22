//
// Created by Jaspreet Singh on 16/08/24.
//
#include <iostream>
#include <vector>

void ShellSort(std::vector<int> &nums)
{
  for (int gap = nums.size()/2; gap >=1; gap=gap/2) {
    for (int j = gap; j<nums.size(); j++) {
      for (int i= j - gap; i >=0; i=i-gap) {
        if (nums[i+gap] > nums[i]) {
          break;
        }
        else {
          int temp = nums[i];
          nums[i] = nums[i+gap];
          nums[i+gap] = temp;
        }
      }
    }
  }
}