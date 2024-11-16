/*
 * Description:
 * Program to find the longest substring with unique characters.
 *
 * Approach 1: Naive approach. Process all substrings.
 * TC: O(n^2)
 *
 * Approach 2: Sliding window.
 * TC: O(n)
 *
 * Created on: 17/11/24
 * @author: Jaspreet Singh, mr.jaspreet2110@gmail.com.
 */

#include <iostream>
#include <string>
#include <vector>

//Approach 1: Naive approach. Process all sub strings.
//TC: O(n^2)
int LongestSubstringOfUniqueCharacters_v1(std::string& s)
{
  int maxLen = 0;

  //Create all substring.
  for(int i = 0; i < s.length(); i++) {
    //Character visit tracker for given substring.
    std::vector<bool> visited(256, false);
    for (int j = i; j < s.length(); j++) {
      //If repeating character.
      if (visited[s[j]] == true) {
        break;
      }

      //Update max length.
      visited[s[j]] = true;
      maxLen = std::max(maxLen, j - i + 1);
    }
  }

  return maxLen;
}


//Approach 2: Sliding window.
//TC: O(n)
int LongestSubstringOfUniqueCharacters_v2(std::string& s)
{
  int maxLen = -1;
  std::vector<int> visited(256, false); //freq counter.

  //Process each character.
  int left = 0;
  int right = 0;
  //Traverse complete string.
  while (right < s.length()) {
    //If any repeating character is found, Move left pointer rightwards till repeating character.
    while (visited[s[right]] > 0) {
      visited[s[left]]--;
      left++;
    }

    //Update character hash and maxLen.
    visited[s[right]]++;
    maxLen = std::max(maxLen, right - left + 1);
    right++;
  }

  return maxLen;
}


void Test_LongestSubstringOfUniqueCharacters()
{
  std::cout << "\nTest longest sub string of unique characters.\n";
  std::string s1 = "abcabcbbabca";
  std::string s2 = "aabbcdeeff";

  std::cout << "Testcase 1: (approach 1) Length of sub string with unique chars in '" << s1 << "' is: "
      << LongestSubstringOfUniqueCharacters_v1(s1) << std::endl;
  std::cout << "Testcase 2: (approach 1) Length of sub string with unique chars in '" << s2 << "' is: "
      << LongestSubstringOfUniqueCharacters_v1(s2) << std::endl;

  std::cout << "Testcase 1: (approach 2) Length of sub string with unique chars in '" << s1 << "' is: "
      << LongestSubstringOfUniqueCharacters_v2(s1) << std::endl;
  std::cout << "Testcase 2: (approach 2) Length of sub string with unique chars in '" << s2 << "' is: "
      << LongestSubstringOfUniqueCharacters_v2(s2) << std::endl;
}
