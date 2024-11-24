/*
 * Description:
 * Program to find pairs of elements in array that sums to target sum.
 *
 * Created on: 24/11/24
 * @author: Jaspreet Singh, mr.jaspreet2110@gmail.com.
 */

#include <iostream>
#include <vector>

//Approach 1: Sort + two pointers approach (Need fix).
//TC: O(nlogn)
int FindPairsWithTargetSum_v1(std::vector<int>& nums, int target)
{
  int left = 0;
  int right = nums.size() - 1;
  int count = 0;

  //Sort the array.
  std::sort(nums.begin(), nums.end());

  //Use two pointer approach.
  while (left < right) {
    int sum = nums[left] + nums[right];

    //If sum equals target.
    if (sum == target) {
      //Now there is possibility that, further sum is possible.
      int count1 = 0;
      int count2 = 0;
      int leftElem = nums[left];
      int rightElem = nums[right];
      while (left <= right && nums[left] == leftElem) {
        left++;
        count1++;
      }

      while (left <= right && nums[right] == rightElem) {
        right--;
        count2++;
      }

      count += (count1*count2);
    }
    else if (sum < target) {
      left++;
    }
    else {
      right--;
    }
  }

  return count;
}


//Approach 2: Using hashMap.
//TC: O(n)
int FindPairsWithTargetSum_v2(std::vector<int>& nums, int target)
{
  std::unordered_map<int, int> map;
  int count = 0;

  for (int i = 0; i < nums.size(); i++) {

    if (map.find(target-nums[i]) != map.end()) {
      //Increment count by the greq of remaining value element.
      count += map[target-nums[i]];
    }

    //Increment frequency counter.
    map[nums[i]]++;
  }

  return count;
}


void Test_FindPairsWithTargetSum()
{
  std::vector<int> nums1 = {1, 5, 7, -1, 5};
  std::vector<int> nums2 = {1, 1, 1, 1};
  int targetSum1 = 6;
  int targetSum2 = 2;

  std::cout << "\nTest find pairs with given target sum\n";

  /*********** Test approach 1 ***********************************************/
  std::cout << "TestCase 1: (approach #1): Pair of elements found with target sum: "
    << FindPairsWithTargetSum_v1(nums1, targetSum1) << std::endl;
  std::cout << "TestCase 2: (approach #1): Pair of elements found with target sum: "
    << FindPairsWithTargetSum_v1(nums2, targetSum2) << std::endl;

  /*********** Test approach 2 ***********************************************/
  std::cout << "TestCase 1: (approach #2): Pair of elements found with target sum: "
    << FindPairsWithTargetSum_v2(nums1, targetSum1) << std::endl;
  std::cout << "TestCase 2: (approach #2): Pair of elements found with target sum: "
    << FindPairsWithTargetSum_v2(nums2, targetSum2) << std::endl;
}
