/*
 * Description:
 * Program to find sub array with given target sum.
 *
 * Approach 1: Using Nested loops (not implemented.)
 *
 * Created on: 24/11/24
 * @author: Jaspreet Singh, mr.jaspreet2110@gmail.com.
 */

#include <iostream>
#include <vector>
#include <unordered_map>

//Approach 2: Using sliding window.
//TC: O(n)
std::vector<int> FindSubArrayWithTargetSum_v1(std::vector<int> arr, int targetSum)
{
  std::vector<int> result;
  int sum = 0;
  int startIndex = 0;

  //Slide the window to get the target sum.
  for(int i = 0; i < arr.size(); i++) {
    sum += arr[i];

    //If current sum is greater than target sum, start removing elements from left side.
    if (sum >= targetSum) {
      while ((startIndex < i) && (sum > targetSum)) {
        sum -= arr[startIndex];
        startIndex++;
      }

      //If sum becomes same as target sum, store the indexes.
      if (sum == targetSum) {
        result.push_back(startIndex);
        result.push_back(i);
      }
    }
  }

  return result;
}


//Approach 2: Using hashing with prefix sum. (Can handle negative values)
//TC: O(n)
std::vector<int> FindSubArrayWithTargetSum_v2(std::vector<int> arr, int targetSum)
{
  int sum = 0;
  std::vector<int> result;
  std::unordered_map<int, int> hashMap;

  //Iterate over all elements of array and calculate prefix sum.
  for (int i = 0; i < arr.size(); i++) {
    sum += arr[i];

    //If 0->ith index elements adds up to target sum.
    if (sum == targetSum) {
      result.push_back(0);
      result.push_back(i);
    }

    //Find the remaining value in map.
    int remainingValue = sum - targetSum;

    //If map contains remaining value, use next index to that element.
    if (hashMap.find(remainingValue) != hashMap.end()) {
      result.push_back(hashMap[remainingValue] + 1);
      result.push_back(i);
    }

    hashMap.insert({sum, i});
  }

  return result;
}


void Test_FindSubArrayWithTargetSum()
{
  std::cout << "\nTest find sub array with target sum\n";
  std::vector<int> nums1 = {15, 2, 4, 8, 9, 5, 10, 23};
  std::vector<int> nums2 = {1, 4, 0, 0, 3, 10, 5};
  std::vector<int> nums3 = {1, 4};
  std::vector<int> nums4 = { 2, 12, -2, -20, 10 };

  int targetSum1 = 23;
  int targetSum2 = 7;
  int targetSum3 = 0;
  int targetSum4 = -10;

  /************** Approach 1 ********************************************************/
  std::cout << "TestCase 1: (approach #1): ";
  std::vector<int> result = FindSubArrayWithTargetSum_v1(nums1, targetSum1);
  if (result.empty()) {
    std::cout << "No sub array found with target sum!!!\n";
  }
  else {
    std::cout << "Sub array found with target sum: ";
    for (int i = 0; i < result.size(); i+=2) {
      std::cout << "(" << result[i] << ", " << result[i+1] << ") ";
    }
    std::cout << "\n";
  }

  std::cout << "TestCase 2: (approach #1): ";
  result = FindSubArrayWithTargetSum_v1(nums2, targetSum2);
  if (result.empty()) {
    std::cout << "No sub array found with target sum!!!\n";
  }
  else {
    std::cout << "Sub array found with target sum: ";
    for (int i = 0; i < result.size(); i+=2) {
      std::cout << "(" << result[i] << ", " << result[i+1] << ") ";
    }
    std::cout << "\n";
  }

  std::cout << "TestCase 3: (approach #1): ";
  result = FindSubArrayWithTargetSum_v1(nums3, targetSum3);
  if (result.empty()) {
    std::cout << "No sub array found with target sum!!!\n";
  }
  else {
    std::cout << "Sub array found with target sum: ";
    for (int i = 0; i < result.size(); i+=2) {
      std::cout << "(" << result[i] << ", " << result[i+1] << ") ";
    }
    std::cout << "\n";
  }

  /************** Approach 2 ********************************************************/
  std::cout << "TestCase 1: (approach #2): ";
  result = FindSubArrayWithTargetSum_v2(nums1, targetSum1);
  if (result.empty()) {
    std::cout << "No sub array found with target sum!!!\n";
  }
  else {
    std::cout << "Sub array found with target sum: ";
    for (int i = 0; i < result.size(); i+=2) {
      std::cout << "(" << result[i] << ", " << result[i+1] << ") ";
    }
    std::cout << "\n";
  }

  std::cout << "TestCase 2: (approach #2): ";
  result = FindSubArrayWithTargetSum_v2(nums2, targetSum2);
  if (result.empty()) {
    std::cout << "No sub array found with target sum!!!\n";
  }
  else {
    std::cout << "Sub array found with target sum: ";
    for (int i = 0; i < result.size(); i+=2) {
      std::cout << "(" << result[i] << ", " << result[i+1] << ") ";
    }
    std::cout << "\n";
  }

  std::cout << "TestCase 3: (approach #2): ";
  result = FindSubArrayWithTargetSum_v2(nums3, targetSum3);
  if (result.empty()) {
    std::cout << "No sub array found with target sum!!!\n";
  }
  else {
    std::cout << "Sub array found with target sum: ";
    for (int i = 0; i < result.size(); i+=2) {
      std::cout << "(" << result[i] << ", " << result[i+1] << ") ";
    }
    std::cout << "\n";
  }

  std::cout << "TestCase 4: (approach #2): ";
  result = FindSubArrayWithTargetSum_v2(nums4, targetSum4);
  if (result.empty()) {
    std::cout << "No sub array found with target sum!!!\n";
  }
  else {
    std::cout << "Sub array found with target sum: ";
    for (int i = 0; i < result.size(); i+=2) {
      std::cout << "(" << result[i] << ", " << result[i+1] << ") ";
    }
    std::cout << "\n";
  }
}
