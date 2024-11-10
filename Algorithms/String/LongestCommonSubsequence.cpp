/*
 * Description:
 * Program to find length of longest common subsequence.
 *
 * Approach #1: Using recursion.
 * TC: O(2^min(l1,l2)) -> every step of recursion there are two possible flows So, 2^x.
 *
 * Approach #2: Recursion with memoization.
 * TC: O(m*n) because of memoization table in place, max calculations will be m*n.
 *
 * Approach #3: Using Dynamic programming.
 * TC: O(m*n)
 *
 * Created on: 10/11/24
 * @author: Jaspreet Singh, mr.jaspreet2110@gmail.com.
 */

#include <iostream>
#include <string>

//Approach 1: Using recursion and process all possible sub sequences.
int LongestCommonSubSequence_v1(std::string str1, std::string str2, int l1 = 0, int l2 = 0)
{
  //If any of the string reaches end, return.
  if (l1 >= str1.size() || l2 >= str2.size()) {
    return 0;
  }

  if (str1[l1] == str2[l2]) {
    return 1 + LongestCommonSubSequence_v1(str1, str2, l1 + 1, l2 + 1);
  }
  return std::max(LongestCommonSubSequence_v1(str1, str2, l1 + 1, l2), LongestCommonSubSequence_v1(str1, str2, l1, l2 + 1));
}

//Approach 2: Using recursion with memoization.
int LongestCommonSubSequence_v2(std::string str1, std::string str2, std::vector<std::vector<int>> &m, int l1 = 0, int l2 = 0)
{
  //If any of the string reaches end, return.
  if (l1 == str1.size() || l2 == str2.size()) {
    return 0;
  }

  if (m[l1][l2] != -1) {
    return m[l1][l2];
  }

  if (str1[l1] == str2[l2]) {
    m[l1][l2] = 1 + LongestCommonSubSequence_v2(str1, str2, m, l1 + 1, l2 + 1);
    return m[l1][l2];
  }
  m[l1][l2] = std::max(LongestCommonSubSequence_v2(str1, str2, m, l1 + 1, l2), LongestCommonSubSequence_v2(str1, str2, m, l1, l2 + 1));
  return m[l1][l2];
}


//Approach #3: Dynamic programming.
int LongestCommonSubSequence_v3(std::string str1, std::string str2, std::vector<std::vector<int>> &dp)
{
  //Clear the dp array.
  for (int i = 0; i <= str1.size(); i++) {
    for (int j = 0; j <= str2.size(); j++) {
      dp[i][j] = 0;
    }
  }

  //Build dp table.
  for (int i = 1; i <= str1.size(); i++) {
    for (int j = 1; j <= str2.size(); j++) {
      if (str1[i - 1] == str2[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + 1; //Diagonal left value  + 1.
      }
      else {
        dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]); //Max of left and top value.
      }
    }
  }
  return dp[str1.size()][str2.size()];
}

void Test_LongestCommonSubSequence()
{
  std::cout << "\nTest longest common subsequence.\n";
  std::string str1 = "ABC";
  std::string str2 = "ACD";
  std::string str3 = "CBA";
  std::string str4 = "AGGTAB";
  std::string str5 = "GXTXAYB";
  std::string str6 = "ABSDHS";
  std::string str7 = "ABDHSP";
  std::string str8 = "longest";
  std::string str9 = "stone";

  std::cout << "*** Testing approach #1\n";
  std::cout << "Testcase #1: Longest common subsequence for strings '" << str1 << "' and '" << str2 << "' is: " << LongestCommonSubSequence_v1(str1, str2) << std::endl;
  std::cout << "Testcase #2: Longest common subsequence for strings '" << str1 << "' and '" << str3 << "' is: " << LongestCommonSubSequence_v1(str1, str3) << std::endl;
  std::cout << "Testcase #3: Longest common subsequence for strings '" << str4 << "' and '" << str5 << "' is: " << LongestCommonSubSequence_v1(str4, str5) << std::endl;
  std::cout << "Testcase #4: Longest common subsequence for strings '" << str6 << "' and '" << str7 << "' is: " << LongestCommonSubSequence_v1(str6, str7) << std::endl;
  std::cout << "Testcase #5: Longest common subsequence for strings '" << str8 << "' and '" << str9 << "' is: " << LongestCommonSubSequence_v1(str8, str9) << std::endl;

  std::cout << "*** Testing approach #2\n";
  //Create a extra memory for memoization approach.
  //NOTE for approach 2, size + 1 is not required, only size would work. But, creating common array so can be used in DP approach.
  std::vector<std::vector<int>> m1(str1.size() + 1, std::vector<int>(str2.size() + 1, -1));
  std::vector<std::vector<int>> m2(str1.size() + 1, std::vector<int>(str3.size() + 1, -1));
  std::vector<std::vector<int>> m3(str4.size() + 1, std::vector<int>(str5.size() + 1, -1));
  std::vector<std::vector<int>> m4(str6.size() + 1, std::vector<int>(str7.size() + 1, -1));
  std::vector<std::vector<int>> m5(str8.size() + 1, std::vector<int>(str9.size() + 1, -1));
  std::cout << "Testcase #1: Longest common subsequence for strings '" << str1 << "' and '" << str2 << "' is: " << LongestCommonSubSequence_v2(str1, str2, m1) << std::endl;
  std::cout << "Testcase #2: Longest common subsequence for strings '" << str1 << "' and '" << str3 << "' is: " << LongestCommonSubSequence_v2(str1, str3, m2) << std::endl;
  std::cout << "Testcase #3: Longest common subsequence for strings '" << str4 << "' and '" << str5 << "' is: " << LongestCommonSubSequence_v2(str4, str5, m3) << std::endl;
  std::cout << "Testcase #4: Longest common subsequence for strings '" << str6 << "' and '" << str7 << "' is: " << LongestCommonSubSequence_v2(str6, str7, m4) << std::endl;
  std::cout << "Testcase #5: Longest common subsequence for strings '" << str8 << "' and '" << str9 << "' is: " << LongestCommonSubSequence_v2(str8, str9, m5) << std::endl;

  //Sample memoization table.
  for (int i = 0; i < str6.size(); i++) {
    for (int j = 0; j < str7.size(); j++) {
      std::cout << m4[i][j] << "\t";
    }
    std::cout << std::endl;
  }

  std::cout << "*** Testing approach #3\n";
  std::cout << "Testcase #1: Longest common subsequence for strings '" << str1 << "' and '" << str2 << "' is: " << LongestCommonSubSequence_v3(str1, str2, m1) << std::endl;
  std::cout << "Testcase #2: Longest common subsequence for strings '" << str1 << "' and '" << str3 << "' is: " << LongestCommonSubSequence_v3(str1, str3, m2) << std::endl;
  std::cout << "Testcase #3: Longest common subsequence for strings '" << str4 << "' and '" << str5 << "' is: " << LongestCommonSubSequence_v3(str4, str5, m3) << std::endl;
  std::cout << "Testcase #4: Longest common subsequence for strings '" << str6 << "' and '" << str7 << "' is: " << LongestCommonSubSequence_v3(str6, str7, m4) << std::endl;
  std::cout << "Testcase #5: Longest common subsequence for strings '" << str8 << "' and '" << str9 << "' is: " << LongestCommonSubSequence_v3(str8, str9, m5) << std::endl;
}