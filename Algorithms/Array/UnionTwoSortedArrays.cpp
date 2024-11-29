/*
 * Description:
 * Program for union of sorted arrays.
 *
 * Created on: 30/11/24
 * @author: Jaspreet Singh, mr.jaspreet2110@gmail.com.
 */

#include <iostream>
#include <vector>

std::vector<int> UnionWithDuplicates(std::vector<int>& nums1, std::vector<int>& nums2)
{
  int n1 = nums1.size();
  int n2 = nums2.size();
  std::vector<int> result(n1+n2, 0);

  int i = 0;
  int j = 0;
  int k = 0;

  //Iterate over both arrays.
  while ((i < n1) && (j < n2)) {
    if (nums1[i] < nums2[j]) {
      result[k++] = nums1[i++];
    }
    else {
      result[k++] = nums2[j++];
    }
  }

  //Append pending elements.
  while (i < n1) {
    result[k++] = nums1[i++];
  }
  while (j < n2) {
    result[k++] = nums2[j++];
  }

  return result;
}

std::vector<int> UnionWithDistinct(std::vector<int>& nums1, std::vector<int>& nums2)
{
  int n1 = nums1.size();
  int n2 = nums2.size();
  std::vector<int> result;

  int i = 0;
  int j = 0;

  //Iterate over both arrays.
  while ((i < n1) && (j < n2)) {
    if (nums1[i] < nums2[j]) {
      result.push_back(nums1[i++]);
    }
    else if (nums1[i] > nums2[j]) {
      result.push_back(nums2[j++]);
    } else {
      result.push_back(nums1[i]);
      i++;
      j++;
    }
  }

  //Append pending elements.
  while (i < n1) {
    result.push_back(nums1[i++]);
  }
  while (j < n2) {
    result.push_back(nums2[j++]);
  }

  return result;
}

void Test_UnionSortedArrays()
{
  std::cout << "\nTest union of two sorted arrays\n";
  std::vector<int> nums1 = {3, 5, 10, 10, 10, 15, 15, 20};
  std::vector<int> nums2 = {5, 10, 10, 15, 30};
  std::vector<int> nums3 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::vector<int> nums4 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  //Test union with duplicates.
  /*********************************************************************/
  std::cout << "Testing union with duplicates\n";
  std::cout << "Testcase 1: ";
  std::vector<int> result = UnionWithDuplicates(nums1, nums2);
  //Print result.
  for (int i = 0; i < result.size(); i++) {
    std::cout << result[i] << " ";
  }
  std::cout << std::endl;

  std::cout << "Testcase 2: ";
  result = UnionWithDuplicates(nums3, nums4);
  //Print result.
  for (int i = 0; i < result.size(); i++) {
    std::cout << result[i] << " ";
  }
  std::cout << std::endl;
  /*********************************************************************/

  //Test union with distinct.
  /*********************************************************************/
  std::cout << "Testing union with distincts\n";
  std::cout << "Testcase 1: ";
  result = UnionWithDistinct(nums3, nums4);
  //Print result.
  for (int i = 0; i < result.size(); i++) {
    std::cout << result[i] << " ";
  }
  std::cout << std::endl;
  /*********************************************************************/
}