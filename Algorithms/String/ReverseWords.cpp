/*
 * Description:
 * Program to reverse string word by word.
 * Input: str = “i.like.this.program.very.much”
 * Output: str = “much.very.program.this.like.i”
 *
 * Approach 1: Using stack.
 * TC: O(n), SC O(n)
 *
 * Approach 2: Word by word reverse (without extra space).
 * TC O(n)
 *
 * Created on: 09/11/24
 * @author: Jaspreet Singh, mr.jaspreet2110@gmail.com.
 */

#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

//Approach #1: Using stack.
std::string ReverseWords_v1(std::string& str, char delimiter)
{
  std::string temp;
  std::stack<std::string> st;
  std::string final;

  //Extract words from main string and put them in stack.
  //The last word may have delimiter in end or may not.
  //So, either add delimiter explicitly, or at end add last word to stack after loop ends.
  for (char c : str) {
    if (c == delimiter) {
      if (!temp.empty()) {
        st.push(temp);
        temp.clear();
      }
      continue;
    }
    temp += c;
  }
  //For last word, if it ends without delimiter.
  if (!temp.empty()) {
    st.push(temp);
    temp.clear();
  }

  while (!st.empty()) {
    final += st.top();
    st.pop();
    if (!st.empty()) {
      final += ".";
    }
  }
  return final;
}

//Approach #2: Reverse string then words.
std::string ReverseWords_v2(std::string str, char delimiter)
{
  //Reverse the main string.
  std::reverse(str.begin(), str.end());

  int start = 0;
  for (int i = 0; i < str.size(); i++) {
    if ((str[i] == delimiter) || (i == str.size() - 1)) {
      if (i - start == 1) {
        start = i;
        continue;
      }
      std::reverse(str.begin() + start, str.begin() + i);
      start = i + 1;
    }
  }
  return str;
}

void Test_ReverseWords()
{
  std::cout << "\nTest program to reverse string in word by word format.\n";
  std::string str1 = ".i.like.this.program.very.much.";
  std::string str2 = ".This.is.program.to.reverse.string.word.by.word.";

  //Approach 1
  std::cout << "Testcase #1: (approach 1) Reversed string for main string: " << str1 << " is: " << ReverseWords_v1(str1, '.') << std::endl;
  std::cout << "Testcase #2: (approach 1) Reversed string for main string: " << str2 << " is: " << ReverseWords_v1(str2, '.') << std::endl;

  //Approach 2
  std::cout << "Testcase #1: (approach 2) Reversed string for main string: " << str1 << " is: " << ReverseWords_v2(str1, '.') << std::endl;
  std::cout << "Testcase #2: (approach 2) Reversed string for main string: " << str2 << " is: " << ReverseWords_v2(str2, '.') << std::endl;
}