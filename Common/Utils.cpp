//
// Created by Jaspreet Singh on 11/08/24.
//

#include "Utils.h"

void PrintVector(std::vector<int> nums)
{
  for (int &num:nums) {
    std::cout << num << "\t";
  }
  std::cout << std::endl;
}
