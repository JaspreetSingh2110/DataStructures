/*
 * Description:
 * Program to buy and sell stocks with max profit in single transaction.
 *
 * Created on: 29/11/24
 * @author: Jaspreet Singh, mr.jaspreet2110@gmail.com.
 */

#include <iostream>
#include <vector>

int MaxProfit_Single_Transaction(std::vector<int> prices)
{
  int maxProfit = 0;
  int n = prices.size();

  int buyIndex = 0;
  int SellIndex = -1;

  for (int i = 1; i < n; i++) {
    if (prices[i] > prices[buyIndex]) {
      maxProfit = std::max(maxProfit, prices[i] - prices[buyIndex]);
    }
    else {
      buyIndex = i;;
    }
  }

  return maxProfit;
}

void Test_StockBuySell_1()
{
  std::cout << "\nTest stock buy and sell 1 transaction\n";
  std::vector<std::vector<int>> prices = {{7, 10, 1, 3, 6, 9, 2}, {7, 6, 4, 3, 1} , {1, 3, 6, 9, 11}};

  for (int i = 0; i < prices.size(); i++) {
    std::cout << "Testcase: " << i + 1 << ", max profit: " << MaxProfit_Single_Transaction(prices[i]) << std::endl;
  }
}