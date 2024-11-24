/*
* Description:
 * Program to find the count of sub arrays with equal 0s and 1s.
 *
 * Created on: 24/11/24
 * @author: Jaspreet Singh, mr.jaspreet2110@gmail.com.
 */

#include <iostream>
#include <vector>
#include <unordered_map>

//Approach : Using hashing with prefix sum. (Can handle negative values)
//TC: O(n)
int CountSubArraysWithEqual0and1(std::vector<int> arr)
{
  int sum = 0;
  int count = 0;
  std::vector<int> result;
  std::unordered_map<int, int> hashMap;

  //Initialise hashMap with key 0 as 1.
  //This is because whenever we received 1st sum as 0 (there was 1 already processed.)
  hashMap[0] = 1;

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
      count += hashMap[sum];
      hashMap[sum]++;
    } else {
      hashMap[sum] = 1;
    }
  }

  return count;
}


void Test_CountSubArraysWithEqual0and1()
{
  std::cout << "\nTest find count of sub arrays with equal 0s and 1s\n";
  std::vector<std::vector<int>> nums = {{1, 0, 0, 1, 0, 1, 1}, { 1, 0, 0, 1, 1, 0, 0, 1}};

  for (int i = 0; i < nums.size(); i++) {
    std::cout << "TestCase " << i + 1 << ": Count of Sub arrays with equal 0s and 1s are: " << CountSubArraysWithEqual0and1(nums[i]) << std::endl;
  }
}
