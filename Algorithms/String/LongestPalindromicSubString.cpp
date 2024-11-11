/*
 * Description:
 * Program to find longest palindromic sub string.
 *
 * Approach #1: Brute force approach. (Iterative)
 * TC: O(n^3), SC: O(1)
 *
 * Created on: 25/10/24.
 * Updated rev2: 12/11/24.
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

//Approach #1: Iterative.
int FindLongestPalindrome_v1(std::string& str)
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

//Approach #2: Using dynamic programming.
std::string FindLongestPalindromeSubString_DP(std::string& str)
{
  if (str.empty()) {
    return str;
  }

  int size = str.size();
  int maxLen = 1;
  int startIndex = 0;
  std::vector<std::vector<bool>> dp(size, std::vector<bool>(size, false));

  //Substring of size 1 are always palindrome.
  for (int i = 0; i < size; i++) {
    dp[i][i] = true;
    startIndex = i;
  }

  //Substring of size 2. If both characters are same, it is palindrome.
  for (int i = 0; i < size; i++) {
    if (str[i] == str[i + 1]) {
      dp[i][i + 1] = true;
      maxLen = 2;
      startIndex = i;
    }
  }

  //Size grater than 2. Increment diff by 1 in each loop.
  for (int diff = 2; diff <= size; diff++) {
    for (int i = 0; i < size - diff; i++) {
      int j = i + diff;

      if ((str[i] == str[j]) && (dp[i+1][j-1] == true)) {
        dp[i][j] = true;

        if (diff >= maxLen) {
          maxLen = diff + 1;
          startIndex = i;
        }
      }
    }
  }
  return str.substr(startIndex, maxLen);
}


void Test_FindLongestPalindromeSubString()
{
  std::cout << "\nTest FindLongestPalindrome" << std::endl;
  std::string str1 = "abcabcbb";  //bcb -> 3
  std::string str2 = "abcracecarprq"; //racecar -> 7
  std::string str3 = "abccivicracecarcivicprq"; //-> civic + racecar + civic = 5+7+5 -> 17
  std::string str4 = "jasapj";

  std::vector<std::string> testStrings = {str1, str2, str3, str4};

  std::cout << "\nTest approach #1 (BF)" << std::endl;
  for (int i = 0; i < testStrings.size(); i++) {
    int maxLen = FindLongestPalindrome_v1(testStrings[i]);
    std::cout << "TC #" << i+1 << ": Longest palindromic subsequence for string '" << testStrings[i] << "' is: " << maxLen << std::endl;
  }

  std::cout << "\nTest approach #2 (DP)" << std::endl;
  for (int i = 0; i < testStrings.size(); i++) {
    std::string res = FindLongestPalindromeSubString_DP(testStrings[i]);
    std::cout << "TC #" << i+1 << ": Longest palindromic subsequence for string '" << testStrings[i] << "' is: " << res << std::endl;
  }
}
