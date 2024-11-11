/*
 * Description:
 * Program for longest palindromic subsequence.
 *
 * Approach #1: Recursive approach.
 * TC: O(2^n)
 *
 * Approach #2: Recursive approach with memoization.
 * TC: O(n*n), SC: O(n*n)
 *
 * Approach #3: Dynamic programming.
 * TC: O(n*n), SC: O(n*n)
 *
 * Created on: 12/11/24
 * @author: Jaspreet Singh, mr.jaspreet2110@gmail.com.
 */

#include <iostream>
#include <string>
#include <vector>

//Approach #1: Recursion.
int FindLongestPalindromeSubSequence_v1(std::string &s, int start, int end)
{
  //Single character is palindrome and has length 1.
  if (start == end) {
    return 1;
  }

  //Only two characters and are same.
  if ((start + 1 == end) && (s[start] == s[end])) {
    return 2;
  }

  if (s[start] == s[end]) {
    return 2 + FindLongestPalindromeSubSequence_v1(s, start + 1, end - 1);
  }
  return std::max(FindLongestPalindromeSubSequence_v1(s, start + 1, end),
    FindLongestPalindromeSubSequence_v1(s, start, end - 1));
}


//Approach #2: Recursion with memoization.
int FindLongestPalindromeSubSequence_v2(std::string &s, int start, int end, std::vector<std::vector<int>> &m)
{
  //Single character.
  if (start == end) {
    return 1;
  }

  //Two characters and are same.
  if ((start + 1 == end) && (s[start] == s[end])) {
    return 2;
  }

  //Check if pre-processed value exist in memory.
  if (m[start][end] != 0) {
    return m[start][end];
  }

  //Compute the value and make recursive calls.
  if (s[start] == s[end]) {
    m[start][end] = 2 + FindLongestPalindromeSubSequence_v2(s, start + 1, end - 1, m);
    return m[start][end];
  }

  m[start][end] = std::max(FindLongestPalindromeSubSequence_v2(s, start + 1, end, m),
    FindLongestPalindromeSubSequence_v2(s, start, end - 1, m));
  return m[start][end];
}


//Approach #3: Using dynamic programming.
/*
 * Algorithm:
 * if str[i] == str[j]:
 *   dp[i][j] = dp[i+1][j-1] + 2 //diagonal left down value + 2.
 * else:
 *   dp[i][j] = max(dp[i][j-1], dp[i+1][j]) //max of left cell or bottom cell.
 *
 * dp[0][n-1] = max length value.
 */
int FindLongestPalindromeSubSequence_v3(std::string &s)
{
  int len = s.size();
  //Create a 2-D array for DP (len x len).
  std::vector<std::vector<int>> dp(len, std::vector<int>(len, 0));

  //Update initial diagonal values in dp.
  for (int i = 0; i < len; i++) {
    dp[i][i] = 1;
  }

  //NOTE: We need to traverse dp diagonally as to compute value for cell (i,j),
  // we have dependency on values at down and diagonal cells.
  //i = len - 2, because we have to start filling dp matrix from down to top.
  //So, we have already filled the diagonal elements, so, (len-1, len-1) is already filled.
  //Hence, we have to start from len -2.
  for (int i = len - 2; i >= 0; i--) {
    for (int j = i + 1; j < len; j++) {
      if (s[i] == s[j]) {
        dp[i][j] = dp[i + 1][j - 1] + 2;
      }
      else {
        dp[i][j] = std::max(dp[i + 1][j], dp[i][j - 1]);
      }
    }
  }

  return dp[0][len - 1];
}

void Test_FindLongestPalindromeSubSequence()
{
  std::cout << "\nTest FindLongestPalindrome" << std::endl;
  std::string str1 = "abcabcbb";  //bcacb -> 5
  std::string str2 = "abcracecarprq"; //racecar -> 7
  std::string str3 = "abccivicracecarcivicprq"; //-> civic + racecar + civic = 5+7+5 -> 17
  std::string str4 = "jasapj"; //jasaj -> 5
  std::string str5 = "BBABCBCAB"; //BABCBAB -> 7


  std::vector<std::string> testStrings = {str1, str2, str3, str4, str5};

  std::cout << "\nTest approach #1 (recursive)" << std::endl;
  for (int i = 0; i < testStrings.size(); i++) {
    int maxLen = FindLongestPalindromeSubSequence_v1(testStrings[i], 0, testStrings[i].length() - 1);
    std::cout << "TC #" << i+1 << ": Longest palindromic subsequence for string '" << testStrings[i] << "' is: " << maxLen << std::endl;
  }

  std::cout << "\nTest approach #2 (recursive with memoization)" << std::endl;
  for (int i = 0; i < testStrings.size(); i++) {
    //Create array for memoization.
    int l = testStrings[i].length();
    std::vector<std::vector<int>> m(l + 1, std::vector<int>(l + 1, 0));
    int maxLen = FindLongestPalindromeSubSequence_v2(testStrings[i], 0, l - 1, m);
    std::cout << "TC #" << i+1 << ": Longest palindromic subsequence for string '" << testStrings[i] << "' is: " << maxLen << std::endl;
  }

  std::cout << "\nTest approach #3 (DP)" << std::endl;
  for (int i = 0; i < testStrings.size(); i++) {
    int maxLen = FindLongestPalindromeSubSequence_v3(testStrings[i]);
    std::cout << "TC #" << i+1 << ": Longest palindromic subsequence for string '" << testStrings[i] << "' is: " << maxLen << std::endl;
  }
}