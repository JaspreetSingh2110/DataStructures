/*
 * Description:
 * Program for intersection of sorted arrays.
 *
 * Created on: 30/11/24
 * @author: Jaspreet Singh, mr.jaspreet2110@gmail.com.
 */

#include <iostream>
#include <vector>

std::vector<int> IntersectionWithDuplicates(std::vector<int>& nums1, std::vector<int>& nums2)
{
  int n1 = nums1.size();
  int n2 = nums2.size();
  std::vector<int> result;

  int i = 0;
  int j = 0;

  //Iterate over both arrays.
  while ((i < n1) && (j < n2)) {
    if (nums1[i] < nums2[j]) {
      i++;
    }
    else if (nums2[j] < nums1[i]) {
      j++;
    }
    else {
      if (result.empty() || (!result.empty() && result.back() != nums1[i])) {
        result.push_back(nums1[i]);
      }
      i++;
      j++;
    }
  }

  return result;
}

std::vector<int> IntersectionWithDistinct(std::vector<int>& nums1, std::vector<int>& nums2)
{
  int n1 = nums1.size();
  int n2 = nums2.size();
  std::vector<int> result;

  int i = 0;
  int j = 0;

  ///Iterate over both arrays.
  while ((i < n1) && (j < n2)) {
    if (nums1[i] < nums2[j]) {
      i++;
    }
    else if (nums2[j] < nums1[i]) {
      j++;
    }
    else {
      result.push_back(nums1[i]);
      i++;
      j++;
    }
  }

  return result;
}

void Test_IntersectionSortedArrays()
{
  std::cout << "\nTest intersection of two sorted arrays\n";
  std::vector<int> nums1 = { 1, 1, 2, 2, 2, 4};
  std::vector<int> nums2 = { 2, 2, 4, 4};
  std::vector<int> nums3 = { 1, 2, 4, 5, 6 };
  std::vector<int> nums4 = { 2, 4, 7, 9 };

  //Test intersection with duplicates.
  /*********************************************************************/
  std::cout << "Testing intersection with duplicates\n";
  std::cout << "Testcase 1: ";
  std::vector<int> result = IntersectionWithDuplicates(nums1, nums2);
  //Print result.
  for (int i = 0; i < result.size(); i++) {
    std::cout << result[i] << " ";
  }
  std::cout << std::endl;
  /*********************************************************************/

  //Test intersection with distinct.
  /*********************************************************************/
  std::cout << "Testing intersection with distincts\n";
  std::cout << "Testcase 1: ";
  result = IntersectionWithDistinct(nums3, nums4);
  //Print result.
  for (int i = 0; i < result.size(); i++) {
    std::cout << result[i] << " ";
  }
  std::cout << std::endl;
  /*********************************************************************/
}