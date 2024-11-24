/*
* Description:
 * Program to find the longest sub array with equal 0s and 1s.
 *
 * Created on: 24/11/24
 * @author: Jaspreet Singh, mr.jaspreet2110@gmail.com.
 */

#include <iostream>
#include <vector>
#include <unordered_map>

//Approach : Using hashing with prefix sum. (Can handle negative values)
//TC: O(n)
std::vector<int> FindLongestSubArrayWithEqual0and1(std::vector<int> arr)
{
  int sum = 0;
  int maxLength = 0;
  std::vector<int> result;
  std::unordered_map<int, int> hashMap;

  //Create prefix array.
  for (int i = 0; i < arr.size(); i++) {
    //Treat 0 as -1 and create prefix array.
    if (arr[i] == 0) {
      sum += -1;
    }
    else {
      sum += 1;
    }

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


void Test_FindLongestSubArrayWithEqual0and1()
{
  std::cout << "\nTest find longest sub array with equal 0s and 1s\n";
  std::vector<int> nums1 = {1, 0, 1, 1, 1, 0, 0};

  std::cout << "TestCase 1: (approach #1): ";
  std::vector<int> result = FindLongestSubArrayWithEqual0and1(nums1);
  if (result.empty()) {
    std::cout << "No sub array found!!!\n";
  }
  else {
    std::cout << "Sub array found with equal 0s and 1s is from index: " << result[0] << " -> " << result[1] << std::endl;
  }
}
