/*
 * Description:
 * Program to sort given array in wave form.
 * arr[0] >= arr[1] <= arr[2] >= arr[3] <= arr[4] >= ….
 *
 * Created on: 23/11/24
 * @author: Jaspreet Singh, mr.jaspreet2110@gmail.com.
 */


#include <iostream>
#include <vector>

//Approach #1: Sort the array.
//Then swap the 0->1, 2->3, 4->5 ...
//TC: O(NlogN)

//Approach 2: Make sure elements at index 0, 2, 4 (even) are greater than their adjacent elements.
//TC: O(N)
void SortArrayInWaveForm(std::vector<int>& arr)
{
  for (int i = 0; i < arr.size(); i+=2) {
    //Validate number wrt to left number.
    if ((i>0) && (arr[i] < arr[i-1])) {
      std::swap(arr[i], arr[i-1]);
    }
    //Validate number wrt to right number.
    if ((i < arr.size() -1) && (arr[i] < arr[i+1])) {
      std::swap(arr[i], arr[i+1]);
    }
  }
}


void Test_SortArrayInWaveForm()
{
  std::cout << "\nTest Sort Array In Wave Form" << std::endl;

  std::vector<std::vector <int>> nums = {{10, 5, 6, 3, 2, 20, 100, 80}, {10, 90, 49, 2, 1, 5, 23}};

  for (int i = 0; i < nums.size(); i++) {;
    SortArrayInWaveForm(nums[i]);

    std::cout << "Testcase #" << i + 1 << ": Sorted Array In Wave Form: ";
    for (int num: nums[i]) {
      std::cout << num << " ";
    }
    std::cout << std::endl;
  }
}