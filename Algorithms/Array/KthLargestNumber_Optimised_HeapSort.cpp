/*
* Description:
 * Find Kth largest number in array.
 * Optimised approach: using max Heap sort.
 *
 * Time complexity: O(nlog(k)) Space complexity: O(k)
 *
 * Created on: 25/10/24
 * @author: Jaspreet Singh, mr.jaspreet2110@gmail.com.
 */

#include <iostream>
#include <vector>

void Heapify(std::vector<int> &nums, int size, int index)
{
  //While heapify the parent node, get its child nodes.
  int lChild =  index * 2 + 1;
  int rChild =  index * 2 + 2;
  int largest = index;

  if ((lChild < size) && (nums[lChild] > nums[largest])) {
    largest = lChild;
  }
  if ((rChild < size) && (nums[rChild] > nums[largest])) {
    largest = rChild;
  }

  if (largest != index) {
    std::swap(nums[index], nums[largest]);
    Heapify(nums, size, largest);
  }
}

void MaxHeapSort(std::vector<int>& nums)
{
  //1st valid parent is at index (nums.size()/2 -1)
  for (int i = (nums.size()/2) - 1; i >= 0; i--) {
    Heapify(nums, nums.size(), i);
  }

  for (int i = nums.size() - 1; i >= 0; i--) {
    std::swap(nums[0], nums[i]);
    Heapify(nums, i, 0);
  }
}

int KthLargestNumber_Optimised_HeapSort(std::vector<int>& nums, int k)
{
  //Check if finding Kth largest element is possible.
  if (k > nums.size()) {
    return -1;
  }

  //Perform max heap sort on array. // It will sort the array into ASCENDING ORDER.
  MaxHeapSort(nums);

  //Array after sorting
  std::cout << "\nSorted array: ";
  for (int &num : nums) {
    std::cout << num << " ";
  }
  std::cout << std::endl;

  return nums[nums.size() - k];
}


void Test_KthLargestNumber_Optimised_HeapSort()
{
  std::cout << "\nTest find Kth largest element in array (optimised using max heap sort)\n";
  std::vector<int> nums = {14, 12, 35, 56, 18, 435, 45, 456, 67, 67, 55, 789, 567, 98, 98, 654, 63, 52, 6, 3};
  int k = 3;

  std::cout << "\nOriginal array: ";
  for (int i = 0; i < nums.size(); ++i) {
    std::cout << nums[i] << " ";
  }
  std::cout << "\n3rd largest number in array is: " << KthLargestNumber_Optimised_HeapSort(nums, k) << std::endl;
}