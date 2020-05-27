//https://www.geeksforgeeks.org/painting-fence-algorithm/ ==== Memoization Solution ====
#include <iostream>
#include <string>
#include <vector>
#include <map> 
#include<limits.h> 
using namespace std;

int global_recurssion = 0;
int countWays(int n, int k, map<int, int> dp)
{
    if (n <= 0)
    {
        return 0;
    }
    
    // one pole can be painted in k ways
    if (n == 1)
        return k;
    
    // two poles can be painted in same + diff; Same paint = k, diff paint = k * (k -1)
    if (n == 2)
        return k + k * (k - 1);
    
    dp[n] = (k - 1) * (countWays(n - 1, k, dp) + countWays(n -2, k, dp));   
    
    return dp[n];
}
  
// Driver code 
int main() 
{ 
    int n = 3, k = 2; 
    map<int, int> dp;
    cout << countWays(n, k, dp) << endl; 
    return 0; 
} 

