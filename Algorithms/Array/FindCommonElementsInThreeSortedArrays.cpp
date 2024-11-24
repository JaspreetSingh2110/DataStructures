/*
 * Description:
 * Program to find common elements in three sorted array.
 *
 * Created on: 24/11/24
 * @author: Jaspreet Singh, mr.jaspreet2110@gmail.com.
 */

#include <iostream>
#include <vector>

//Approach 1: three pointers.
//TC: O(n)
std::vector<int> FindCommonelementsInSortedArray_v1(std::vector<int>& nums1, std::vector<int>& nums2, std::vector<int>& nums3)
{
  std::vector<int> results;
  int ptr1 = 0;
  int ptr2 = 0;
  int ptr3 = 0;

  while (ptr1 < nums1.size() && ptr2 < nums2.size() && ptr3 < nums3.size()) {
    if (nums1[ptr1] == nums2[ptr2] && nums1[ptr1] == nums3[ptr3]) {
      results.push_back(nums1[ptr1]);
      ptr1++;
      ptr2++;
      ptr3++;

      //If array contains duplicate elements. Add logic to skip duplicate elements.
      while (ptr1 < nums1.size() && nums1[ptr1] == nums1[ptr1-1]) {
        ptr1++;
      }
      while (ptr2 < nums2.size() && nums2[ptr2] == nums2[ptr2-1]) {
        ptr2++;
      }
      while (ptr3 < nums3.size() && nums3[ptr3] == nums3[ptr3-1]) {
        ptr3++;
      }
    }
    else {
      if ((nums1[ptr1] < nums2[ptr2]) || (nums1[ptr1] < nums3[ptr3])) {
        ptr1++;
      }
      if ((nums2[ptr2] < nums1[ptr1]) || (nums2[ptr2] < nums3[ptr3])) {
        ptr2++;
      }
      if ((nums3[ptr3] < nums1[ptr1]) || (nums3[ptr3] < nums2[ptr2])) {
        ptr3++;
      }
    }
  }

  return results;
}


void Test_FindCommonElementsInSortedArray()
{
  std::vector<int> nums1 = {1, 5, 10, 20, 30};
  std::vector<int> nums2 = {5, 13, 15, 20};
  std::vector<int> nums3 = {5, 20};

  std::cout << "\nTest common elements in three sorted arrays\n";
  /*********** Test approach 1 ***********************************************/
  std::cout << "TestCase 1: (approach #1): Common elements: ";
  std::vector<int> res = FindCommonelementsInSortedArray_v1(nums1, nums2, nums3);

  //Print result.
  for (int i = 0; i < res.size(); i++) {
    std::cout << res[i] << " ";
  }
  std::cout << std::endl;
}
