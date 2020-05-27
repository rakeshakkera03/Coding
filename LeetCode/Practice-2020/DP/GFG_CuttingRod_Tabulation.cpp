// https://www.geeksforgeeks.org/game-theory-choice-area/ ==== Tabulation Solution ====
#include <iostream>
#include <string>
#include <vector>
#include <map> 
#include<limits.h> 
using namespace std;

void show(vector<bool> const &v) {
    for (auto i: v) {
        cout << i << ' ';
    }
    cout << '\n';
}

/*int max(int a, int b, int c)
{
    return max(a, max(b, c));
}*/

int global_recurssion = 0;
int cutRod(int arr[], int size, map<int, int> dp)
{
    if (size <= 0)
    {
        return 0;
    }
    
    int max_val = INT_MIN;
    
    for (int i = 0; i < size; i++)
    {
        max_val = max(max_val, arr[i] + cutRod(arr, size - i - 1, dp));  
    }
    
    dp[size] = max_val;
    return dp[size];
}
  
/* Driver program to test above functions */
int main() 
{ 
    int arr[] = {1, 5, 8, 9, 10, 17, 17, 20}; 
    int size = sizeof(arr)/sizeof(arr[0]); 
    map<int, int> dp;
    printf("Maximum Obtainable Value is %dn", cutRod(arr, size, dp)); 
    //getchar(); 
    return 0; 
} 

