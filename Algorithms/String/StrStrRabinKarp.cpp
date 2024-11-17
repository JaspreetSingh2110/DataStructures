/*
 * Description:
 * Program to implement strstr using Rabin Karp's Algorithm.
 *
 * Time Complexity: O(l1+l2)
 * Worst case: O(l1xl2)
 *
 * Created on: 18/11/24
 * @author: Jaspreet Singh, mr.jaspreet2110@gmail.com.
 */

#include <iostream>
#include <string>
#include <vector>

#define constant 19  //Random multiplier.

//Approach 1: Simple hash function.
std::vector<int> StrStrRabinKarp(std::string& ms, std::string& ss)
{
  std::vector<int> result;
  int hashSS = 0;
  int hashMS = 0;

  //Calculate hash for pattern and main string till length of ss.
  for (int i = 0; i < ss.size(); i++) {
    hashSS += (ss[i]*constant - 'a');
    hashMS += (ms[i]*constant - 'a');
  }

  //Iterate over main string and process string match.
  for (int i = 0; i <= ms.size() - ss.size(); i++) {
    //If hash value matches.
    if (hashMS == hashSS) {
      //Check if strings match.
      int j = 0;
      for (; j < ss.size(); j++) {
        if (ss[j] != ms[i + j]) {
          break;
        }
      }
      //If string match was successful, update result vector.
      if (j == ss.size()) {
        result.push_back(i);
      }
    }
    //If hash value mis matches.
    else {
      //Update hash value for next set.
      //Exclude ith index character contribution and include next character.
      hashMS = hashMS - (ms[i]*constant - 'a') + (ms[i + ss.size()]*constant - 'a');
    }
  }

  return result;
}

void Test_StrStrRabinKarp()
{
  std::cout << "\nTesting StrStr using Rabin Karps's algorithm\n" << std::endl;
  std::string txt = "aabaacaadaabaaba";
  std::vector<std::string> patterns = {"aaba", "aabaab"};

  for (int i = 0; i < patterns.size(); i++) {
    std::vector<int> res = StrStrRabinKarp(txt, patterns[i]);
    std::cout << "Testcase "<< i+1 << ": Pattern found at index(es): ";
    for (int re : res) {
      std::cout << re << "\t";
    }
    std::cout << std::endl;
  }
}
