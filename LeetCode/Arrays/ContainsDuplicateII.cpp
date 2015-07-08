/*
Given an array of integers and an integer k, find out whether there there are two distinct indices i and j in the array such that nums[i] = nums[j] and the difference between i and j is at most k.
*/

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
        map<int, int> m;
        
        for( int i = 0; i < nums.size(); i++ )
        {
            if( m.find(nums[i]) == m.end() )
            {
                m[nums[i]] = i;
            }
            else
            {
                if( i - m[nums[i]] <= k)
                {
                    return true;
                }
                else
                {
                    m[nums[i]] = i;
                }
            }
        }
        
        return false;
    }
};
