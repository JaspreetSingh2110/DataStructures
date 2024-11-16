/*
 * Description:
 * Program to multiply two large numbers.
 *
 * Created on: 16/11/24
 * @author: Jaspreet Singh, mr.jaspreet2110@gmail.com.
 */

#include <iostream>
#include <string>
#include <vector>

//Approach 1. Using list of numbers.
std::string MultiplyLargeNumbers(std::string s1, std::string s2)
{
  std::vector<int> num1(s1.size());
  std::vector<int> num2(s2.size());
  std::vector<int> result(s1.size() + s2.size());
  std::string res = "";

  //Store numbers in reversed order in vector..
  //Convert s1 in vector.
  for (int i = 0; i < s1.size(); i++) {
    num1[i] = s1[s1.size() - i - 1] - '0';
  }
  //Convert s2 in vector.
  for (int i = 0; i < s2.size(); i++) {
    num2[i] = s2[s2.size() - i - 1] - '0';
  }

  //Multiply num1 and num2.
  for (int i = 0; i < s1.size(); i++) {
    int carry = 0;
    for (int j = 0; j < s2.size(); j++) {
      int prod = num1[i]*num2[j] + carry + result[i + j];
      carry = prod / 10;
      result[i + j] = prod % 10;
    }
    if (carry > 0) {
      result[i + s2.size()] += carry;
    }
  }

  //Convert back to result in string format and reverse order.
  for (int i = result.size() - 1; i>=0; i--) {
    res.push_back(result[i] + '0');
  }

  return res;
}


void Test_LargeNumbersMultiplication()
{
  std::cout << "\nTesting Large Numbers multiplication" << std::endl;
  std::string s1 = "1234567899082739873298723987";
  std::string s2 = "1234567892342302349823908234";

  std::cout << "TestCase #1 (Approach 1): Product is: " << MultiplyLargeNumbers(s1, s2) << std::endl;

  s1 = "23";
  s2 = "123";
  std::cout << "TestCase #2 (Approach 1): Product is: " << MultiplyLargeNumbers(s1, s2) << std::endl;
}