/*
Given an array and a value, remove all instances of that value in place and return the new length.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.
*/

class Solution {
public:
    /*int removeElement(vector<int>& nums, int val) {
        int i = 0;
        while(i < nums.size())
        {
            if( nums[i] == val )
            {
                nums.erase(nums.begin() + i);
            }
            else
                i++;
        }
        
        return nums.size();
    } */
    
    int removeElement(vector<int>& nums, int val) {
        int insert_pos = 0, i = 0;
        
        if( nums.size() == 0 )
            return 0;
        
        while( i < nums.size() )
        {
            if( nums[i] != val )
            {
                nums[insert_pos] = nums[i];
                insert_pos++;
                i++;
            }
            else
            {
                i++;
            }
        }
        
        return insert_pos;
           
    }
};
