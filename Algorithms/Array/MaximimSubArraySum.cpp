/*
 * Description:
 * Given an array arr[], the task is to find the subarray that has the maximum sum and return its sum.
 *
 * Examples:
 *
 * Input: arr[] = {2, 3, -8, 7, -1, 2, 3}
 * Output: 11
 * Explanation: The subarray {7, -1, 2, 3} has the largest sum 11.
 *
 * Input: arr[] = {-2, -4}
 * Output: –2
 * Explanation: The subarray {-2} has the largest sum -2.
 *
 * Input: arr[] = {5, 4, 1, 7, 8}
 * Output: 25
 * Explanation: The subarray {5, 4, 1, 7, 8} has the largest sum 25.
 *
 * Created on: 23/10/24
 * @author: Jaspreet Singh, mr.jaspreet2110@gmail.com.
 */

#include <iostream>
#include <vector>

int MaxSubArraySum(std::vector<int> arr)
{
  int maxSubArraySum = INT_MIN;
  int start = -1;
  int end = -1;

  //i will serve as starting index of sub array.
  //j will serve as end index of sub array.
  for (int i = 0; i < arr.size(); i++) {
    int subArraySum = 0;
    for (int j = i; j < arr.size(); j++) {
      //Calculate sum of sub array for elements arr[i] -> arr[j].
      subArraySum += arr[j];

      //Check if sub array sum is greater than max, set max to current value.
      //Also, store the indices (i,j).
      if (subArraySum > maxSubArraySum) {
        start = i;
        end = j;
        maxSubArraySum = subArraySum;
      }
    }
  }
  if (maxSubArraySum != INT_MIN) {
    std::cout << "Sub array details:: start index: " << start << " end index: " << end << std::endl;
  }
  return maxSubArraySum;
}

void Test_MaxArraySum()
{
  std::vector<int> arr = {2, 3, -8, 7, -1, 2, 3};
  int res = MaxSubArraySum(arr);
  std::cout << "Maximum sub array sum is: " << res << std::endl;
}
