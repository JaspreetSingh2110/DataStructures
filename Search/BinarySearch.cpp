//
// Created by Jaspreet Singh on 10/7/2024.
//

#include <iostream>


int BinarySearch(int arr[], int size, int value) {
  int low = 0;
  int high = size - 1;

  while (low <= high) {
    /* To avoid overflow if array is large enough.
     * In that case, high + low can cross the uint32_t max value.
     */
    int mid = low + (high - low) / 2;

    /*
     * Alternate formula (works for smaller size arrays.):
     * int mid = (low + high) / 2;
     */
    if (arr[mid] == value) {
      return mid;
    }

    //If value is lesser than midValue, search left half.
    if (arr[mid] > value) {
      high = mid - 1;
    }
    else
    {
      //If value is greater than midValue, search right half.
      low = mid + 1;
    }
  }
  return -1;
}

void TestBinarySearch() {
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  int searchElems[] = {0, 1, 4, 10, 12, 9, 30};
  //Search each element in array and print the result.
  for (int searchElem : searchElems) {
    int index = BinarySearch(arr, 10, searchElem);
    if (index == -1) {
      std::cout << "Element " << searchElem << " not found!!!" << std::endl;
    }
    else {
      std::cout << "Element " << searchElem << " found at index " << index << std::endl;
    }
  }
}