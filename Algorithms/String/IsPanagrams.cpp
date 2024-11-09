/*
* Description:
 * Program to find if given string is panagram.
 * String is panagram if it contains all alphabetical characters at least once.
 *
 * Approach #1: TC O(n)
 * Approach #2: TC O(nlogn) -> n for iteration over each character, logn for set insert operations.
 *
 * Created on: 10/11/24
 * @author: Jaspreet Singh, mr.jaspreet2110@gmail.com.
 */

#include <iostream>
#include <set>
#include <string>

constexpr int MAX_CHAR = 26;

//Approach #1: Using frequency counter.
bool IsPanagrams_v1(std::string& str)
{
  if(str.length() < MAX_CHAR) {
    return false;
  }

  //Create array for character frequency count.
  std::vector<int> fc(MAX_CHAR, 0);

  //Create map from string1
  for(int i = 0; i < str.length(); i++) {
    if (str[i] >= 'a' && str[i] <= 'z') {
      fc[str[i] - 'a']++;
    }
    else if (str[i] >= 'A' && str[i] <= 'Z') {
      fc[std::tolower(str[i]) - 'a']++;
    }
  }

  //Iterate over frequency counter again to see if any all characters were present.
  for(int i = 1; i < MAX_CHAR; i++) {
    if (fc[i] == 0) {
      return false;
    }
  }

  return true;
}


//Approach #2: Using set.
bool IsPanagrams_v2(std::string& str)
{
  if(str.length() < MAX_CHAR) {
    return false;
  }
  //Create a set.
  std::set<char> s;

  for(int i = 0; i < str.length(); i++) {
    if (str[i] >= 'a' && str[i] <= 'z') {
      s.insert((str[i]));
    }
    else if (str[i] >= 'A' && str[i] <= 'Z') {
      s.insert(std::tolower(str[i]));
    }
  }

  return (s.size() == MAX_CHAR);
}


void Test_IsPanagrams()
{
  std::cout << "\nTest Is Panagrams strings.\n";
  std::string str1 = "The quick brown fox jumps over the lazy dog";
  std::string str2 = "The quick brown fox jumps over the dog"; //lzy missing.

  std::cout << "*** Testing approach #1\n";
  std::cout << "Testcase #1: String '" << str1 << "' is panagram: (0:False/1:True): " << IsPanagrams_v1(str1) << std::endl;
  std::cout << "Testcase #2: String '" << str2 << "' is panagram: (0:False/1:True): " << IsPanagrams_v1(str2) << std::endl;

  std::cout << "*** Testing approach #2\n";
  std::cout << "Testcase #1: String '" << str1 << "' is panagram: (0:False/1:True): " << IsPanagrams_v2(str1) << std::endl;
  std::cout << "Testcase #2: String '" << str2 << "' is panagram: (0:False/1:True): " << IsPanagrams_v2(str2) << std::endl;
}