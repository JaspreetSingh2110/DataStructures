/*
 * Description:
 * Program to get sub string containing all characters of other string.
 *
 * Approach 1: Naive approach. TC: O(n^3)
 * Approach 2: Hashing (characters frequency counters) and sliding window. TC: O(n)
 *
 * Created on: 17/11/24
 * @author: Jaspreet Singh, mr.jaspreet2110@gmail.com.
 */

#include <iostream>
#include <string>
#include <vector>

bool ContainsAllCharacters(std::string& ms, int start, int end, std::string& ss)
{
  char characters[256]  = {0};

  //Create frequency of characters in sec string.
  for (char &c : ss) {
    characters[c]++;
  }

  //Decr. freq counter.
  for (int i = start; i < end; i++) {
    characters[ms[i]]--;
  }

  //Check if all count is 0.
  for (int i = 0; i < 256; i++) {
    if (characters[i] > 0) {
      return false;
    }
  }
  return true;
}

//Approach 1: Naive approach. Generate and process all sub strings.
//TC: O(n^3)
int SmallestSubstringContainingAllCharactersOfOtherString_v1(std::string& ms, std::string& ss)
{
  int minLen = INT_MAX;

  //Iterate over all chars of main string.
  for(int i = 0; i < ms.size(); i++) {
    //Create all possible sub strings.
    for (int j = i + 1; j <= ms.size(); j++) {
      //Check if created sub string contains all characters of other string.
      if (ContainsAllCharacters(ms, i, j, ss)) {
        minLen = std::min(minLen, j - i);
      }
    }
  }
  return minLen;
}

//Approach 2: Using hashing.
//TC: O(n)
int SmallestSubstringContainingAllCharactersOfOtherString_v2(std::string& ms, std::string& ss)
{
  int minLen = INT_MAX;
  //Create two freq counters for characters of both strings.
  std::vector<int> msc(256, 0);
  std::vector<int> ssc(256, 0);

  //Update freq counter for sec str.
  for (int i = 0; i < ss.size(); i++) {
    ssc[ss[i]]++;
  }

  int matchCount = 0;
  int start = 0;
  for (int i = 0; i < ms.size(); i++) {
    msc[ms[i]]++;

    //Update matched characters count.
    if (msc[ms[i]] <= ssc[ms[i]]) {
      matchCount++;
    }

    //If all characters matched i.e. match count is same as length of ss.
    if (matchCount == ss.size()) {
      //Right shift start pointer.
      while ((ssc[ms[start]] == 0) || (msc[ms[start]] > ssc[ms[start]])) {
        if (msc[ms[start]] > 0) {
          msc[ms[start]]--;
        }
        start++;
      }

      //Update min len.
      minLen = std::min(minLen, i - start + 1);
    }
  }

  return minLen;
}

void Test_SmallestSubstringContainingAllCharactersOfOtherString()
{
  std::cout << "\nTesting Smallest Substring Containing All Characters Of Other String" << std::endl;
  std::string ms1 = "timetopractice";
  std::string ms2 = "datastructuresalgo";
  std::string ms3 = "abadcbcd";
  std::string ss1 = "toc";
  std::string ss2 = "tttoc";
  std::string ss3 = "tpl";
  std::string ss4 = "dor";
  std::string ss5 = "bcc";

  std::cout << "Testcase 1 (approach 1): Min. length: " << SmallestSubstringContainingAllCharactersOfOtherString_v1(ms1, ss1) << std::endl;
  std::cout << "Testcase 1 (approach 1): Min. length: " << SmallestSubstringContainingAllCharactersOfOtherString_v1(ms1, ss2) << std::endl;
  std::cout << "Testcase 2 (approach 1): Min. length: " << SmallestSubstringContainingAllCharactersOfOtherString_v1(ms1, ss3) << std::endl;
  std::cout << "Testcase 3 (approach 1): Min. length: " << SmallestSubstringContainingAllCharactersOfOtherString_v1(ms2, ss4) << std::endl;
  std::cout << "Testcase 4 (approach 1): Min. length: " << SmallestSubstringContainingAllCharactersOfOtherString_v1(ms3, ss5) << std::endl;

  std::cout << std::endl;
  std::cout << "Testcase 1 (approach 2): Min. length: " << SmallestSubstringContainingAllCharactersOfOtherString_v2(ms1, ss1) << std::endl;
  std::cout << "Testcase 1 (approach 2): Min. length: " << SmallestSubstringContainingAllCharactersOfOtherString_v2(ms1, ss2) << std::endl;
  std::cout << "Testcase 2 (approach 2): Min. length: " << SmallestSubstringContainingAllCharactersOfOtherString_v2(ms1, ss3) << std::endl;
  std::cout << "Testcase 3 (approach 2): Min. length: " << SmallestSubstringContainingAllCharactersOfOtherString_v2(ms2, ss4) << std::endl;
  std::cout << "Testcase 4 (approach 2): Min. length: " << SmallestSubstringContainingAllCharactersOfOtherString_v2(ms3, ss5) << std::endl;
}