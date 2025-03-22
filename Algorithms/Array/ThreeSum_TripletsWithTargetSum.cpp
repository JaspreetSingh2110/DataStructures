/*
 * Description:
 * Program to find pairs of elements in array that sums to target sum.
 *
 * Created on: 24/11/24
 * @author: Jaspreet Singh, mr.jaspreet2110@gmail.com.
 */

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

//Approach 1: Sort + two pointers approach.
//TC: O(nlogn)
std::vector<int> FindTripletsWithTargetSum_v1(std::vector<int>& nums, int target)
{
  std::vector<int> triplets;

  //Sort the array.
  std::sort(nums.begin(), nums.end());

  for (int i = 0; i < nums.size() - 2; i++) {
    int left = i+1;
    int right = nums.size()- 1;

    while (left < right) {
      int sum = nums[i] + nums[left] + nums[right];
      if (sum == target) {
        triplets.push_back(nums[i]);
        triplets.push_back(nums[left]);
        triplets.push_back(nums[right]);
        return triplets;
      }
      else if (sum < target) {
        left++;
      }
      else {
        right--;
      }
    }
  }

  return triplets;
}


//Approach 2: Using hashMap.
//TC: O(n)
std::vector<int> FindTripletsWithTargetSum_v2(std::vector<int>& nums, int target)
{
  std::vector<int> triplets;
  std::unordered_set<int> set;

  for (int i = 0; i < nums.size() - 2; i++) {
    //Reset set.
    set.clear();

    //Now find pair from remaining elements.
    for (int j = i + 1; j < nums.size(); j++) {
      if (set.find(target - (nums[i] + nums[j])) != set.end()) {
        triplets.push_back(nums[i]);
        triplets.push_back(nums[j]);
        triplets.push_back(target - (nums[i] + nums[j]));
      }

      //Insert element into set.
      set.insert(nums[j]);
    }
  }

  return triplets;
}


void Test_FindTripletsWithTargetSum()
{
  std::vector<int> nums1 = { 1, 4, 45, 6, 10, 8 };
  std::vector<int> nums2 = {1, 1, 1, 1};
  int targetSum1 = 22;
  int targetSum2 = 3;

  std::cout << "\nTest find triplets with given target sum\n";

  /*********** Test approach 1 ***********************************************/
  std::cout << "TestCase 1: (approach #1): Triplets found with target sum: ";
  std::vector<int> res = FindTripletsWithTargetSum_v1(nums1, targetSum1);
  for (int i = 0; i < res.size(); i+=3) {
    std::cout << "(" << res[i] << " " << res[i+1] << " " << res[i+2] << ") ";
  }
  std::cout << std::endl;

  std::cout << "TestCase 2: (approach #1): Triplets found with target sum: ";
  res = FindTripletsWithTargetSum_v1(nums2, targetSum2);
  for (int i = 0; i < res.size(); i+=3) {
    std::cout << "(" << res[i] << " " << res[i+1] << " " << res[i+2] << ") ";
  }
  std::cout << std::endl;

  /*********** Test approach 2 ***********************************************/
  std::cout << "TestCase 1: (approach #2): Triplets found with target sum: ";
  res = FindTripletsWithTargetSum_v2(nums1, targetSum1);
  for (int i = 0; i < res.size(); i+=3) {
    std::cout << "(" << res[i] << " " << res[i+1] << " " << res[i+2] << ") ";
  }
  std::cout << std::endl;

  std::cout << "TestCase 2: (approach #2): Triplets found with target sum: ";
  res = FindTripletsWithTargetSum_v2(nums2, targetSum2);
  for (int i = 0; i < res.size(); i+=3) {
    std::cout << "(" << res[i] << " " << res[i+1] << " " << res[i+2] << ") ";
  }
  std::cout << std::endl;
}
