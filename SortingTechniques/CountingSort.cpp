//
// Created by Jaspreet Singh on 13/08/24.
//
#include <vector>

#include "../Common/Utils.h"

void CountingSort(std::vector<int> &nums)
{
  PrintVector(nums);
  //Find max number in array.
  int max = nums[0];
  for (const int num : nums) {
    max = (num > max) ? num : max;
  }

  //Create a count array of maxVal+1 elements and initialise it with 0.
  std::vector<int> countVec(max + 1, 0);

  //Update count vector with count of each elements count in input array.
  for (const int num : nums) {
    countVec[num]+=1;
  }
  PrintVector(countVec);

  //Find cumulative frequency.
  for (int i=1; i < countVec.size(); i++) {
    countVec[i] += countVec[i-1];
  }
  PrintVector(countVec);

  // Generate sorted array.
  std::vector<int> output(nums.size(), 0);
  for (const int num : nums) {
    int index = countVec[num];
    //std::cout << "Num: " << num << ", idx: " << index << std::endl;
    if (index > 0) {
      output[index-1] = num;
      countVec[num]-=1;
    }
  }
  //std::cout << "Final\n";
  PrintVector(output);

  //Copy back to orignal array.
  nums = output;
}
