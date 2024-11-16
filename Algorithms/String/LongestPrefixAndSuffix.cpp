/*
 * Description:
 * Program to find longest prefix and suffix. (both same)
 *
 * Approach 1: Naive approach. TC: O(n^2)
 *
 * Approach 2: Using KMP. Will be done in the future.
 *
 * Created on: 16/11/24
 * @author: Jaspreet Singh, mr.jaspreet2110@gmail.com.
 */

#include <iostream>
#include <string>

//Approach 1: Naive approach.
int LengthOfLongestPrefixSuffix_v1(const std::string& s)
{
  int len = 0;
  int maxLen = 0;

  //Iterate over each character of string.
  for(int i = 0; i < s.length()/2; i++) {
    len = 0;
    //Compare sub string of length i + 1 from begin and end.
    for (int j = 0; j <= i; j++) {
      if (s[j] == s[s.length() - 1 - i + j]) {
        len++;
      }
      else {
        break;
      }
    }

    //If equal sized prefix and suffix are found, update length.
    if ((len == i + 1) && (len > maxLen)) {
      maxLen = len;
    }
  }

  return maxLen;
}

void Test_LengthOfLongestPrefixSuffix()
{
  std::cout << "\nTest longest suffix and prefix.\n";
  std::string s1 = "abcabcbbabca";

  std::cout << "Testcase 1: Length of longest prefix-suffix in string " << s1 << " is: "
    << LengthOfLongestPrefixSuffix_v1(s1) << std::endl;
}
