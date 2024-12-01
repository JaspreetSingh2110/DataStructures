/*
 * Description:
 * Program to find numbers of characters to add at begin to make string palindrome.
 *
 * Created on: 30/11/24
 * @author: Jaspreet Singh, mr.jaspreet2110@gmail.com.
 */

#include <iostream>
#include <string>

int CountInsertionsHelper(std::string& s, int i, int j, std::vector<std::vector<int>>& memo)
{
  //Base cases
  if (i > j) {
    return INT_MAX;
  }
  //Both points at same character and obviously it is same. So no character addition needed.
  if (i == j) {
    return 0;
  }
  //2 characters
  if (i + 1 == j) {
    if (s[i] == s[j]) {
      return 0;
    }
    return 1;
  }

  //Check if previously computed values exists.
  if (memo[i][j] != -1) {
    return memo[i][j];
  }

  //Both characters same, no insertions needed.
  if (s[i] == s[j]) {
    memo[i][j] = CountInsertionsHelper(s, i + 1, j - 1, memo);
    return memo[i][j];
  }

  //Compare cases with insertions at begin/ insertions at end.
  memo[i][j] = 1 + std::min(CountInsertionsHelper(s, i+1, j, memo), CountInsertionsHelper(s, i, j - 1, memo) + 1);
  return memo[i][j];
}

//Approach 1: Recursion with memo.
//TC: Only recursion O(2^n)
//TC: With memoization O(nxn)
int CountInsertionsToMakePalindrome(std::string& s)
{
  int n = s.size();
  std::vector<std::vector<int>> memo(n + 1, std::vector<int>(n + 1, -1));

  return CountInsertionsHelper(s, 0, n -1, memo);
}


void Test_CountInsertionsToMakePalindrome()
{
  std::cout << "\nTest count insertions to make string palindrome\n";
  std::string s1 = "abc";
  std::string s2 = "aba";

  std::cout << "Testcase 1: Nos of insertions to make string '" << s1 << "' palindrome is: " << CountInsertionsToMakePalindrome(s1) << "\n";
  std::cout << "Testcase 2: Nos of insertions to make string '" << s2 << "' palindrome is: " << CountInsertionsToMakePalindrome(s2) << "\n";
}