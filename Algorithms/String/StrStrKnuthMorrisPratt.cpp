/*
 * Description:
 * Program to implement strstr using KMP i.e. Knuth Morris Pratt's Algorithm.
 *
 * Time Complexity: O(l1+l2)
 *
 * Created on: 17/11/24
 * @author: Jaspreet Singh, mr.jaspreet2110@gmail.com.
 */

#include <iostream>
#include <string>
#include <vector>

void ConstructLPS(std::string& pattern, std::vector<int>& lps)
{
  int len = 0;
  int i = 0;

  lps[0] = 0; //For single character it is always 0.
  i++;
  //Process each character of pattern from index 1.
  while (i < pattern.size()) {
    //If both characters match, update the value and increment len.
    if (pattern[i] == pattern[len]) {
      len++;
      lps[i] = len;
      i++;
    }
    //Mismatch case.
    else {
      if (len != 0) {
        //Update len to previous lps value.
        len = lps[len-1];
      }
      else {
        //If no matching prefix is found, set it to 0.
        lps[i] = 0;
        i++;
      }
    }
  }
}

std::vector<int> StrStrKnuthMorrisPratt(std::string& ms, std::string& ss)
{
  std::vector<int> res;
  std::vector<int> lps(ss.size(), 0);
  ConstructLPS(ss, lps);

  int i = 0;
  int j = 0;
  //Process all characters of string.
  while (i < ms.size()) {
    //If characters match.
    if (ms[i] == ss[j]) {
      i++;
      j++;

      //If entire substring is matched.
      if (j == ss.size()) {
        res.push_back(i - j);
        //Update j
        j = lps[j - 1];
      }
    }
    //If mismatched.
    else {
      //If J is non zero. update it.
      if (j != 0) {
        j = lps[j - 1];
      }
      else {
        //If no further match possibility, just incr i.
        i++;
      }
    }
  }
  return res;
}

void Test_StrStrKnuthMorrisPratt()
{
  std::cout << "\nTesting StrStr using Knuth Morris Pratt's algorithm\n" << std::endl;
  std::string txt = "aabaacaadaabaaba";
  std::vector<std::string> patterns = {"aaba", "aabaab"};

  for (int i = 0; i < patterns.size(); i++) {
    std::vector<int> res = StrStrKnuthMorrisPratt(txt, patterns[i]);
    std::cout << "Testcase "<< i+1 << ": Pattern found at index(es): ";
    for (int i = 0; i < res.size(); i++) {
      std::cout << res[i] << "\t";
    }
    std::cout << std::endl;
  }
}
