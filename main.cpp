#include <iostream>
#include <vector>

#include "Common/Utils.h"
#include "SortingTechniques/SortingTechniques.h"
#include "LinearDS/Stack.h"
#include "LinearDS/Queue.h"
#include "LinearDS/SingleLinkedLists.h"


void TestLinearDS() {
  std::cout << "Testing data structures implementation!" << std::endl;

  std::cout << "Testing 'Stack' implementation!" << std::endl;
  TestStack();

  std::cout << "Testing 'Queue' implementation!" << std::endl;
  TestQueue();

  std::cout << "Testing 'Single LinkedLists' implementation!" << std::endl;
  TestSingleLinkedLists();

  std::cout << "Testing DONE!" << std::endl;
}


void TestSortingTechniques()
{
  std::vector<int> nums1 = {5, 4, 3, 2, 1};
  std::vector<int> nums2 = {2, 4, 3, 5, 1};
  std::vector<int> nums3 = {3, 4, 2, 5, 1};
  std::vector<int> nums4 = {3, 4, 2, 5, 1, 3, 2};
  std::vector<std::vector<int>> testVectors = {nums1, nums2, nums3, nums4};

  for (auto testVector : testVectors) {
    std::cout << "Test array: " << std::endl;
    PrintVector(testVector);

    //std::cout << "Testing Bubble Sort\n";
    //BubbleSort(testVector);
    //PrintVector(testVector);

    //std::cout << "Testing Selection Sort\n";
    //SelectionSort(testVector);
    //PrintVector(testVector);

    //std::cout << "Testing Insertion Sort\n";
    //InsertionSort(testVector);
    //PrintVector(testVector);

    //std::cout << "Testing Counting Sort\n";
    //CountingSort(testVector);
    //PrintVector(testVector);

    //std::cout << "Testing Merge Sort\n";
    //MergeSort(testVector, 0, testVector.size() -1);
    //PrintVector(testVector);

    //std::cout << "Testing Shell Sort\n";
    //ShellSort(testVector);
    //PrintVector(testVector);

    //std::cout << "Testing Quick Sort\n";
    QuickSort(testVector, 0, testVector.size() -1);
    PrintVector(testVector);
  }
}


int main()
{
  TestSortingTechniques();
  TestLinearDS();
  return 0;
}


