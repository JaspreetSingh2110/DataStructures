/*
 * Description:
 * Program to find if two strings are isomorphic to each other.
 * Strings are isomorphic if each character can be mapped to other character in string.
 * Eg. aabccc and xxyzzz are isomorphic.
 *
 * Created on: 10/11/24
 * @author: Jaspreet Singh, mr.jaspreet2110@gmail.com.
 */

#include <iostream>
#include <string>

bool IsIsomorphic(std::string& str1, std::string& str2)
{
  if (str1.length() != str2.length()) {
    return false;
  }

  std::unordered_map<char, char> map1;
  std::unordered_map<char, char> map2;

  //Iterate over all the characters.
  for (int i = 0; i < str1.length(); i++) {
    //Create map of str1[i]->str2[i]
    if (map1.find(str1[i]) == map1.end()) {
      map1[str1[i]] = str2[i];
    }
    //Create reverse map of str2[i]->str1[i]
    if (map2.find(str2[i]) == map2.end()) {
      map2[str2[i]] = str1[i];
    }

    //Check both the mappings.
    if ((map1[str1[i]] != str2[i]) || (map2[str2[i]] != str1[i])) {
      return false;
    }
  }

  return true;
}

void Test_IsIsomorphic()
{
  std::cout << "\nTest Is isomprphic strings.\n";
  std::string str1 = "AABCDD";
  std::string str2 = "XXYZPP";
  std::string str3 = "XXYZXX";

  std::cout << "Testcase #1: Strings '" << str1 << "' and '" << str2 << "' are isomorphic (0:False/1:True): " << IsIsomorphic(str1, str2) << std::endl;
  std::cout << "Testcase #2: Strings '" << str1 << "' and '" << str3 << "' are isomorphic (0:False/1:True): " << IsIsomorphic(str1, str3) << std::endl;
}