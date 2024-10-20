/*
 * Description:
 * Implementation of Heap sort.
 *
 * Created on: 20/10/24
 * @author: Jaspreet Singh, mr.jaspreet2110@gmail.com.
 */

#include <iostream>

enum SortType {
  SORT_ASCENDING,
  SORT_DESCENDING,
  MAX
};

class HeapSort {
  public:
  void MaxHeapify(int *arr, int size, int index)
  {
    int largest = index;
    int lChild = 2 * index + 1;
    int rChild = 2 * index + 2;

    if ((lChild < size) && (arr[lChild] > arr[largest])) {
      largest = lChild;
    }
    if ((rChild < size) && (arr[rChild] > arr[largest])) {
      largest = rChild;
    }
    if (largest != index) {
      std::swap(arr[index], arr[largest]);
      MaxHeapify(arr, size, largest);
    }
  }

  void MinHeapify(int *arr, int size, int index)
  {
    int smallest = index;
    int lChild = 2 * index + 1;
    int rChild = 2 * index + 2;

    if ((lChild < size) && (arr[lChild] < arr[smallest])) {
      smallest = lChild;
    }
    if ((rChild < size) && (arr[rChild] < arr[smallest])) {
      smallest = rChild;
    }
    if (smallest != index) {
      std::swap(arr[index], arr[smallest]);
      MinHeapify(arr, size, smallest);
    }
  }

  void SortAscending(int *arr, int size)
  {
    //First heapify the given array.
    for (int i = (size/2) - 1; i >= 0; i--) {
      MaxHeapify(arr, size, i);
    }

    //Move max element to size -1 index.
    //This will create ascending sorted array by keeping max elements at end of array.
    for (int i = size-1; i >= 0; i--) {
      std::swap(arr[0], arr[i]);
      MaxHeapify(arr, i, 0);
    }
  }

  void SortDescending(int *arr, int size)
  {
    //Min Heapify all nodes with no childrens.
    //NOTE: The first bottom node with child starts at index (size/2 - 1)
    for (int i = (size/2) -1; i >=0; i--) {
      MinHeapify(arr, size, i);
    }

    for (int i = size-1; i >= 0; i--) {
      std::swap(arr[0], arr[i]);
      MinHeapify(arr, i, 0);
    }
  }

  void Sort(int *arr, int size, SortType type)
  {
    switch (type) {
      case SORT_ASCENDING:
        SortAscending(arr, size);
      break;
      case SORT_DESCENDING:
        SortDescending(arr, size);
      break;
      default:
        std::cout << "Unkown SortType!" << std::endl;
    }
  }
};


void Test_HeapSort()
{
  HeapSort heapSort;

  int arr[20] = {14, 12, 35, 56, 18, 435, 45, 456, 67, 67, 55, 789, 567, 98, 98, 654, 63, 52, 6, 3};

  //Test ascending order sort.
  heapSort.SortAscending(arr, 20);
  //Print sorted array.
  std::cout << "Array after sorting in ascending order are:->\t";
  for (int i = 0; i < 20; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;

  //TEst descending order sort.
  heapSort.SortDescending(arr, 20);
  //Print sorted array.
  std::cout << "Array after sorting in descending order are:->\t";
  for (int i = 0; i < 20; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}