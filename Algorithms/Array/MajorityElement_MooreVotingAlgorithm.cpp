/*
 * Description:
 * Program to find majority element using Moore's voting algorithm
 *
 * Created on: 23/11/24
 * @author: Jaspreet Singh, mr.jaspreet2110@gmail.com.
 */

#include <iostream>
#include <vector>

int FindMajorityElement(std::vector<int>& nums)
{
  int majorityElem = nums[0];
  int count = 0;

  //Iterate over array and apply algorithm.
  for(int i = 0; i < nums.size(); i++) {
    //Set the majority element.
    if (count == 0) {
      majorityElem = nums[i];
    }

    //Update counter.
    if(nums[i] == majorityElem) {
      count++;
    }
    else {
      count--;
    }
  }

  //Validate majority element.
  count = 0;
  for (int i = 0; i < nums.size(); i++) {
    if (nums[i] == majorityElem) {
      count++;
    }
  }

  if (count > nums.size() / 2) {
    return majorityElem;
  }
  return -1;
}

void Test_FindMajorityElement()
{
  std::cout << "\nTest find majority element in array\n";
  std::vector<std::vector<int>> nums = {{1, 1, 2, 1, 3, 5, 1}, {{3, 3, 4, 2, 4, 4, 2, 4}}, {5}};

  for (int i = 0; i < nums.size(); ++i) {
    std::cout << "Testcase: " << i+1 << ": Majority element is: " << FindMajorityElement(nums[i]) << '\n';
  }
}
