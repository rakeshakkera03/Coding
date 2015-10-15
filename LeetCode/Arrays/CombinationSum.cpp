/*
Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 2,3,6,7 and target 7, 
A solution set is: 
[7] 
[2, 2, 3] 
*/

    // Backtracking question 

void FindCombinationSum( vector<int> &candidates, int level, int target, int curr_sum, vector<int> &temp, vector<vector<int> >&result)
    {
        if( curr_sum == target )
        {
            result.push_back(temp);
            return;
        }
        
        // At each level you are adding the same index (passing in 'i' in recursive call) 
        // as long as the sum is less than the target. 
        // That way you are getting the combinations with the same number.
        
        for( int i = level; i < candidates.size(); i++ )
        {
            if( (curr_sum + candidates[i]) > target )
                continue;
                
            temp.push_back( candidates[i] );
            curr_sum = curr_sum + candidates[i];
            
            FindCombinationSum(candidates, i, target, curr_sum, temp, result );
            
            curr_sum = curr_sum - candidates[i];
            temp.pop_back();
        }
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        int level = 0, curr_sum = 0; 
        vector<vector<int> > result;
        result.clear();
        
        vector<int> temp;
        temp.clear();
        
        if( target == 0 || candidates.size() == 0 )
            return result;
            
        sort( candidates.begin(), candidates.end() );
        
        FindCombinationSum( candidates, level, target, curr_sum, temp, result );
        
        return result;
    }
