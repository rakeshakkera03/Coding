/*
Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 10,1,2,7,6,1,5 and target 8, 
A solution set is: 
[1, 7] 
[1, 2, 5] 
[2, 6] 
[1, 1, 6] 
*/

class Solution {
public:
    // Backtracking question 
    
    void printTemp( vector<int> &temp )
    {
        for( int i = 0; i < temp.size(); i++ )
        {
            cout << temp[i] << " ";
        }
        
        cout << endl;
    }
    
    void FindCombinationSum( vector<int> &candidates, int level, int target, int curr_sum, bool used[], vector<int> &temp, vector<vector<int> >&result)
    {
        if( curr_sum == target )
        {
            result.push_back(temp);
            return;
        }
        
        // At each level you are adding the "next" index (passing in 'i + 1' in recursive call) 
        // as long as the sum is less than the target. 
        // That way you are getting the combinations with the same number.
        // Used[] makes sure that there are not duplicate result sets. Example: input: [1, 1], 1; Output: [[1]]; Not [[1], [1]]
        
        for( int i = level; i < candidates.size(); i++ )
        {
            if( (curr_sum + candidates[i] > target) || ( i > 0 && candidates[i - 1] == candidates[i] && used[i-1] == false ) )
                continue;
                
            temp.push_back( candidates[i] );
            curr_sum = curr_sum + candidates[i];
            used[i] = true;
            printTemp( temp );
            
            FindCombinationSum(candidates, i + 1, target, curr_sum, used, temp, result );
            
            used[i] = false;
            curr_sum = curr_sum - candidates[i];
            temp.pop_back();
        }
        
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        int level = 0, curr_sum = 0; 
        vector<vector<int> > result;
        result.clear();
        
        vector<int> temp;
        temp.clear();
        
        if( target == 0 || candidates.size() == 0 )
            return result;
        
        bool used[candidates.size()];
        memset( used, false, sizeof(bool) * candidates.size() );
            
        sort( candidates.begin(), candidates.end() );
        
        printTemp ( candidates );
        
        FindCombinationSum( candidates, level, target, curr_sum, used, temp, result );
        
        return result;
    }
};
