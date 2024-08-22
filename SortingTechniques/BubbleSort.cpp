//
// Created by Jaspreet Singh on 11/08/24.
//

#include <iostream>
#include <vector>

void BubbleSort(std::vector<int> &nums)
{
  for (int i=0; i < nums.size(); i++)
  {
    for (int j=i; j < nums.size(); j++) {
      if (nums[i] > nums[j]) {
        int temp = nums[j];
        nums[j] = nums[i];
        nums[i] = temp;
      }
    }
  }
}