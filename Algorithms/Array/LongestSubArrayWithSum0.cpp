/*
 * Description:
 * Program to find the longest sub array with given target sum 0.
 *
 * Created on: 24/11/24
 * @author: Jaspreet Singh, mr.jaspreet2110@gmail.com.
 */

#include <iostream>
#include <vector>
#include <unordered_map>

//Approach : Using hashing with prefix sum. (Can handle negative values)
//TC: O(n)
std::vector<int> FindLongestSubArrayWithTargetSum0(std::vector<int> arr)
{
  int sum = 0;
  int maxLength = 0;
  std::vector<int> result;
  std::unordered_map<int, int> hashMap;

  //Create prefix array.
  for (int i = 0; i < arr.size(); i++) {
    sum += arr[i];

    //Whenever we find a repeating prefix sum, it means intermediate elements sums up to 0.
    if (hashMap.find(sum) != hashMap.end()) {
      int length = i - hashMap[sum];
      if (length > maxLength) {
        maxLength = length;

        //Update new result.
        result.clear();
        result.push_back(hashMap[sum] + 1);
        result.push_back(i);
      }
    }
    else {
      hashMap[sum] = i;
    }
  }

  return result;
}


void Test_FindLongestSubArrayWithTargetSum0()
{
  std::cout << "\nTest find longest sub array with target sum 0\n";
  std::vector<int> nums1 = {15, -2, 2, -8, 1, 7, 10, 23};

  std::cout << "TestCase 1: (approach #1): ";
  std::vector<int> result = FindLongestSubArrayWithTargetSum0(nums1);
  if (result.empty()) {
    std::cout << "No sub array found with target sum!!!\n";
  }
  else {
    std::cout << "Sub array found with target sum: index: " << result[0] << " -> " << result[1] << std::endl;
  }
}
