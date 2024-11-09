/*
 * Description:
 * Program to find nos of deletions to make given string palindrome.
 * Approach #1: Recursion.
 * TC: O(2^n) -> 2 recursive calls in each step.
 * SC: O(n) -> Stack frame consumption.
 *
 * Approach #2: Using dynamic programming.
 *
 * Created on: 10/11/24
 * @author: Jaspreet Singh, mr.jaspreet2110@gmail.com.
 */

#include <iostream>
#include <string>


//Helper for approach 1.
int Helper1(std::string str, int left, int right)
{
  if (left > right) {
    return 0;
  }

  if (str[left] != str[right]) {
    return 1 + std::min(Helper1(str, left, right-1), Helper1(str, left+1, right));
  }
  return Helper1(str, left + 1, right - 1);
}

//Approach #1: Using recursion.
int CountDeletionsToMakeStringPalindrome_v1(std::string s)
{
  return Helper1(s, 0, s.size() - 1);
}

//Approach #2(TODO): Using dynamic programming.
int CountDeletionsToMakeStringPalindrome_v2(std::string s)
{
  int count = 0;
  return count;
}

void Test_CountDeletionsToMakeStringPalindrome()
{
  std::cout << "\nTest numbers of deletions required to make string palindrome.\n";
  std::string str1 = "aebcbda"; //2
  std::string str2 = "geeksforgeeks"; //8

  std::cout << "*** Testing approach #1\n";
  std::cout << "Testcase #1: Nos of deletions to make string '" << str1 << "' palindrome is: " << CountDeletionsToMakeStringPalindrome_v1(str1) << std::endl;
  std::cout << "Testcase #1: Nos of deletions to make string '" << str2 << "' palindrome is: " << CountDeletionsToMakeStringPalindrome_v1(str2) << std::endl;

  //std::cout << "*** Testing approach #2\n";
  //std::cout << "Testcase #1: Nos of deletions to make string '" << str1 << "' palindrome is: " << CountDeletionsToMakeStringPalindrome_v2(str1) << std::endl;
  //std::cout << "Testcase #1: Nos of deletions to make string '" << str1 << "' palindrome is: " << CountDeletionsToMakeStringPalindrome_v2(str1) << std::endl;
}