//
// Created by Jaspreet Singh on 10/7/2024.
//

#include <iostream>
#include "Search.h"

int LinearSearch(int arr[], int size, int value) {
  //Search for element in array.
  for (int i = 0; i < size; i++) {
    if (arr[i] == value) {
      return i;
    }
  }
  return -1;
}


void TestLinearSearch() {
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  int searchElems[] = {4, 10, 12, 9, 30};
  //Search each element in array and print the result.
  for (int searchElem : searchElems) {
    int index = LinearSearch(arr, 10, searchElem);
    if (index == -1) {
      std::cout << "Element " << searchElem << " not found!!!" << std::endl;
    }
    else {
      std::cout << "Element " << searchElem << " found at index " << index << std::endl;
    }
  }
}