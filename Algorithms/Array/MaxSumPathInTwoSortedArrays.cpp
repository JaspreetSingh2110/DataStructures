/*
 * Description:
 *
 * Created on: 29/11/24
 * @author: Jaspreet Singh, mr.jaspreet2110@gmail.com.
 */

#include <iostream>
#include <vector>

int FindMaxSumPathInTwoSortedArrays(std::vector<int> arr1, std::vector<int> arr2)
{
  int n1 = arr1.size();
  int n2 = arr2.size();
  int maxSum = 0;
  int sum1 = 0;
  int sum2 = 0;
  int i = 0;
  int j = 0;

  //Iterate over all elements of array.
  while ((i < n1) && (j < n2)) {
    if (arr1[i] < arr2[j]) {
      sum1 += arr1[i++];
    }
    else if (arr2[j] < arr1[i]) {
      sum2 += arr2[j++];
    }
    else {
      maxSum += std::max(sum1, sum2) + arr1[i];
      sum1 = sum2 = 0;
      i++;
      j++;
    }
  }

  //Add remaining elements if any of array gets traversed early.
  while (i < n1) {
    sum1 += arr1[i++];
  }
  while (j < n2) {
    sum2 += arr2[j++];
  }

  maxSum += std::max(sum1, sum2);
  return maxSum;
}


void Test_FindMaxSumPathInTwoSortedArrays()
{
  std::cout << "\nTesting find max sum path in two sorted arrays." << std::endl;
  std::vector<int> arr1 = {2, 3, 7, 10, 12, 15, 30, 34};
  std::vector<int> arr2 = {1, 5, 7, 8, 10, 15, 16, 19};

  std::cout << "Test case 1: Max sum is: " << FindMaxSumPathInTwoSortedArrays(arr1, arr2) << std::endl;
}