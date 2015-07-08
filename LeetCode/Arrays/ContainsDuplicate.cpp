/*
Given an array of integers, find if the array contains any duplicates. Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.
*/

class Solution {
public:

    bool containsDuplicate(vector<int>& nums) {
        
        map<int, bool> m;
        
        if( nums.size() == 0 )
        {
            return false;
        }
        
        for(int i = 0 ;i < nums.size(); i++)
        {
            if(m.find(nums[i]) == m.end() )
            {
                m[nums[i]] = true;
            }
            else
            {
                return true;
            }
            
        }
        
        return false;
        
    }
        
/*    bool containsDuplicate(vector<int>& nums) {
        
        if( nums.size() == 0 )
            return false;
        sort(nums.begin(), nums.end());
        
        for(int i = 0 ; i < nums.size(); i++ )
        {
            if( i+1 < nums.size() && nums[i] == nums[i+1])
            {
                return true;
            }
        }
        
        return false;
        
    }*/
};
