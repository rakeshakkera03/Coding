// https://www.geeksforgeeks.org/cutting-a-rod-dp-13/ ==== Memoized Solution ====
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

int max(int a, int b, int c)
{
    return max(a, max(b, c));
}

int global_recurssion = 0;
int cuttingRodLength(int input_array[], int size, int curr_sum, int curr_length, int target_length, map<int, int>& dp)
{
    cout << "input_array[size - 1]: " << input_array[size-1] << ", size: " << size  << ", curr_sum: " << curr_sum << ", curr_length: " << curr_length << ", target_length: " << target_length << "\n";
    //getchar(); 
    global_recurssion++;
    
    if ( size <= 0 )
        return 0;
    
    if ( curr_length > target_length )
        return 0;
      
    if (dp.find(curr_length) != dp.end())
    {
        cout << "gr: " << global_recurssion << "curr_length: " << curr_length << ", dp[curr_length]: " << dp[curr_length] << "\n";
        return dp[curr_length];
    }
    
    if ( curr_length == target_length )
        return curr_sum;
    
    int includingCurrent = cuttingRodLength(input_array, size, curr_sum + input_array[size - 1], curr_length + size, target_length, dp);
    int excludingCurrent = cuttingRodLength(input_array, size - 1, curr_sum, curr_length, target_length, dp);
    
    dp[curr_length] = max(excludingCurrent, includingCurrent);
                
    return dp[curr_length];
}
  
/* Driver program to test above functions */
int main() 
{ 
    int input_array[] = {1, 5, 8, 9, 10, 17, 17, 20}; 
    int size = sizeof(input_array)/sizeof(input_array[0]); 
    map<int, int> dp;
    printf("Maximum Obtainable Value is %d\n", cuttingRodLength(input_array, size, 0, 0, size, dp)); 
    cout << "global_recurssion: " << global_recurssion  << "\n";
    //getchar(); 
    return 0; 
} 

