/*
 * Description:
 * Implementation of Max heap.
 *
 * Created on: 20/10/24
 * @author: Jaspreet Singh, mr.jaspreet2110@gmail.com.
 */

#include <iostream>

class MaxHeap {
public:
  int* arr = nullptr;
  int size = 0;
  int maxSize = 0;

  explicit MaxHeap(int maxSize)
  {
    arr = new int[maxSize];
    size = 0;
    this->maxSize = maxSize;
  };

  ~MaxHeap()
  {
    delete[] arr;
  }

  int Parent(int index)
  {
    return (index - 1) / 2;
  }

  int LeftChild(int index)
  {
    return 2 * index + 1;
  }

  int RightChild(int index)
  {
    return 2 * index + 2;
  }

  void Insert(int key)
  {
    if (size == maxSize) {
      std::cout << "Max heap already full" << std::endl;
      return;
    }

    //Initially insert the new key at next to last key in heap.
    arr[size] = key;
    size++;

    //Now, do shifts to restore the heap property if violated.
    int cIdx = size - 1;
    int parent = Parent(cIdx);
    while ((parent >= 0) && (arr[parent] < arr[cIdx])) {
      //swap
      std::swap(arr[parent], arr[cIdx]);
      cIdx = parent;
      parent = Parent(cIdx);
    }
  }

  int DeleteMax()
  {
    //If no elements in heap.
    if (size == 0) {
      return INT_MIN;
    }

    //If single element in heap.
    if (size == 1) {
      size = 0;
      return arr[0];
    }

    //Copy the last element from heap to top position.
    //Then call Heapify to restore properties the heap.
    int top = arr[0];
    arr[0] = arr[size - 1];
    size--;

    //Call MaxHeapify on root element.
    MaxHeapify(0);
    return top;
  }

  void MaxHeapify(int idx)
  {
    int maxIdx = idx;
    int lChild = LeftChild(idx);
    int rChild = RightChild(idx);

    //Find which child is largest of three.
    //Check if left child is largest than root.
    if ((lChild < size) && (arr[maxIdx] < arr[lChild])) {
      maxIdx = lChild;
    }
    //Check if right child is largest of root/left child
    if ((rChild < size) && (arr[maxIdx] < arr[rChild])) {
      maxIdx = rChild;
    }

    //If any of child is greater than current element (root).
    if (idx != maxIdx) {
      std::swap(arr[idx], arr[maxIdx]);
      MaxHeapify(maxIdx);
    }
  }

  // Get max element from heap.
  int GetMax()
  {
    if (size == 0) {
      std::cout << "Max heap is empty" << std::endl;
      return -1;
    }
    return arr[0];
  }

  bool IsEmpty()
  {
    return (size == 0);
  }


  int Size()
  {
    return size;
  }

  //Prints array.
  void Print()
  {
    if (size == 0) {
      std::cout << "Max heap is empty" << std::endl;
      return;
    }
    for (int idx = 0; idx < size; idx++) {
      std::cout << arr[idx] << " ";
    }
    std::cout << std::endl;
  }
};


void Test_MaxHeap()
{
  MaxHeap maxHeap(25);

  maxHeap.Insert(10);
  maxHeap.Insert(20);
  maxHeap.Insert(30);
  maxHeap.Insert(40);
  maxHeap.Insert(50);
  maxHeap.Insert(60);
  maxHeap.Insert(70);
  maxHeap.Insert(80);
  maxHeap.Insert(90);
  maxHeap.Insert(100);

  maxHeap.Print();

  //Make heap empty to test delete function.
  while(maxHeap.IsEmpty() == false) {
    int maxElem = maxHeap.DeleteMax();
    std::cout << "\nDeleted element: " << maxElem << " from the heap!!!";
  }
}