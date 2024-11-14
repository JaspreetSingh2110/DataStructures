/*
* Description:
 * Program to find if two strings are K-Anagrams.
 * Strings are anagrams if count of each characters in string are same.
 * K anagrams means : Strings can become anagrams after changing k nos of characters.
 *
 * Created on: 10/11/24
 * @author: Jaspreet Singh, mr.jaspreet2110@gmail.com.
 */

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>


//Approach #1: Using unordered set as frequency counter.
bool IsKAnagrams_v1(std::string& str1, std::string& str2, int k)
{
  if(str1.length() != str2.length()) {
    return false;
  }

  //Create Map of characters with their occurrence count.
  std::unordered_map<char, int> map;

  //Create map from string1
  for(int i = 0; i < str1.length(); i++) {
    if (map.find(str1[i]) == map.end()) {
      map[str1[i]] = 1;
    }
    else {
      map[str1[i]]++;
    }
  }

  //Iterate over characters of 2nd string and decrement the counters.
  for(int i = 0; i < str2.length(); i++) {
    if (map.find(str2[i]) != map.end()) {
      map[str2[i]]--;
    }
  }

  //Iterate over map again and find the total positive count.
  int count = 0;
  for(auto it = map.begin(); it != map.end(); it++) {
    if(it->second > 0) {
      count = count + it->second;
    }
  }

  return (count == k);
}


//Approach #2: Using array (26 chars) as a frequency counter.
bool IsKAnagrams_v2(std::string& str1, std::string& str2, int k)
{
  if(str1.length() != str2.length()) {
    return false;
  }

  //Create array of 26 size to keep track of characters frequency.
  std::vector<int> fc(26, 0);

  //Update frequency counter.
  for(int i = 0; i < str1.length(); i++) {
    fc[str1[i] - 'a']++;
  }

  //Iterate over characters of 2nd string and decrement the counters.
  int count = 0;
  for(int i = 0; i < str2.length(); i++) {
    if (fc[str2[i] - 'a'] > 0) {
      fc[str2[i] - 'a']--;
    }
    else {
      count++;
    }

    if (count > k) {
      return false;
    }
  }

  return (count == k);
}

void Test_IsKAnagrams()
{
  std::cout << "\nTest Is K-Anagrams strings.\n";
  std::string str1 = "anagram";
  std::string str2 = "grammer";
  std::string str3 = "analogy";

  std::cout << "*** Testing approach #1\n";
  std::cout << "Testcase #1: Strings '" << str1 << "' and '" << str2 << "' are K-anagrams (0:False/1:True): " << IsKAnagrams_v1(str1, str2, 3) << std::endl;
  std::cout << "Testcase #2: Strings '" << str1 << "' and '" << str3 << "' are K-anagrams (0:False/1:True): " << IsKAnagrams_v1(str1, str3, 4) << std::endl;
  std::cout << "Testcase #3: Strings '" << str1 << "' and '" << str3 << "' are K-anagrams (0:False/1:True): " << IsKAnagrams_v1(str1, str3, 3) << std::endl;

  std::cout << "*** Testing approach #2\n";
  std::cout << "Testcase #1: Strings '" << str1 << "' and '" << str2 << "' are K-anagrams (0:False/1:True): " << IsKAnagrams_v2(str1, str2,3) << std::endl;
  std::cout << "Testcase #2: Strings '" << str1 << "' and '" << str3 << "' are K-anagrams (0:False/1:True): " << IsKAnagrams_v2(str1, str3, 4) << std::endl;
  std::cout << "Testcase #3: Strings '" << str1 << "' and '" << str3 << "' are K-anagrams (0:False/1:True): " << IsKAnagrams_v2(str1, str3, 3) << std::endl;
}