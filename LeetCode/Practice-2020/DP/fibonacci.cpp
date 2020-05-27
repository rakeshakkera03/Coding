#include <iostream>
#include <string>
#include <vector>
#include <map> 
#include<limits.h> 
#include <stdlib.h>  
using namespace std;

int fib(int n, map<int , int>& dp)
{
  if(dp.find(n) != dp.end())
    return dp[n];

  dp[n] = fib(n - 1, dp) + fib(n - 2, dp);

  return dp[n];
}

int fib_table(int n, map<int , int>& dp)
{
  for(int i = 2; i <= n; i++)
  {
    dp[i] = dp[i-1] + dp[i-2];
  }

  return dp[n];
}

int main() {
  map<int , int> dp;
  int n = 6;
  dp[0] = 1;
  dp[1] = 1;

  std::cout << "memoized: " << fib(n, dp);

  cout << "\n tabulation: " << fib_table(n, dp);
}
