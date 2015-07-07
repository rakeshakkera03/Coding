/*
Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        
        while(i < nums.size() )
        {
            if( i+1 < nums.size() && nums[i+1] == nums[i] )
            {
                nums.erase(nums.begin() + i + 1);   
            }
            else
                i++;
        }
        
        return nums.size();
    }
};
