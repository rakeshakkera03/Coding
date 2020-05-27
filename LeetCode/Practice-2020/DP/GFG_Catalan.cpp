//https://www.geeksforgeeks.org/program-nth-catalan-number/
#include <iostream>
#include <string>
#include <vector>
#include <map> 
#include<limits.h> 
#include <stdlib.h>  
using namespace std;

int cataline_memoized(unsigned int n, map<int , int>& dp)
{
  if (dp.find(n) != dp.end())
    return dp[n];

  unsigned long int result = 0;
  for (int i = 0; i < n; i++)
  {
    result += cataline_memoized(i, dp) * cataline_memoized(n - i - 1, dp);
  }

  dp[n] = result;

  return result;
}

int cataline_tabulation(unsigned int n, map<int , int>& dp)
{
  dp[0] = 1;
  dp[1] = 1;

  for (int i = 2; i <= n; i++)
  {
    unsigned long int result = 0;
    
    for(int j = 0; j < i; j++)
    {
      result += dp[j] * dp[i - j - 1];
    }

    dp[i] = result;
  }

  return dp[n];
}

int main() {
  map<int , int> dp;
  int n = 9;
  dp[0] = 1;
  dp[1] = 1;

  std::cout << "memoized: " << cataline_memoized(n, dp);

  cout << "\ntabulation: " << cataline_tabulation(n, dp);
}
