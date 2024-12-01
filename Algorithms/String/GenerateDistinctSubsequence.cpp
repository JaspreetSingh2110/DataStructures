/*
 * Description:
 *
 * Created on: 30/11/24
 * @author: Jaspreet Singh, mr.jaspreet2110@gmail.com.
 */

#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

//Approach 1: Using recursion.
//TC: O(2^n)
void GenerateDistinctSubsequence(std::string& str, char temp[], int i, int j, std::unordered_set<std::string>& subsequence)
{
  if (i == str.size()) {
    temp[j] = '\0';
    subsequence.insert(temp);
    return;
  }

  temp[j] = str[i];
  //Include ith character.
  GenerateDistinctSubsequence(str, temp, i + 1, j + 1, subsequence);

  //Exclude ith character.
  GenerateDistinctSubsequence(str, temp, i + 1, j, subsequence);
}


void Test_GenerateDistinctSubsequence()
{
  std::cout << "\nTest generation of distinct sub sequences\n";
  std::vector<std::string> strs = {"abc", "aba", "aaa"};
  std::unordered_set<std::string> set;
  char temp[10];

  for (int i = 0; i < strs.size(); ++i) {
    set.clear();
    memset(temp, 0, sizeof(temp));
    std::cout << "Testcase " << i + 1 << ": subsequences for string '" << strs[i] << "' are: ";
    GenerateDistinctSubsequence(strs[i], temp, 0, 0, set);
    for (std::string s : set) {
      std::cout << s << "\t";
    }
    std::cout << std::endl;
  }
}