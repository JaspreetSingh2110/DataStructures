/*
 * Description:
 * Program to add two large numbers.
 *
 * Created on: 16/11/24
 * @author: Jaspreet Singh, mr.jaspreet2110@gmail.com.
 */

#include <iostream>
#include <string>
#include <algorithm>

//Approach 1. Make both strings equal size and create sun character by character.
std::string AddLargeNumbers(std::string s1, std::string s2)
{
  int l1 = s1.length();
  int l2 = s2.length();

  //Make both strings of equal size by inserting 0s at begin of small string.
  if (l1 < l2) {
    s1.insert(0, l2 - l1, '0');
    l1 = l2;
  }
  else {
    s2.insert(0, l1 - l2, '0');
    l2 = l1;
  }

  int carry = 0;
  for (int i = l1 - 1; i >= 0; i--) {
    int sum = (s1[i] - '0') + (s2[i] - '0') + carry;
    carry = sum / 10;
    s1[i] = (sum % 10) + '0';
  }

  if (carry) {
    s1.insert(0, 1, carry + '0');
  }
  return s1;
}

//Approach #2: Without making strings equal size. School method.
std::string AddLargeNumbers_v2(std::string s1, std::string s2)
{
  std::string result;

  //Keep smaller string in s1.
  if (s1.length() > s2.length()) {
    s1.swap(s2);
  }

  int l1 = s1.length();
  int l2 = s2.length();

  //First process the smallest string.
  int carry = 0;
  for (int i = l1 - 1; i >= 0; i--) {
    int sum = (s1[i] - '0') + (s2[i] - '0') + carry;
    carry = sum / 10;
    result.push_back(sum % 10 + '0');
  }

  //Process the remaining characters in bigger string.
  for (int i = l2 - l1 - 1; i >= 0; i--) {
    int sum = (s2[i] - '0') + carry;
    carry = sum / 10;
    result.push_back(sum % 10 + '0');
  }

  if (carry) {
    result.push_back(carry + '0');
  }

  //Reverse the result string.
  std::reverse(result.begin(), result.end());
  return result;
}


void Test_LargeNumbersAddition()
{
  std::cout << "\nTesting Large Numbers Addition" << std::endl;
  std::string s1 = "1234567899082739873298723987";
  std::string s2 = "1234567892342302349823908234";

  std::cout << "TestCase #1 (Approach 1): Sum is: " << AddLargeNumbers(s1, s2) << std::endl;
  std::cout << "TestCase #1 (Approach 2): Sum is: " << AddLargeNumbers_v2(s1, s2) << std::endl;

  s1 = "123";
  s2 = "999";
  std::cout << "TestCase #2 (Approach 1): Sum is: " << AddLargeNumbers(s1, s2) << std::endl;
  std::cout << "TestCase #2 (Approach 2): Sum is: " << AddLargeNumbers_v2(s1, s2) << std::endl;
}