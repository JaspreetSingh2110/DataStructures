/*
 * Description:
 * Algorithm to calculate sub array with maximum product.
 * Brute force approach: O(n^2)
 *
 * Created on: 23/10/24
 * @author: Jaspreet Singh, mr.jaspreet2110@gmail.com.
 */

#include <iostream>
#include <vector>

int MaxSubArrayProduct(std::vector<int>& nums)
{
  int maxProduct = nums[0];
  int currentProduct = 1;

  for(int i = 0; i < nums.size(); i++) {
    //Reset multiplier.
    currentProduct = 1;

    //Find product i with i+1, i+2 ... n-2, n-1, n.
    for (int j = i; j < nums.size(); j++) {
      currentProduct *= nums[j];

      if (currentProduct > maxProduct) {
        maxProduct = currentProduct;
      }
    }
  }

  return maxProduct;
}


void Test_MaxSubArrayProduct()
{
  std::cout << "\nTest maximum sub array product: BRUTE FORCE algorithm!!!\n";
  std::vector<int> arr = { -2, 6, -3, -10, 0, 2 };
  int maxProduct = MaxSubArrayProduct(arr);
  std::cout << "Sub array max product: " << maxProduct << std::endl;
}
