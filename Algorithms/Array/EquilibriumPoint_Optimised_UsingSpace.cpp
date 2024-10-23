/*
 * Description:
 * Program to find the equilibrium point in array. (Optimised using extra space)
 * Time complexity: O(n)
 * Space complexity: O(n).
 * Equilibrium point is basically the index for which left sub array sum is equal to right sub array sum.
 * This approach first calculates left and right sum at each index in extra space.
 * Then uses it later to perform the calculations.
 *
 * Created on: 24/10/24
 * @author: Jaspreet Singh, mr.jaspreet2110@gmail.com.
 */

#include <iostream>
#include <vector>

int FindEquilibriumPoint_Optimised_UsingSpace(std::vector<int> &arr)
{
  //Extra memory to store pre-calculated data.
  int size = arr.size();
  std::vector<int> leftSum(size, 0);
  std::vector<int> rightSum(size, 0);

  //Calculate left sum for each index.
  leftSum[0] = 0;
  for (int i = 1; i < size; i++) {
    leftSum[i] = leftSum[i - 1] + arr[i - 1];
  }

  //Calculate right sum for each index.
  rightSum[size - 1] = 0;
  for (int i = size - 2; i >= 0; i--) {
    rightSum[i] = rightSum[i+1] + arr[i+1];
  }

  //Now iterate over array and use leftSum and rightSum at each index to find equilibrium point.
  for (int i = 0; i < size; i++) {
    if (leftSum[i] == rightSum[i]) {
      return i;
    }
  }
  return -1;
}


void Test_EquilibriumPoint_Optimised_UsingSpace()
{
  std::cout << "\nTest Find equilibrium point (optimised using extra space)\n";
  std::vector<int> arr = { -7, 1, 5, 2, -4, 3, 0 };
  int res = FindEquilibriumPoint_Optimised_UsingSpace(arr);
  if (res == -1) {
    std::cout << "TEST #1: Equilibrium point in given array does not exists!!!\n";
  } else {
    std::cout << "\nTEST #1: Equilibrium point is at index: " << res << std::endl;
  }

  arr = { 1,2,3};
  res = FindEquilibriumPoint_Optimised_UsingSpace(arr);
  if (res == -1) {
    std::cout << "\nTEST #2: Equilibrium point in given array does not exists!!!\n";
  } else {
    std::cout << "\nTEST #2: Equilibrium point is at index: " << res << std::endl;
  }
}
