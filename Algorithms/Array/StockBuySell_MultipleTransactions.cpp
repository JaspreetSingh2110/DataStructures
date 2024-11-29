/*
* Description:
 * Program to buy and sell stocks with max profit in multiple transaction.
 *
 * Created on: 29/11/24
 * @author: Jaspreet Singh, mr.jaspreet2110@gmail.com.
 */

#include <iostream>
#include <vector>

int MaxProfitMultipleTransactions(std::vector<int> prices)
{
  int maxProfit = 0;
  int n = prices.size();

  for (int i = 1; i < n; i++) {
    if (prices[i] > prices[i-1]) {
      maxProfit += (prices[i] - prices[i-1]);
    }
  }

  return maxProfit;
}

void Test_StockBuySellMultipleTransactions()
{
  std::cout << "\nTest stock buy and sell multiple transactions\n";
  std::vector<std::vector<int>> prices = {{7, 10, 1, 3, 6, 9, 2}, {100, 180, 260, 310, 40, 535, 695}};

  for (int i = 0; i < prices.size(); i++) {
    std::cout << "Testcase: " << i + 1 << ", max profit: " << MaxProfitMultipleTransactions(prices[i]) << std::endl;
  }
}