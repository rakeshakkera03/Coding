// https://www.geeksforgeeks.org/subset-sum-problem-dp-25/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Memoized solution
bool isSubsetSum(int set[], int n, int sum, vector<vector<int>>& dp)
{   
    if ( sum < 0 )
        return false;
        
    if (sum == 0)
        return true;
    
    if (n <= 0)
        return false;
    
    if (dp[n][sum] == 0)
        return false;
    else if (dp[n][sum] == 1)
        return true;
    
    if (set[n-1] > sum)
        dp[n][sum] = isSubsetSum(set, n - 1, sum, dp) == true? 1 : 0;
    
    dp[n][sum] = (isSubsetSum(set, n - 1, sum - set[n - 1], dp) || isSubsetSum(set, n - 1, sum, dp)) == true ? 1 : 0;
    
    return dp[n][sum] == 1 ? true: false;
}

int main()
{
  int set[] = {3, 34, 4, 12, 5, 2}; 
  int sum = 7; 
  int n = sizeof(set)/sizeof(set[0]); 

  vector<vector<int>> dp (n + 1, vector<int>(sum + 1, -1));
  for (int i = 0; i < n + 1; i++)
    for(int j = 0; j < sum + 1; j++)
        dp[i][j] = -1;
        
  if (isSubsetSum(set, n, sum, dp) == true) 
     printf("Found a subset with given sum"); 
  else
     printf("No subset with given sum"); 
  return 0; 

}

