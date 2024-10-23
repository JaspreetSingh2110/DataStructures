/*
 * Description:
 * Algorithm to calculate sub array with maximum product. Optimised approach: O(n)
 * NOTE: If array does not contains negative numbers, we can avoid calculations of current min product.
 *
 * Created on: 23/10/24
 * @author: Jaspreet Singh, mr.jaspreet2110@gmail.com.
 */

#include <iostream>
#include <vector>

int MaxSubArrayProductOptimised(std::vector<int>& nums)
{
  int maxProduct = nums[0];
  int currentMin = nums[0];
  int currentMax = nums[0];

  for(int i = 1; i < nums.size(); i++) {
    //Get max product at current index |currentMax|.
    int temp = std::max(std::max(nums[i], currentMax * nums[i]), currentMin * nums[i]);
    //Get min product at current index |currentMin|.
    currentMin = std::min(std::min(nums[i], currentMax * nums[i]), currentMin * nums[i]);
    currentMax = temp;

    //Update max product if needed.
    if (currentMax > maxProduct) {
      maxProduct = currentMax;
    }
  }

  return maxProduct;
}


void Test_MaxSubArrayProductOptimised()
{
  std::cout << "\nTest maximum sub array product: optimised O(n) algorithm!!!\n";
  std::vector<int> arr = { -2, 6, -3, -10, 0, 2 };
  int maxProduct = MaxSubArrayProductOptimised(arr);
  std::cout << "Sub array max product: " << maxProduct << std::endl;
}
