/*
 * Description:
 * Program to find if string 1 is subsequence of another.
 *
 * Created on: 12/11/24
 * @author: Jaspreet Singh, mr.jaspreet2110@gmail.com.
 */

#include <iostream>
#include <string>
#include <vector>

bool IsSubSequence(std::string& ms, std::string& ss)
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

void Test_IsSubSequence()
{
  std::cout << "\nTest Is subsequence" << std::endl;
  std::vector<std::string> testStrings = {"ale", "apple", "monkey", "plea"};
  std::string mString = "abpcplea";

  std::cout << "\nTest approach #1." << std::endl;
  for (int i = 0; i < testStrings.size(); i++) {
    bool result = IsSubSequence(mString, testStrings[i]);
    if (result == true) {
      std::cout << "TC #" << i+1 << ": String '" << testStrings[i] << "' is subsequence of '" << mString << "'." << std::endl;
    }
    else {
      std::cout << "TC #" << i+1 << ": String '" << testStrings[i] << "' is not subsequence of '" << mString << "'." << std::endl;
    }
  }
}

