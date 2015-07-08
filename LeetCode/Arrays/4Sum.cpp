/*
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.
*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        vector<vector<int> > result;
        vector<int> temp;
        if( nums.size() < 4)
            return result;
            
        sort(nums.begin(), nums.end());
        
        for( int i = 0; i < nums.size() - 3; i++ )
        {
            if( i > 0 && nums[i] == nums[i - 1] )
                continue;
            for( int j = i+1; j < nums.size() - 2; j++ )
            {
                if(j > i + 1 && nums[j] == nums[j - 1] )
                continue;
                int k = j + 1, l = nums.size() - 1;
                while( k < l)
                {
                    int sum = nums[i] + nums[j] + nums[k] + nums[l];
                    if( sum == target)
                    {
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[k]);
                        temp.push_back(nums[l]);
                        result.push_back(temp);
                        temp.clear();
                        k++; l--;
                        while(k<l && nums[k] == nums[k-1]) k++;
                        while(k<l && nums[l] == nums[l+1]) l--;
                    }
                    else if (sum > target)
                        l--;
                    else
                        k++;
                }
            }
        }
        
        return result;
        
    }
};
