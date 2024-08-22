//
// Created by Jaspreet Singh on 11/08/24.
//

#ifndef SORTINGTECHNIQUES_H
#define SORTINGTECHNIQUES_H

void BubbleSort(std::vector<int> &nums);
void SelectionSort(std::vector<int> &nums);
void InsertionSort(std::vector<int> &nums);
void ShellSort(std::vector<int> &nums);
void MergeSort(std::vector<int> &nums, int beg, int end);
void QuickSort(std::vector<int> &nums, int low, int high);

//Linear sorting techniques.
void CountingSort(std::vector<int> &nums);

#endif //SORTINGTECHNIQUES_H
