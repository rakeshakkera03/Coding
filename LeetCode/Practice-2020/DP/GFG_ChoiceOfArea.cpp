// https://www.geeksforgeeks.org/game-theory-choice-area/ ==== Memoized Solution ====
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

void show(vector<bool> const &v) {
    for (auto i: v) {
        cout << i << ' ';
    }
    cout << '\n';
}


//  structure to represent an area 
struct area 
{ 
    //  increment or decrement in A and B 
    int a, b; 
    area(int a, int b) : a(a), b(b) 
    {} 
}; 

int max(int a, int b, int c)
{
    return max(a, max(b, c));
}

int calculateMaxSurvivalTime(int A, int B, struct area X, struct area Y, struct area Z, int last, map< pair<int, int>, int >& dp)
{
    if (A <= 0 || B <=0)
    {
        return 0;
    }
    
    pair<int, int> p = make_pair(A, B);
    
    if (dp.find(p) != dp.end())
    {
        return dp[p];
    }
    
    int maxSumInIndividualPath;
    
    switch (last)
    {
        case 1: maxSumInIndividualPath = 1 + max(calculateMaxSurvivalTime(A + Y.a, B + Y.b, X, Y, Z, 2, dp), calculateMaxSurvivalTime(A + Z.a, B + Z.b, X, Y, Z, 3, dp));
                break;
        
        case 2: maxSumInIndividualPath =  1 + max(calculateMaxSurvivalTime(A + X.a, B + X.b, X, Y, Z, 1, dp), calculateMaxSurvivalTime(A + Z.a, B + Z.b, X, Y, Z, 3, dp));
                break;
        
        case 3: maxSumInIndividualPath =  1 + max(calculateMaxSurvivalTime(A + X.a, B + X.b, X, Y, Z, 1, dp), calculateMaxSurvivalTime(A + Y.a, B + Y.b, X, Y, Z, 2, dp));
                break;
    }
    
    dp[p] = maxSumInIndividualPath;
    
    return dp[p];
}

int getMaxSurvivalTime(int A, int B, struct area X, struct area Y, struct area Z)
{
    map< pair<int, int>, int > dp;
    return max(calculateMaxSurvivalTime(A + X.a, B + X.b, X, Y, Z, 1, dp),
               calculateMaxSurvivalTime(A + Y.a, B + Y.b, X, Y, Z, 2, dp),
               calculateMaxSurvivalTime(A + Z.a, B + Z.b, X, Y, Z, 3, dp));
    
}
  
//  Driver code to test above method 
int main() 
{ 
    area X(3, 2); 
    area Y(-5, -10); 
    area Z(-20, 5); 
  
    int A = 20; 
    int B = 8; 
    cout << getMaxSurvivalTime(A, B, X, Y, Z); 
  
    return 0; 
}

