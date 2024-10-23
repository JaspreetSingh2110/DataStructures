/*
 * Description:
 * Kadane's algorithm for maximum sub array sum.
 * Time complexity: O(n)
 *
 * Created on: 23/10/24
 * @author: Jaspreet Singh, mr.jaspreet2110@gmail.com.
 */

#include <iostream>
#include <vector>

int MaxSubArraySum_KadaneAlgo(std::vector<int>& arr)
{
  int maxSum = arr[0];
  int currentMaxSum = arr[0];

  //Iterate from 1st element till end of array.
  for(int i = 1; i < arr.size(); i++) {
    //Current max sum at index i is either arr[i] or (arr[i] + currentMaxSum).
    currentMaxSum = std::max(arr[i], currentMaxSum + arr[i]);

    //Update the max sum.
    maxSum = std::max(currentMaxSum, maxSum);
  }

  return maxSum;
}

void Test_MaxArraySum_KadaneAlgo()
{
  std::cout << "\nTest maximum sub array sum: KADANE's algorithm!!!\n";
  std::vector<int> arr = {2, 3, -8, 7, -1, 2, 3};
  int res = MaxSubArraySum_KadaneAlgo(arr);
  std::cout << "Maximum sub array sum is: " << res << std::endl;
}