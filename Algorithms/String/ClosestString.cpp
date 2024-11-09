/*
 * Description:
 * Given an array of strings and two words, find the min distance b/w both words.
 *
 * Created on: 10/11/24
 * @author: Jaspreet Singh, mr.jaspreet2110@gmail.com.
 */

#include <iostream>
#include <string>
#include <vector>

int FindClosestDistance(std::vector<std::string> words, const std::string& s1, const std::string& s2)
{
  int result = INT_MAX;
  int index1 = -1;
  int index2 = -1;

  for (int i = 0; i < words.size(); i++) {
    if (s1 == words[i]) {
      index1 = i;
    }
    if (s2 == words[i]) {
      index2 = i;
    }
    if (index1 != -1 && index2 != -1) {
      result = std::min(result, abs(index1 - index2));
    }
  }
  return result;
}

void Test_FindClosestDistance()
{
  std::cout << "\nTesting find closest distance b/w two words in array of strings.\n";
  std::vector<std::string> words = {"the", "quick", "brown", "fox", "is", "fastest"};
  std::string word1 = "the";
  std::string word2 = "fox";
  std::string word3 = "is";

  int result = FindClosestDistance(words, word1, word2);
  std::cout << "Test case #1: The closest distance b/w words is: " << result << "\n";

  result = FindClosestDistance(words, word3, word1);
  std::cout << "Test case #1: The closest distance b/w words is: " << result << "\n";
}