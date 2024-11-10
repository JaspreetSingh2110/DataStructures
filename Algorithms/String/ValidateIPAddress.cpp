/*
 * Description:
 *
 * Created on: 10/11/24
 * @author: Jaspreet Singh, mr.jaspreet2110@gmail.com.
 */

#include <iostream>
#include <sstream>
#include <vector>
#include <string>

bool IsValidateIPAddress(std::string ipAddress)
{
  //Min length is 7. i.e. 4 digits with 3 dots.
  if (ipAddress.length() < 7) {
    return false;
  }

  //1st way: using string stream.
  //2nd way: using find then substr (not implemented).
  std::stringstream ss(ipAddress);
  std::vector<std::string> tokens;
  while (ss.good()) {
    std::string token;
    std::getline(ss, token, '.'); //Use delimiter in as character, not string.
    tokens.push_back(token);
  }

  //Validate only 4 token are created. neither less nor more.
  if (tokens.size() != 4) {
    return false;
  }

  for (std::string token : tokens) {
    //Empty token i.e. continuous dots.
    if (token.size() == 0) {
      return false;
    }

    //Validate each character in token.
    for (auto c : token) {
      //Check if any character is non digit.
      if (!std::isdigit(c)) {
        return false;
      }
    }

    //Convert to integer value.
    int val = std::stoi(token);

    //Check if value is 0, token length should be 1. i.e. "00 is invalid"
    if ((val == 0) && (token.size() != 1)) {
      return false;
    }

    //Check valid range.
    if (val < 0 || val > 255) {
      return false;
    }
  }
  return true;
}


void Test_ValidateIPAddress()
{
  std::cout << "\nTest validation of IP address.\n";
  std::vector<std::string> str = {
    "192.178.64.23", "1.3.4.0", "10.10.00.34", "258.45.123.4", "8.4.5", "5.5..7"
  };

  for (auto s : str) {
    bool res = IsValidateIPAddress(s);
    if (res == true) {
      std::cout << "IP address [" << s << "] is valid.\n";
    } else {
      std::cout << "IP address [" << s << "] is not valid.\n";
    }
  }
}