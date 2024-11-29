/*
 * Description:
 *
 * Created on: 29/11/24
 * @author: Jaspreet Singh, mr.jaspreet2110@gmail.com.
 */

#include <iostream>
#include <vector>
#include <stack>

//TC: O(n) using stack.
std::vector<int> FindStockSpan(std::vector<int> arr)
{
  std::vector<int> result(arr.size(), 0);
  std::stack<int> s;
  //indexes.
  s.push(0);
  result[0] = 1;

  //Iterate over remaining elements
  for(int i = 1; i < arr.size(); i++) {
    //Pop out all indexes those values are lesser than current value.
    while (!s.empty() && (arr[s.top()] <= arr[i])) {
      s.pop();
    }

    if (s.empty()) {
      //All elements prior to this lesser than current value.
      //Because default is 1, result is current index + 1.
      result[i] = i + 1;
    } else {
      result[i] = i - s.top();
    }

    s.push(i);
  }
  return result;
}

void Test_StockSpan()
{
  std::cout << "\nTesting Stock Span..." << std::endl;
  std::vector<std::vector<int>> arr = {{ 10, 4, 5, 90, 120, 80 },{ 100, 80, 60, 70, 60, 75, 85 }};

  for (int i = 0; i < arr.size(); ++i) {
    std::cout << "Testcase " << i + 1 << ": Stock span result: ";
    std::vector<int> res = FindStockSpan(arr[i]);
    for (int j = 0; j < res.size(); ++j) {
      std::cout << res[j] << " ";
    }
    std::cout << std::endl;
  }
}