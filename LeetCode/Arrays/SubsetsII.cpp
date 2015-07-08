/*
Given a collection of integers that might contain duplicates, nums, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If nums = [1,2,2], a solution is:

[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
*/

class Solution {
public:

    void PrintSubsets(vector<int>& nums, vector<vector<int> >&result, vector<int> temp, int level, bool flags[])
    {
        if( level == nums.size() )
        {
            return;
        }
        
        for( int i = level ; i < nums.size(); i++ )
        {
            //Aditya's idea. If the previous value is same as current and if it is not used, then 
            // the same combinations would have been formed by the previous value itself. Hence skip.
            if(i > 0 && nums[i] == nums[i-1] && flags[i-1] == false)
                continue;
            temp.push_back(nums[i]);
            flags[i] = true;
            result.push_back(temp);
            PrintSubsets(nums, result, temp, i+1, flags);
            temp.pop_back();
            flags[i] = false;
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        bool flags[nums.size()];

	// This is how you memset
        memset(flags, false , sizeof(bool) * nums.size());

        vector<vector<int> > result;
        vector<int> temp;
        result.push_back(temp);
        int level = 0; 
        PrintSubsets(nums, result, temp, level, flags);
        return result;
        
    }
};
