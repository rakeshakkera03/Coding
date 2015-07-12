/*
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[1,1,2], [1,2,1], and [2,1,1].
*/

class Solution {
public:
    void Permute(vector<int>& nums, vector<vector<int> > & result, vector<int> &temp, bool used[], int level)
    {
        if( level == nums.size() )
        {
            result.push_back(temp);
            return;
        }
        
        for( int i = 0; i < nums.size(); i++ )
        {
            if( used[i] == true || (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false))
                continue;
            
            used[i] = true;
            temp.push_back( nums[i] );
            
            Permute(nums, result, temp, used, level + 1);
            
            temp.pop_back();
            used[i] = false;
            
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        vector<vector<int> > result;
        vector<int> temp;
        bool used[nums.size()];
        memset(used, false, nums.size());
        
        if( nums.size() == 0 )
            return result;
        
        sort(nums.begin(), nums.end());
        
        Permute(nums, result, temp, used, 0);
        
        return result;
        
    }
};
