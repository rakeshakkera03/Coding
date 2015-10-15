/*
Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.

Ensure that numbers within the set are sorted in ascending order.


Example 1:

Input: k = 3, n = 7

Output:

[[1,2,4]]
*/

void FindCombinationSum( int k, int n, int level, int count, int curr_sum, vector<int> &temp, vector<vector<int> >&result )
    {
        if( curr_sum == n && count == k )
        {
            result.push_back(temp);
            return;
        }
        
        if( count > k )
            return;
            
        for( int i = level; i <= 9 ; i++ )
        {
            if( curr_sum + i > n )
                return;
            
            temp.push_back(i);
            curr_sum = curr_sum + i;
            
            FindCombinationSum( k, n, i + 1, count + 1, curr_sum, temp, result );
            
            temp.pop_back();
            curr_sum = curr_sum - i;
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        
        int level = 1, curr_sum = 0, count = 0;
        vector<vector<int> > result;
        result.clear();
        vector<int> temp;
        temp.clear();
        
        if( k == 0 || n == 0 )
            return result;
        
        FindCombinationSum( k, n, level, count, curr_sum, temp, result );
        
        return result;
        
    }
