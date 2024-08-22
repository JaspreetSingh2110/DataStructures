//
// Created by Jaspreet Singh on 13/08/24.
//

#include<vector>

void InsertionSort(std::vector<int> &nums)
{
  for (int i=1; i<nums.size(); i++) {
    int temp = nums[i];
    for (int j=i-1; j >= 0; j--) {
      if (temp < nums[j]) {
        nums[j+1] = nums[j];
        nums[j] = temp;
      }
    }
  }
}
