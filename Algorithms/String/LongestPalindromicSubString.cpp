/*
 * Description:
 * Program to find longest palindromic sub string.
 *
 * Brute force approach.
 * TC: O(n^3), SC: O(1)
 *
 * Created on: 25/10/24
 * @author: Jaspreet Singh, mr.jaspreet2110@gmail.com.
 */

#include <iostream>
#include <vector>
#include <string>

bool IsPalindrome(std::string& str, int start, int end)
{
  while (start < end) {
    if (str[start] != str[end]) {
      return false;
    }
    start++;
    end--;
  }
  return true;
}

int FindLongestPalindrome(std::string& str)
{
  if (str.empty()) {
    return 0;
  }

  //Each single character in string is a palindrome. So, min len is 1.
  int cLen = 0;
  int maxLen = 1;

  for (int i = 0; i < str.size(); i++) {
    for (int j = str.size() - 1; j > i; j--) {
      if (IsPalindrome(str, i, j)) {
        cLen = j - i + 1;
        if (cLen > maxLen) {
          maxLen = cLen;
        }
      }
    }
  }
  return maxLen;
}


void Test_FindLongestPalindrome()
{
  std::cout << "\nTest FindLongestPalindrome" << std::endl;
  std::string str1 = "abcabcbb";  //bcb -> 3
  std::string str2 = "abcracecarprq"; //racecar -> 7
  std::string str3 = "abccivicracecarcivicprq"; //-> civic + racecar + civic = 5+7+5 -> 17


  int maxLen = FindLongestPalindrome(str1);
  std::cout << "TC #1: Longest palindromic substring for string '" << str1 << "' is: " << maxLen << std::endl;

  maxLen = FindLongestPalindrome(str2);
  std::cout << "TC #2: Longest palindromic substring for string '" << str2 << "' is: " << maxLen << std::endl;

  maxLen = FindLongestPalindrome(str3);
  std::cout << "TC #3: Longest palindromic substring for string '" << str3 << "' is: " << maxLen << std::endl;
}
