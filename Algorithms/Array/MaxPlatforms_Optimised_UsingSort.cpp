/*
* Description:
 * Program to find max number of platforms needed as per given trains arrival and departure charts.
 *
 * Optimised approach using sorting.
 * TC: O(n), SC: O(1)
 *
 * Created on: 25/10/24
 * @author: Jaspreet Singh, mr.jaspreet2110@gmail.com.
 */

#include <iostream>
#include <vector>
#include <algorithm>

int FindMaxPlatforms_Optimised_UsingSort(std::vector<double> &arrivals, std::vector<double> &departure)
{
  //Sort the arrays.
  std::sort(arrivals.begin(), arrivals.end());
  std::sort(departure.begin(), departure.end());

  int platformCnt = 0;
  int max = 0;

  //Basic idea is to process events in terms of their timings.
  //Increment the platform count on arrival and decrement it on departure.
  //While train 1 is arrived and 2nd train arrives before 1's departure, increment platform count.
  //At end, count shall fall back to 0.
  //Get the max platform count that reached.
  int ar = 0;
  int dp = 0;
  while (ar < arrivals.size() && dp < departure.size()) {
    if (arrivals[ar] < departure[dp]) {
      platformCnt++;
      ar++;
    } else {
      platformCnt--;
      dp++;
    }
    max = std::max(platformCnt, max);
  }
  return max;
}


void Test_FindMaxPlatforms_Optimised_UsingSort()
{
  std::cout << "\nTest Max platforms (optimised using sorting)\n";
  std::vector<double> arrivals = {9, 9.40, 9.50, 11, 15, 18};
  std::vector<double> departures = {9.10, 12, 11.20, 11.30, 19, 20};
  int platformCount = FindMaxPlatforms_Optimised_UsingSort(arrivals, departures);
  std::cout << "TC #1: Numbers of platforms needed to support this timings chart is: " << platformCount << std::endl;


  arrivals = {100, 300, 500};
  departures = {900, 400, 600};
  platformCount = FindMaxPlatforms_Optimised_UsingSort(arrivals, departures);
  std::cout << "TC #2: Numbers of platforms needed to support this timings chart is: " << platformCount << std::endl;
}