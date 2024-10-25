/*
 * Description:
 * Program to find max number of platforms needed as per given trains arrival and departure charts.
 *
 * Brute force approach.
 * TC: O(n^2), SC: O(1)
 *
 * Created on: 25/10/24
 * @author: Jaspreet Singh, mr.jaspreet2110@gmail.com.
 */

#include <iostream>
#include <vector>

int FindMaxPlatforms(std::vector<double> &arrivals, std::vector<double> &departure)
{
  int platformCount = 1;
  int result = 1;
  // For each arrival and departure at given index, check if any other trains overlaps.
  // If it overlaps, increment the platform count.
  for (int i = 0; i < arrivals.size(); i++) {
    platformCount = 1;
    for (int j = 0; j < departure.size(); j++) {
      //Skip index i. (as it will definitely overlap.)
      if (i != j) {
        //If any other trains timings falls b/w timings of train i. we would need additional platform.
        //To check overlap, while there is train j on platform, does train i overlap.
        //i.i. train i is coming to platform while j is on platform.
        if ((arrivals[i] >= arrivals[j]) && (arrivals[i] <= departure[j])) {
          platformCount++;
        }
      }
    }
    result = std::max(result, platformCount);
  }

  return result;
}


void Test_FindMaxPlatforms()
{
  std::cout << "\nTest Max platforms\n";
  std::vector<double> arrivals = {9, 9.40, 9.50, 11., 15, 18};
  std::vector<double> departures = {9.10, 12, 11.20, 11.30, 19, 20};
  int platformCount = FindMaxPlatforms(arrivals, departures);
  std::cout << "TC #1: Numbers of platforms needed to support this timings chart is: " << platformCount << std::endl;


  arrivals = {100, 300, 500};
  departures = {900, 400, 600};
  platformCount = FindMaxPlatforms(arrivals, departures);
  std::cout << "TC #2: Numbers of platforms needed to support this timings chart is: " << platformCount << std::endl;
}