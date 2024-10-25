/*
 * Description:
 * Program to rotate the array right.
 *
 * Created on: 25/10/24
 * @author: Jaspreet Singh, mr.jaspreet2110@gmail.com.
 */

#include <iostream>
#include <vector>

void RightRotate(std::vector<int>& nums, int rotationCnt)
{
  int n = nums.size();
  rotationCnt = rotationCnt % n;

  //Execute the loop for |rotationCnt| times.
  for (int i = 0; i < rotationCnt; i++) {
    //Take the backup of last element in array.
    int temp = nums[n-1];

    //Shift all elements towards right 1 time.
    for (int j = n-1; j > 0; j--) {
      nums[j] = nums[j-1];
    }
    //Copy back the backup element at 0th index.
    nums[0] = temp;
  }
}

void LeftRotate(std::vector<int>& nums, int rotationCnt)
{
  int n = nums.size();
  rotationCnt = rotationCnt % n;

  for (int i = 0; i < rotationCnt; i++) {
    int temp = nums[0];

    for (int j = 0; j < n - 1; j++) {
      nums[j] = nums[j + 1];
    }
    nums[n-1] = temp;
  }
}


void Test_ArrayRotation()
{
  std::cout << "\nTesting rotation of array\n";
  std::vector<int> nums{1,2,3,4,5,6,7,8,9};

  std::cout << "\nTest right rotation: \n";
  RightRotate(nums, 4);
  for (int i = 0; i < nums.size(); i++) {
    std::cout << nums[i] << " ";
  }
  std::cout << std::endl;

  std::cout << "\nTest left rotation: \n";
  LeftRotate(nums, 4);
  for (int i = 0; i < nums.size(); i++) {
    std::cout << nums[i] << " ";
  }
  std::cout << std::endl;

  std::cout << "\nTest left rotation: \n";
  LeftRotate(nums, 3);
  for (int i = 0; i < nums.size(); i++) {
    std::cout << nums[i] << " ";
  }
  std::cout << std::endl;
}