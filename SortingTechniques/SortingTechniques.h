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
void BucketSort(std::vector<int> &nums);
void RadixSort(std::vector<int> &nums);

/*
 ***********************************************************************************
____________________________________________________________________________________
Algorithm	      |             Time Complexity	                  | Space Complexity |
___________________________________________________________________________________|
                | Best	        | Average	      | Worst	        | Worst            |
___________________________________________________________________________________|
Bubble Sort	    | O(n)	        | O(n2)	        | O(n2)	        | O(1)             |
Selection Sort  | O(n2)	        | O(n2)	        | O(n2)	        | O(1)             |
Insertion Sort  | O(n)	        | O(n2)	        | O(n2)	        | O(1)             |
Shell Sort	    | O(n log(n))	  | O(n log(n))	  | O(n2)	        | O(1)             |
Merge Sort      | O(n log(n))	  | O(n log(n))	  | O(n log(n))	  | O(n)             |
Quick Sort      | O(n log(n))	  | O(n log(n))	  | O(n2)	        | O(n)             |
Count Sort      | O(n +k)	      | O(n +k)	      | O(n +k)	      | O(k)             |
Bucket Sort	    | O(n +k)	      | O(n +k)	      | O(n2)	        | O(n)             |
Radix Sort      | O(nk)	        | O(nk)	        | O(nk)	        | O(n + k)         |
Heap Sort	      | O(n log(n))	  | O(n log(n))	  | O(n log(n))	  | O(1)             |
Tim Sort        | O(n)	        | O(n log(n))	  | O(n log (n))	| O(n)             |
Tree Sort	      | O(n log(n))	  | O(n log(n))	  | O(n2)	        | O(n)             |
Cube Sort	      | O(n)	        | O(n log(n))	  | O(n log(n))	  | O(n)             |
___________________________________________________________________________________|
 ***********************************************************************************
 */

#endif //SORTINGTECHNIQUES_H
