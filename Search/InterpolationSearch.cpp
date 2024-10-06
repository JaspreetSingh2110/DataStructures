//
// Created by Jaspreet Singh on 10/7/2024.
//
/*
 * Description for formula used in this algorithm. (Linear interpolation).
 *
 * Let's assume that the elements of the array are linearly distributed.
 * General equation of line : y = m*x + c.
 * y is the value in the array and x is its index.
 *
 * Now putting value of lo,hi and x in the equation
 * arr[hi] = m*hi+c ----(1)
 * arr[lo] = m*lo+c ----(2)
 * arr[pos] or x = m*pos + c     ----(3)
 *
 * Subtract equation (2) from (1).
 * m = (arr[hi] - arr[lo] )/ (hi - lo) ----(4)
 *
 * Subtracting equation (2) from (3).
 * x - arr[lo] = m * (pos - lo)
 * pos = lo + (x - arr[lo])/m
 *
 * Using (4) in (5):
 * pos = lo + (x - arr[lo]) *(hi - lo)/(arr[hi] - arr[lo])
 */

#include <iostream>

int InterpolationSearch(int arr[], int size, int value)
{
  int low = 0;
  int high = size - 1;

  while ((low <= high) &&
    (value >= arr[low]) && (value <= arr[high])) {

    //Check description above to know about formula derivation.
    int pos = low + (value - arr[low]) *(high - low)/(arr[high] - arr[low]);

    if (arr[pos] == value) {
      return pos;
    }

    // Update high and low based upon value.
    if (arr[pos] < value) {
      low = pos + 1;
    } else {
      high = pos - 1;
    }
  }
  return -1;
}


void TestInterpolationSearch() {
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  int searchElems[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 10, 12, 9, 30};
  //Search each element in array and print the result.
  for (int searchElem : searchElems) {
    int index = InterpolationSearch(arr, 10, searchElem);
    if (index == -1) {
      std::cout << "Element " << searchElem << " not found!!!" << std::endl;
    }
    else {
      std::cout << "Element " << searchElem << " found at index " << index << std::endl;
    }
  }
}