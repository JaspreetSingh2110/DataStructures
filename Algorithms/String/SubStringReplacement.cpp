/*
 * Description:
 * Program to replace substring in a string with other string.
 * eg. Main string = "jaspreet", substr = "pr", replacement str = singh.
 * O/p: jassingheet.
 *
 * Approach 1: Naive approach. TC: O(N*M)
 *
 * Approach 2: Using KMP. Will be done in the future.
 *
 * Created on: 16/11/24
 * @author: Jaspreet Singh, mr.jaspreet2110@gmail.com.
 */

#include <iostream>
#include <string>

//Approach 1: Naive approach.
std::string ReplaceSubStrings_v1(std::string ms, std::string ss, std::string rs)
{
  std::string result;
  if (ss.size() > ms.size()) {
    return "";
  }

  //Iterate over each character of main string to find the sub string.
  for (int i = 0; i < ms.size(); i++) {
    //Check if substring possibility is there.
    if ((ms[i] == ss[0]) && (i + ss.size() < ms.size())) {
      //Get substring from starting character.
      std::string substr = ms.substr(i, ss.size());
      if (substr == ss) {
        result.append(rs);
        //Update ith position.
        i += ss.size() - 1;
      }
      else {
        result.push_back(ms[i]);
      }
    }
    else {
      result.push_back(ms[i]);
    }
  }

  return result;
}

void Test_ReplaceSubStrings()
{
  std::cout << "\nTest ReplaceSubStrings.\n" << std::endl;
  std::string ms = "jaspreet";
  std::string ss = "pr";
  std::string rs = "singh";

  std::cout << "Result: " << ReplaceSubStrings_v1(ms, ss, rs) << std::endl;
}
