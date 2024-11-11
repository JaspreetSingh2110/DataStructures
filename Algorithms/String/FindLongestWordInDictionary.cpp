/*
* Description:
 * Program to find longest subsequence word in dictionary.
 * Approach:
 * Among all the given words, check if it is subsequence of main string given.
 * If yes, store its length.
 * At end, return word with max length.
 *
 * Created on: 12/11/24
 * @author: Jaspreet Singh, mr.jaspreet2110@gmail.com.
 */

#include <iostream>
#include <string>
#include <vector>

bool IsSubSequenceAPI(std::string& ms, std::string& ss)
{
  //Iterate over both strings.
  int si = 0;
  for (int mi = 0; mi < ms.size() && si < ss.size(); mi++) {
    if (ms[mi] == ss[si]) {
      si++;
    }
  }

  return (si == ss.size());
}

std::string FindLongestWordInDictionary(std::vector<std::string>& words, std::string str)
{
  std::string result;

  //Process each word.
  for (int i = 0; i < words.size(); i++) {
    if (IsSubSequenceAPI(str, words[i])) {
      if (words[i].size() > result.size()) {
        result = words[i];
      }
    }
  }
  return result;
}

void Test_FindLongestSubSequenceWordInDict()
{
  std::cout << "\nTest find longest subsequence word in dict" << std::endl;
  std::vector<std::string> testStrings = {"ale", "apple", "monkey", "plea"};
  std::string mString = "abpcplea";

  std::cout << "\nTest approach #1." << std::endl;
  std::string result = FindLongestWordInDictionary(testStrings, mString);
  std::cout << "TC #1: Longest subsequence word in dict is '" << result << "'." << std::endl;
}