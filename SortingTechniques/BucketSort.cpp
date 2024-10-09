//
// Created by Jaspreet Singh on 01/09/24.
//

#include <iostream>
#include <vector>
#include <algorithm>

int GetMaxElement(std::vector<int> nums)
{
  int max = nums[0];
  for (int i = 1; i < nums.size(); i++) {
    if (nums[i] > max) {
      max = nums[i];
    }
  }
  return max;
}

void BucketSort(std::vector<int> &nums)
{
  int max = GetMaxElement(nums);
  int bucketCnt = 5;
  int divisor = (max/bucketCnt) + 1;
  std::vector<int> buckets[bucketCnt];

  //Arrange numbers into buckets
  for (int num : nums) {
    buckets[num / divisor].push_back(num);
  }

  //Print buckets.
  /*
  for (int i = 0; i < bucketCnt; i++) {
    std::cout << "Bucket: " << i << std::endl;
    for (int j = 0; j < buckets[i].size(); j++) {
      std::cout << buckets[i][j] << " ";
    }
    std::cout << std::endl;
    std::cout << "****************************************" << std::endl;
  }
  */

  // Sort each bucket contents.
  for (int i = 0; i < bucketCnt; i++) {
    std::sort(buckets[i].begin(), buckets[i].end());
  }

  //Merge elements back to original vector.
  nums.clear();
  for (int i = 0; i < bucketCnt; i++) {
    for (int j : buckets[i]) {
      nums.push_back(j);
    }
  }
}