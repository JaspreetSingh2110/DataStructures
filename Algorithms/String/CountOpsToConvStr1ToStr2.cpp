/*
 * Description:
 * Program to count numbers of operations to convert string1 to string2.
 *
 * Approach #1: Recursive.
 * TC: O(3^m)
 *
 * Approach #2: Recursion with memoization.
 * TC: O(mxn)
 *
 * Created on: 18/11/24
 * @author: Jaspreet Singh, mr.jaspreet2110@gmail.com.
 */

#include <iostream>
#include <string>

//Approach #1: Recursive.
int CountOps_v1(const std::string& s1, const std::string& s2, int l1, int l2)
{
  //If strings reaches first characters.
  if (l1 == 0) {
    return l2;
  }
  if (l2 == 0) {
    return l1;
  }

  if (s1[l1 - 1] == s2[l2 - 1]) {
    return CountOps_v1(s1, s2, l1 - 1, l2 - 1);
  }
  //1 + min(insert, remove, replace).
  return 1 + std::min(
    std::min(CountOps_v1(s1, s2, l1, l2 - 1), CountOps_v1(s1, s2, l1 - 1, l2)),
    CountOps_v1(s1, s2, l1 - 1, l2 - 1));
}

//Approach #2: Recursive with memoization.
int CountOps_v2(const std::string& s1, const std::string& s2, int l1, int l2, std::vector<std::vector<int>>& memo)
{
  //If strings reaches first characters.
  if (l1 == 0) {
    return l2;
  }
  if (l2 == 0) {
    return l1;
  }

  if (s1[l1 - 1] == s2[l2 - 1]) {
    memo[l1][l2] = CountOps_v1(s1, s2, l1 - 1, l2 - 1);
    return memo[l1][l2];
  }
  //1 + min(insert, remove, replace).
  memo[l1][l2] = 1 + std::min(std::min(CountOps_v1(s1, s2, l1, l2 - 1), CountOps_v1(s1, s2, l1 - 1, l2)),
    CountOps_v1(s1, s2, l1 - 1, l2 - 1));

  return memo[l1][l2];
}

int CountOps(std::string& str1, std::string& str2, int approachType)
{
  int count = -1;
  std::vector<std::vector<int>> memo(str1.size() + 1, std::vector<int>(str2.size() + 1, 0));

  if (approachType == 1) {
    count = CountOps_v1(str1, str2, str1.length(), str2.length());
  } else if (approachType == 2) {
    count = CountOps_v2(str1, str2, str1.length(), str2.length(), memo);
  } else {
    std::cout << "Invalid approach selection!!!";
  }
  return count;
}

void Test_CountOps()
{
  std::cout << "\nTesting operations count to convert strings.\n";
  std::string str1 = "world";
  std::string str2 = "coder";

  int count = CountOps(str1, str2, 1);
  std::cout << "Testcase 1: String " << str1 << " -> " << str2 << " will take " << count << " operations.\n";

  //Approach 2.
  count = CountOps(str1, str2, 2);
  std::cout << "Testcase 1: String " << str1 << " -> " << str2 << " will take " << count << " operations.\n";

}