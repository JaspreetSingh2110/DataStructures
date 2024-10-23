/*
 * Description:
 * Program to find the equilibrium point in array.
 * Time complexity: O(n^2)
 * Space complexity: O(1).
 * Equilibrium point is basically the index for which left sub array sum is equal to right sub array sum.
 *
 * Created on: 24/10/24
 * @author: Jaspreet Singh, mr.jaspreet2110@gmail.com.
 */

#include <iostream>
#include <vector>

int FindEquilibriumPoint(std::vector<int> &arr)
{
  int leftSum = 0;
  int rightSum = 0;

  //Start from index 1->n.
  //For each index get the left sum and right sum.
  //If both sum are equal, that is equilibrium point.
  for (int i = 1; i < arr.size(); i++) {
    leftSum = 0;
    rightSum = 0;
    for (int j = 0; j < i; j++) {
      leftSum += arr[j];
    }
    for (int j = i+1; j < arr.size(); j++) {
      rightSum += arr[j];
    }

    if (leftSum == rightSum) {
      return i;
    }
  }
  return -1;
}

void Test_EquilibriumPoint()
{
  std::cout << "\nTest Find equilibrium point\n";
  std::vector<int> arr = { -7, 1, 5, 2, -4, 3, 0 };
  int res = FindEquilibriumPoint(arr);
  if (res == -1) {
    std::cout << "TEST #1: Equilibrium point in given array does not exists!!!\n";
  } else {
    std::cout << "\nTEST #1: Equilibrium point is at index: " << res << std::endl;
  }

  arr = { 1,2,3};
  res = FindEquilibriumPoint(arr);
  if (res == -1) {
    std::cout << "\nTEST #2: Equilibrium point in given array does not exists!!!\n";
  } else {
    std::cout << "\nTEST #2: Equilibrium point is at index: " << res << std::endl;
  }
}
