/*
 * Description:
 * Program to buy and sell the stocks with max profit in single buy and single transaction.
 * TC: O(n2)
 *
 * Created on: 11/7/2024
 * @author: Jaspreet Singh, mr.jaspreet2110@gmail.com.
 */

#include <iostream>
#include <vector>

int MaxProfit_1_Transaction(std::vector<int> prices)
{
  int maxProfit = 0;

  for (int i = 0; i < prices.size(); i++) {
    for (int j = i + 1; j < prices.size(); j++) {
      maxProfit = std::max(maxProfit, prices[j] - prices[i]);
    }
  }

  return maxProfit;
}

void Test_MaxProfit_1_Transaction()
{
  std::vector<int> prices1 = {7, 10, 1, 3, 6, 9, 2};  // 8
  std::vector<int> prices2 = {7, 6, 4, 3, 1};  // 0, as array is sorted in decr order.
  std::vector<int> prices3 = {1, 3, 6, 9, 11}; // 10

  std::cout << "\nTest max profit single transaction: " << std::endl;
  std::cout << "Test case #1: Max profit is: " << MaxProfit_1_Transaction(prices1) << std::endl;
  std::cout << "Test case #2: Max profit is: " << MaxProfit_1_Transaction(prices2) << std::endl;
  std::cout << "Test case #3: Max profit is: " << MaxProfit_1_Transaction(prices3) << std::endl;
}
