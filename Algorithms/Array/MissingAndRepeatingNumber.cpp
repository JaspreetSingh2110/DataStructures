/*
 * Description:
 * Program to find missing and repeating number in array of elements from range (1-n).
 * TC: O(n)
 *
 * Created on: 29/11/24
 * @author: Jaspreet Singh, mr.jaspreet2110@gmail.com.
 */

#include <iostream>
#include <vector>

//Approach 1: Using visited array.
std::vector<int> FindMissingAndRepeatingNumber_v1(std::vector<int>& nums)
{
  std::vector<int> result(2, -1);
  std::vector<int> visited(nums.size(), 0);
  int repeatingNum = 0;
  int missingNum = 0;
  int sum = 0;

  //Iterate over all the elements in array and update the visited array.
  for(int i = 0; i < nums.size(); i++) {
    if (visited[nums[i] - 1] != 0) {
      repeatingNum = nums[i];
      continue;
    }
    visited[nums[i] - 1] = 1;
    // for approach 2.
    sum += nums[i];
  }

  //To calculate the repeating number there are two ways.
  //1. Iterate over visited array and find the index for which entry is 0.
  for(int i = 0; i < visited.size(); i++) {
    if(visited[i] == 0) {
      missingNum = i + 1;
    }
  }

  //2. Use maths formula.
  int expectedSum = nums.size() * (nums.size() + 1)/2;
  int missingElement = expectedSum - sum;

  //std::cout << "Repeating element: " << repeatingNum << std::endl;
  //std::cout << "missing element: " << missingElement << " : " << missingNum << std::endl;

  result[0] = missingElement;
  result[1] = repeatingNum;
  return result;
}


//Approach 2: Using maths formula.
std::vector<int> FindMissingAndRepeatingNumber_v2(std::vector<int>& nums)
{
  std::vector<int> result(2, 0);
  int missingNum = 0;
  int repeatingNum = 0;
  int n = nums.size();

  int expSum = (n*(n+1))/2;
  int expSquareSum = (n * (n+1) * (2*n+1))/6;
  int cSum = 0;
  int cSquareSum = 0;
  for(int i = 0; i < n; i++) {
    cSum += nums[i];
    cSquareSum += nums[i] * nums[i];
  }

  missingNum = (expSum - cSum + (expSquareSum - cSquareSum)/(expSum - cSum))/2;
  repeatingNum = missingNum - expSum + cSum;

  result[0] = missingNum;
  result[1] = repeatingNum;
  return result;
}

void Test_FindMissingAndRepeatingNumber()
{
  std::cout << "\nTesting Find Missing And Repeating Number" << std::endl;
  std::vector<std::vector<int>> nums = {{4, 3, 6, 2, 1, 1}, { 7, 3, 4, 5, 5, 6, 2 }};

  //Approach 1.
  for (int i = 0; i < nums.size(); i++) {
    std::vector<int> result = FindMissingAndRepeatingNumber_v1(nums[i]);
    std::cout << "Test case " << i + 1 << ", approach 1: Missing element: " << result[0]
    << ", repeating element: " << result[1] << std::endl;
  }

  //Approach 2.
  for (int i = 0; i < nums.size(); i++) {
    std::vector<int> result = FindMissingAndRepeatingNumber_v2(nums[i]);
    std::cout << "Test case " << i + 1 << ", approach 2: Missing element: " << result[0]
    << ", repeating element: " << result[1] << std::endl;
  }
}
