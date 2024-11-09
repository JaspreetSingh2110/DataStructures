/*
 * Description:
 * Program to find if both strings becomes equal after n rotations.
 * Approach #1: Using string split and concat. (Not implemented)
 *
 * Approach #2: Modulo operator.
 * TC: O(n)
 *
 * Created on: 10/11/24
 * @author: Jaspreet Singh, mr.jaspreet2110@gmail.com.
 */

#include <iostream>
#include <string>

bool CheckIfEqualAfterRotations(std::string str1, std::string str2, int rCount)
{
  if (str1.size() != str2.size()) {
    return false;
  }

  int sSize = str1.size();
  bool clockwise = true;
  bool counterClockwise = true;

  //Validate clockwise rotations.
  for (int i = 0; i < sSize; i++) {
    if (str1[i] != str2[(i+rCount) % sSize]) {
      clockwise = false;
    }
  }

  //Validate counter-clockwise rotations.
  for (int i = 0; i < sSize; i++) {
    if (str2[i] != str1[(i+rCount) % sSize]) {
      counterClockwise = false;
    }
  }

  return clockwise || counterClockwise;
}

void Test_CheckIfEqualAfterRotations()
{
  std::cout << "\nTest strings are equal after N-rotations.\n";
  std::string str1 = "amazon";
  std::string str2 = "azonam";
  std::string str3 = "onamaz";
  std::string str4 = "zonama";

  std::cout << "*** Testing approach #2\n";
  std::cout << "Testcase #1: Strings '" << str1 << "' and '" << str2 << "' are equal (1:True/0:False): " << CheckIfEqualAfterRotations(str1, str2, 2) << std::endl;
  std::cout << "Testcase #2: Strings '" << str1 << "' and '" << str2 << "' are equal (1:True/0:False): " << CheckIfEqualAfterRotations(str1, str3, 2) << std::endl;
  std::cout << "Testcase #3: Strings '" << str1 << "' and '" << str2 << "' are equal (1:True/0:False): " << CheckIfEqualAfterRotations(str1, str4, 3) << std::endl;
  //Negative cases.
  std::cout << "Testcase #4: Strings '" << str1 << "' and '" << str2 << "' are equal (1:True/0:False): " << CheckIfEqualAfterRotations(str1, str3, 3) << std::endl;
  std::cout << "Testcase #5: Strings '" << str1 << "' and '" << str2 << "' are equal (1:True/0:False): " << CheckIfEqualAfterRotations(str1, str4, 2) << std::endl;
}