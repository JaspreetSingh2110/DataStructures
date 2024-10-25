/*
* Description:
 * Program to find longest palindromic sub string.
 *
 * Dynamic programming approach.
 * TC: O(n^2), SC: O(nxn)
 *
 * Created on: 25/10/24
 * @author: Jaspreet Singh, mr.jaspreet2110@gmail.com.
 */

#include <iostream>
#include <vector>
#include <string>

std::string FindLongestPalindrome_DP(std::string& str)
{
  if (str.empty()) {
    return 0;
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


void Test_FindLongestPalindrome_DP()
{
  std::cout << "\nTest FindLongestPalindrome (DP)" << std::endl;
  std::string str1 = "abcabcbb";  //bcb -> 3
  std::string str2 = "abcracecarprq"; //racecar -> 7
  std::string str3 = "abccivicracecarcivicprq"; //-> civic + racecar + civic = 5+7+5 -> 17


  std::string maxLenPalindromeStr = FindLongestPalindrome_DP(str1);
  //std::cout << "TC #1: Longest palindromic substring for string '" << str1 << "' is: " << maxLenPalindromeStr << std::endl;

  maxLenPalindromeStr = FindLongestPalindrome_DP(str2);
  std::cout << "TC #2: Longest palindromic substring for string '" << str2 << "' is: " << maxLenPalindromeStr << std::endl;

  maxLenPalindromeStr = FindLongestPalindrome_DP(str3);
  std::cout << "TC #3: Longest palindromic substring for string '" << str3 << "' is: " << maxLenPalindromeStr << std::endl;
}
