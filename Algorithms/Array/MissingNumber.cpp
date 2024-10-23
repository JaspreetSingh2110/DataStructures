/*
 * Description:
 * Algorithm to find missing number in array.
 * Given an array arr[] of size N-1 with integers in the range of [1, N],
 * the task is to find the missing number from the first N integers.
 * Note: There are no duplicates in the list.
 *
 * Created on: 23/10/24
 * @author: Jaspreet Singh, mr.jaspreet2110@gmail.com.
 */

#include <iostream>
#include <vector>

int FindMissingNumber(std::vector<int> &nums)
{
  int size = nums.size() +1;

  //As per mathematical approach, sum of n numbers is  n*(n+1)/2.
  int expectedSum = size*(size+1)/2;
  int actualSum = 0;

  //Calculate sum of numbers present in array.
  for (int i = 0; i < size; i++) {
    actualSum += nums[i];
  }

  return expectedSum - actualSum;
}


void Test_FindMissingNumber()
{
  std::cout << "\nTest find missing number algorithm!!!\n";
  //16 is missing.
  std::vector<int> arr = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,17,18,19,20,21,22,23,24,25,26,27,28,29,30};
  int res = FindMissingNumber(arr);
  std::cout << "Missing number in array is: " << res << std::endl;

  if (res != 16) {
    std::cout << "\nTest find missing number algorithm [FAILED]!!!\n";
  }
}