/*
 * Description:
 * Implementation of min heap.
 *
 * Created on: 21/10/24
 * @author: Jaspreet Singh, mr.jaspreet2110@gmail.com.
 */

#include <iostream>

class MinHeap {
  public:
  int *arr = nullptr;
  int size = 0;
  int maxSize = 0;

  explicit MinHeap(int maxSize)
  {
    arr = new int[maxSize];
    size = 0;
    this->maxSize = maxSize;
  }

  ~MinHeap()
  {
    delete[] arr;
  }

  int Parent(int index)
  {
    return (index - 1) / 2;
  }

  int LeftChild(int pIndex)
  {
    return pIndex * 2 + 1;
  }

  int RightChild(int pIndex)
  {
    return pIndex * 2 + 2;
  }

  int GetMinElement()
  {
    if (size == 0) {
      return INT_MIN;
    }
    return arr[0];
  }

  void Insert(int key)
  {
    if (size == maxSize) {
      std::cout << "Heap is full!!!\n";
    }

    //Insert new key at end. Then move it up the indexes.
    int index = size;
    arr[size] = key;
    size++;

    int pIndex = Parent(index);
    while ((pIndex >= 0) && (arr[index] < arr[pIndex])) {
      std::swap(arr[index], arr[pIndex]);
      index = pIndex;
      pIndex = Parent(index);
    }
  }

  int DeleteMin()
  {
    if (size == 0) {
      std::cout << "Heap is empty!!!\n";
      return INT_MIN;
    }

    if (size == 1) {
      int elem = arr[0];
      size = 0;
      return elem;
    }

    //Swap with last element in heap. Then call heapify to restore the heap.
    int min = arr[0];
    arr[0] = arr[size - 1];
    size--;
    MinHeapify(0);

    return min;
  }

  void MinHeapify(int index)
  {
    int lChild = LeftChild(index);
    int rChild = RightChild(index);
    int minIndex = index;

    if ((lChild < size) && (arr[lChild] < arr[minIndex])) {
      minIndex = lChild;
    }
    if ((rChild < size) && (arr[rChild] < arr[minIndex])) {
      minIndex = rChild;
    }
    if (minIndex != index) {
      std::swap(arr[index], arr[minIndex]);
      MinHeapify(minIndex);
    }
  }

  void Print()
  {
    for (int i = 0; i < size; i++) {
      std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
  }

  bool IsEmpty()
  {
    return (size == 0);
  }

  int Size()
  {
    return size;
  }
};


void Test_MinHeap()
{
  MinHeap minHeap(25);

  minHeap.Insert(100);
  minHeap.Insert(90);
  minHeap.Insert(80);
  minHeap.Insert(70);
  minHeap.Insert(60);
  minHeap.Insert(50);
  minHeap.Insert(40);
  minHeap.Insert(30);
  minHeap.Insert(20);
  minHeap.Insert(10);

  minHeap.Print();

  //Make heap empty to test delete function.
  while(minHeap.IsEmpty() == false) {
    int maxElem = minHeap.DeleteMin();
    std::cout << "\nDeleted element: " << maxElem << " from the heap!!!";
  }
}