//
// Created by Jaspreet Singh on 11/08/24.
//

#include <iostream>
#include <vector>

//Move the largest element to end.
void BubbleSort(std::vector<int> &nums)
{
  //Check each element.
  for (int i=0; i < nums.size(); i++)
  {
    bool swapped = false;
    //Process remaining elements.
    for (int j=0; j < nums.size() - i - 1; j++) {
      if (nums[j] > nums[j + 1]) {
        int temp = nums[j];
        nums[j] = nums[j+1];
        nums[j+1] = temp;

        swapped = true;
      }
    }
    //If no more swapping required, break early.
    if (!swapped) {
      break;
    }
  }
}