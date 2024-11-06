/*
* Description:
 * Program to buy and sell the stocks with max profit in single buy and single transaction.
 * Steps:
 * Iterate over elements of array once.
 * On each index, keep track of the min element, till given index.
 * Then calculate profit. Keep track of maxProfit at each index.
 * TC: O(n)
 *
 * Created on: 11/7/2024
 * @author: Jaspreet Singh, mr.jaspreet2110@gmail.com.
 */

#include <iostream>
#include <vector>

int MaxProfit_1_Transaction_Optimisedv1(std::vector<int> prices)
{
  int min = prices[0];
  int maxProfit = 0;

  for (int i = 1; i < prices.size(); i++) {
    //Keep track of min at each index.
    min = std::min(min, prices[i]);

    //Calculate profit at given index and compare it with maxProfit.
    maxProfit = std::max(maxProfit, prices[i] - min);
  }

  return maxProfit;
}

void Test_MaxProfit_1_Transaction_Optimisedv1()
{
  std::vector<int> prices1 = {7, 10, 1, 3, 6, 9, 2};  // 8
  std::vector<int> prices2 = {7, 6, 4, 3, 1};  // 0, as array is sorted in decr order.
  std::vector<int> prices3 = {1, 3, 6, 9, 11}; // 10

  std::cout << "\nTest max profit single transaction optimised v1: " << std::endl;
  std::cout << "Test case #1: Max profit is: " << MaxProfit_1_Transaction_Optimisedv1(prices1) << std::endl;
  std::cout << "Test case #2: Max profit is: " << MaxProfit_1_Transaction_Optimisedv1(prices2) << std::endl;
  std::cout << "Test case #3: Max profit is: " << MaxProfit_1_Transaction_Optimisedv1(prices3) << std::endl;
}
