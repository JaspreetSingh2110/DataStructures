//
// Created by Jaspreet Singh on 11/08/24.
//

#include <iostream>
#include <vector>

void SelectionSort(std::vector<int> &nums)
{
  //Iterate through all the elements of array.
  for (int i=0; i<nums.size(); i++) {
    int minIdx = i;
    // Find the min value and respective index.
    for (int j=i+1; j<nums.size(); j++) {
      if (nums[j] < nums[minIdx]) {
        minIdx = j;
      }
    }

    //If min element is not same at ith element, swap it.
    if (i != minIdx) {
      int temp = nums[i];
      nums[i] = nums[minIdx];
      nums[minIdx] = temp;
    }
  }
}