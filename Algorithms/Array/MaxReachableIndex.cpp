/*
 * Description:
 * Program to find the max reachable index from index 0 by avoiding ith index (invalid).
 *
 * Created on: 30/11/24
 * @author: Jaspreet Singh, mr.jaspreet2110@gmail.com.
 */

#include <iostream>

int FindMaxReachableIndex(int steps, int iIndex)
{
  //Start step is index 0.
  int currentStep = 0;

  //Run the loop for required nos of steps.
  for (int i = 1; i <= steps; i++) {
    //Get the next step to jump at.
    int nextStep = currentStep + i;

    //If next step is a valid index, jump to it. Else skip it.
    if (nextStep != iIndex) {
      currentStep = nextStep;
    }
  }

  return currentStep;
}


void Test_FindMaxReachableIndex()
{
  std::cout << "\nTesting find max reachable index\n";

  std::cout << "Testcase 1: (approach 1) Max reachable index: " << FindMaxReachableIndex(3, 2) << std::endl;
}