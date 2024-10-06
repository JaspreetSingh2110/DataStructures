//
// Created by Jaspreet Singh on 10/7/2024.
//

#include <iostream>

int TernarySearch(int arr[], int size, int value) {
  int low = 0;
  int high = size - 1;

  while (low <= high) {
    int mid1 = low + (high - low) / 3;
    int mid2 = mid1 + (high - low) / 3;
    // int mid2 = high - (high - low) / 3;

    //Check value at mid indexes
    if (arr[mid1] == value) {
      return mid1;
    } else if (arr[mid2] == value) {
      return mid2;
    }

    if (value < arr[mid1]) {
      high = mid1 - 1;
    }
    else if (value > arr[mid2]) {
      low = mid2 + 1;
    }
    else {
      low = mid1 + 1;
      high = mid2 - 1;
    }
  }
  return -1;
}

void TestTernarySearch() {
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  int searchElems[] = {0, 1, 4, 10, 12, 9, 30};
  //Search each element in array and print the result.
  for (int searchElem : searchElems) {
    int index = TernarySearch(arr, 10, searchElem);
    if (index == -1) {
      std::cout << "Element " << searchElem << " not found!!!" << std::endl;
    }
    else {
      std::cout << "Element " << searchElem << " found at index " << index << std::endl;
    }
  }
}
