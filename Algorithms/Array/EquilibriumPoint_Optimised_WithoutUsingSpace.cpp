/*
* Description:
 * Program to find the equilibrium point in array. (Optimised without using extra space)
 * Time complexity: O(n)
 * Space complexity: O(1).
 * Equilibrium point is basically the index for which left sub array sum is equal to right sub array sum.
 * This approach first calculates left and right sum at each index in extra space.
 * Then uses it later to perform the calculations.
 *
 * Created on: 24/10/24
 * @author: Jaspreet Singh, mr.jaspreet2110@gmail.com.
 */

#include <iostream>
#include <vector>

int FindEquilibriumPoint_Optimised_WithoutUsingSpace(std::vector<int> &arr)
{
  int pivot = 0;
  int leftSum = 0;
  int rightSum = 0;

  //Calculate right sum from index 1->n-1.
  for (int i = 1; i < arr.size(); i++) {
    rightSum += arr[i];
  }

  while (pivot < (arr.size() -1)) {
    pivot++;
    leftSum += arr[pivot - 1]; //Add previous pivot element to left sum.
    rightSum -= arr[pivot];  //Remove current pivot element from right sum.

    if (leftSum == rightSum) {
      return pivot;
    }
  }
  return -1;
}


void Test_EquilibriumPoint_Optimised_WithoutUsingSpace()
{
  std::cout << "\nTest Find equilibrium point (optimised using extra space)\n";
  std::vector<int> arr = { -7, 1, 5, 2, -4, 3, 0 };
  int res = FindEquilibriumPoint_Optimised_WithoutUsingSpace(arr);
  if (res == -1) {
    std::cout << "TEST #1: Equilibrium point in given array does not exists!!!\n";
  } else {
    std::cout << "\nTEST #1: Equilibrium point is at index: " << res << std::endl;
  }

  arr = { 1,2,3};
  res = FindEquilibriumPoint_Optimised_WithoutUsingSpace(arr);
  if (res == -1) {
    std::cout << "\nTEST #2: Equilibrium point in given array does not exists!!!\n";
  } else {
    std::cout << "\nTEST #2: Equilibrium point is at index: " << res << std::endl;
  }

  arr = { 1, 7, 3, 6, 5, 6 };
  res = FindEquilibriumPoint_Optimised_WithoutUsingSpace(arr);
  if (res == -1) {
    std::cout << "\nTEST #3: Equilibrium point in given array does not exists!!!\n";
  } else {
    std::cout << "\nTEST #3: Equilibrium point is at index: " << res << std::endl;
  }
}
