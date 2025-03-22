/*
 * Description:
 * Program to find numbers of characters to add at begin to make string palindrome.
 *
 * Created on: 30/11/24
 * @author: Jaspreet Singh, mr.jaspreet2110@gmail.com.
 */

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

//Helper approach 2. Generate LPS.
std::vector<int> GenerateLPS(std::string& str)
{
  std::vector<int> lps(str.size(), 0);
  lps[0] = 0;
  int i = 0;
  int len = 0;

  i++;
  while (i < str.size()) {
    if (str[i] == str[len]) {
      len++;
      lps[i] = len;
      i++;
    }
    else {
      if (len == 0) {
        lps[i] = 0;
        i++;
      } else {
        len = lps[len - 1];
      }
    }
  }
  return lps;
}

//Approach 2: Using KMP algorithm.
int CountInsertionsAtBeginToMakePalindrome_KMP(std::string& str)
{
  std::string rStr = str;
  //Reverse the string.
  std::reverse(rStr.begin(), rStr.end());

  //Form new string using delimiter.
  std::string temp = str + "$" + rStr;
  //Generate the LPS for this string.
  std::vector<int> lps = GenerateLPS(temp);

  return str.size() - lps.back();
}


//Helper for approach 1./
static bool IsPalindrome(std::string& s, int endIndex)
{
  int i = 0;

  while (i < endIndex) {
    if (s[i] != s[endIndex]) {
      return false;
    }
    i++;
    endIndex--;
  }

  return true;
}

//Approach 1. check each sub string.
int CountInsertionsAtBeginToMakePalindrome(std::string& s)
{
  int count = 0;
  for (int i = s.length() - 1; i >= 0; i--) {
    if (IsPalindrome(s, i)) {
      break;
    }
    count++;
  }
  return count;
}


void Test_CountInsertionsAtBeginToMakePalindrome()
{
  std::cout << "\nTest count insertions at begin to make string palindrome\n";
  std::string s1 = "abcd";
  std::string s2 = "aba";
  std::string s3 = "AACECAAAA";

  std::cout << "Test approach 1 (Recursion)\n";
  std::cout << "Testcase 1: Nos of insertions at begin to make string '" << s1 << "' palindrome is: " << CountInsertionsAtBeginToMakePalindrome(s1) << "\n";
  std::cout << "Testcase 2: Nos of insertions at begin to make string '" << s2 << "' palindrome is: " << CountInsertionsAtBeginToMakePalindrome(s2) << "\n";
  std::cout << "Testcase 2: Nos of insertions at begin to make string '" << s2 << "' palindrome is: " << CountInsertionsAtBeginToMakePalindrome(s3) << "\n";

  std::cout << "Test approach 2 (KMP)\n";
  std::cout << "Testcase 1: Nos of insertions at begin to make string '" << s1 << "' palindrome is: " << CountInsertionsAtBeginToMakePalindrome_KMP(s1) << "\n";
  std::cout << "Testcase 2: Nos of insertions at begin to make string '" << s2 << "' palindrome is: " << CountInsertionsAtBeginToMakePalindrome_KMP(s2) << "\n";
  std::cout << "Testcase 2: Nos of insertions at begin to make string '" << s2 << "' palindrome is: " << CountInsertionsAtBeginToMakePalindrome_KMP(s3) << "\n";
}