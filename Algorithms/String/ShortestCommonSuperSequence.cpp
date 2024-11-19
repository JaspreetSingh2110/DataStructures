/*
 * Description:
 *
 * Created on: 18/11/24
 * @author: Jaspreet Singh, mr.jaspreet2110@gmail.com.
 */

#include <string>
#include <iostream>

//Approach #1: Recursion.
int SCSSHelper(const std::string& s1, const std::string& s2, int l1, int l2)
{
  //If any of string completes, hte additional characters required to form
  // super sequence will be remaining length of other string.
  if (l1 == 0) {
    return l2;
  }
  if (l2 == 0) {
    return l1;
  }

  //If both characters match, include them in super sequence.
  //Hence, we have to do +1 in this case as well.
  if (s1[l1 - 1] == s2[l2 - 1]) {
    return 1 + SCSSHelper(s1, s2, l1 - 1, l2 - 1);
  }
  return 1 + std::min(SCSSHelper(s1, s2, l1 - 1, l2), SCSSHelper(s2, s1, l1, l2 - 1));
}

/******************************************************************************/
//Approach 2: Using LCS. >>> SCSS length = l1 + l2 - length(LCS).
//LCS helper function
int LCSHelper(const std::string& s1, const std::string& s2, int l1, int l2)
{
  if ((l1 == 0) || (l2 == 0)) {
    return 0;
  }

  if (s1[l1 - 1] == s2[l2 - 1]) {
    return 1 + LCSHelper(s1, s2, l1 - 1, l2 - 1);
  }
  return std::max(LCSHelper(s1, s2, l1 - 1, l2),LCSHelper(s1, s2, l1, l2 - 1));
}


int ShortestCommonSuperSequence_v1(const std::string& s1, const std::string& s2)
{
  return SCSSHelper(s1, s2, s1.length(), s2.length());
}

int ShortestCommonSuperSequence_v2(const std::string& s1, const std::string& s2)
{
  return s1.length() + s2.length() - LCSHelper(s1, s2, s1.length(), s2.length());
}


void Test_ShortestCommonSuperSequence()
{
  std::cout << "\nTest Shortest common supersequence.\n";
  std::string str1 = "AGGTAB";
  std::string str2 = "GXTXAYB";

  int len = ShortestCommonSuperSequence_v1(str1, str2);
  std::cout << "Testcase 1 (approach 1): Length of Shortest common supersequence is: " << len << std::endl;

  len = ShortestCommonSuperSequence_v2(str1, str2);
  std::cout << "Testcase 1 (approach 2): Length of Shortest common supersequence is: " << len << std::endl;
}

