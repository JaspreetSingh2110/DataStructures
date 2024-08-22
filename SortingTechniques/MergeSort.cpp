//
// Created by Jaspreet Singh on 15/08/24.
//
#include <iostream>

#include "../Common/Utils.h"

void Merge(std::vector<int> &nums, int begin, int mid, int end)
{
  //std::cout << "Vector before: " << endl;
  //PrintVector(nums);
  //std::cout << "begin: " << begin << ", mid: " << mid << ", end: " << end << std::endl;
  int i = begin;
  int j = mid + 1;
  int k = 0;
  std::vector<int> temp(end-begin +1, 0);

  while ((i <= mid) && (j <= end)) {
    if (nums[i] < nums[j]) {
      temp[k++] = nums[i++];
    }
    else {
      temp[k++] = nums[j++];
    }
  }
  while(i<=mid) {
    temp[k++] = nums[i++];
  }
  while(j<=end) {
    temp[k++] = nums[j++];
  }

  //Copy back data from temp to original vector.
  i = begin;
  j = 0;
  while (i <= end) {
    nums[i++] = temp[j++];
  }

  //std::cout << "Vector after sort temp: " << endl;
  //PrintVector(nums);
}

void MergeSort(std::vector<int> &nums, int begin, int end)
{
  if (begin < end)
  {
    int mid = (begin + end) / 2;
    MergeSort(nums, begin, mid);  //Divide first half.
    MergeSort(nums, mid + 1, end);  //Divide second half.
    Merge(nums, begin, mid, end);   // Merge the halves in sorted way.
  }
}
