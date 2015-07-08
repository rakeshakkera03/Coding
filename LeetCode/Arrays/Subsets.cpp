/*
Given a set of distinct integers, nums, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If nums = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/

class Solution {
public:
    
    void PrintSubsets(vector<int>& nums, vector<vector<int> >&result, vector<int> temp, int level)
    {
        if( level == nums.size() )
        {
            return;
        }
        
        for( int i = level ; i < nums.size(); i++ )
        {
            temp.push_back(nums[i]);
	    
	    // need to push back here rather than in the terminating condition since we want to push back
	    // as and when the subsets are created.
            result.push_back(temp);
            PrintSubsets(nums, result, temp, i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        vector<vector<int> > result;
        vector<int> temp;
        
	// empty set is a subset of every set.. Hence the following line 
	result.push_back(temp);

        int level = 0; 
        PrintSubsets(nums, result, temp, level);
        return result;
        
    }
};
