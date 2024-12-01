/*
 * Description:
 * Program to convert ascii to integer
 *
 * Created on: 30/11/24
 * @author: Jaspreet Singh, mr.jaspreet2110@gmail.com.
 */

#include <iostream>
#include <string>
#include <vector>

int AsciiToInt(std::string& str)
{
  unsigned int result = 0;
  int i = 0;
  int n = str.size();
  int sign = 1;

  //Remove leading spaces.
  while ((i < n) && (str[i] == ' ')) {
    i++;
  }

  //Check the sign.
  if (str[i] == '-') {
    sign = -1;
    i++;
  }
  else if (str[i] == '+') {
    sign = 1;
    i++;
  }

  while (i < n) {
    if (str[i] >= '0' && str[i] <= '9') {
      //Check for overflow condition.
      if (result > INT_MAX/10) {
        return (sign == 1) ? INT_MAX : INT_MIN;
      }
      result = (result*10) + (str[i] - '0');
    }
    else {
      return 0;
    }
    i++;
  }

  return result * sign;
}

void Test_AsciiToInt()
{
  std::cout << "\nTest ascii to int\n";
  std::vector<std::string> strs = {"  1234567", "-2423223", "12fdsdw", " -0", "234234234234234234234234"};

  for (int i = 0; i < strs.size(); ++i) {
    std::cout << "Testcase: " << i + 1 << ", int value for string: " << strs[i] << " is " << AsciiToInt(strs[i]) << std::endl;
  }
}
