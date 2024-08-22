//
// Created by Jaspreet Singh on 16/08/24.
//
#include <iostream>

#include "../Common/Utils.h"

int GetPivotIndex(std::vector<int> &nums, int low, int high)
{
  ///std::cout << __func__ << "::" << __LINE__ << ":: low: " << low << ", high: " << high << std::endl;
  //PrintVector(nums);
  int pivot = low;
  int temp;
  int i = low;
  int j = high;
  while (i < j) {
    while ((i<j) && (nums[i] <= nums[pivot]))  {
      i++;
    }
    while ((j >=low) && (nums[j] > nums[pivot])) {
      j--;
    }
    if (i < j) {
      temp = nums[i];
      nums[i] = nums[j];
      nums[j] = temp;
    }
  }
  temp = nums[pivot];
  nums[pivot] = nums[j];
  nums[j] = temp;
  pivot = j;

  //std::cout << pivot << std::endl;
  return pivot;
}

void QuickSort(std::vector<int> &nums, int low, int high)
{
  int pivot;
  if (low < high) {
    pivot = GetPivotIndex(nums, low, high);
    QuickSort(nums, low, pivot -1);
    QuickSort(nums, pivot +1, high);
  }
}