//https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/ *** Memoized ***
#include <iostream>
#include <string>
#include <vector>
#include <map> 
#include<limits.h> 
#include <stdlib.h>  
using namespace std;

int getOptimalKnapsackWeight(int knapSackWeight, int weights[], int values[], int size, int index, int current_weight, int current_val, map<pair<int, int>, int>& memo)
{
  if (index >= size)
  {
    return current_val;
  }

  if (memo.find(make_pair(current_weight, index)) != memo.end())
    return memo[make_pair(current_weight, index)];

  int totalValueIncludingCurrent = 0; 
  if (current_weight + weights[index] > knapSackWeight)
  {
    totalValueIncludingCurrent = current_val;
  }
  else
  {
    totalValueIncludingCurrent = getOptimalKnapsackWeight(knapSackWeight, weights, values, size, index + 1, current_weight + weights[index], current_val + values[index], memo);
  }

  int totalValueExcludingCurrent = getOptimalKnapsackWeight(knapSackWeight, weights, values, size, index + 1, current_weight, current_val, memo);

  memo[make_pair(current_weight, index)] = max(totalValueIncludingCurrent, totalValueExcludingCurrent);

  return memo[make_pair(current_weight, index)];
}

int knapSack(int knapSackWeight, int weights[], int values[], int size)
{
  map<pair<int, int>, int> memo;
  return getOptimalKnapsackWeight(knapSackWeight, weights, values, size, 0, 0, 0, memo);
}

// Driver code 
int main() 
{ 
    int val[] = { 60, 100, 120 }; 
    int wt[] = { 10, 20, 30 }; 
    int W = 50; 
    int n = sizeof(val) / sizeof(val[0]); 
    cout << knapSack(W, wt, val, n); 
    return 0; 
} 

