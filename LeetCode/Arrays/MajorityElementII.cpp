/*
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times. The algorithm should run in linear time and in O(1) space.
*/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        int count1 = 0, count2 = 0, candidate1 = 0, candidate2 = 0;
        vector<int> result;

        
        for(int i = 0; i < nums.size(); i++ )
        {
            if( nums[i] == candidate1 )
            {
                count1++;
            }
            else if ( nums[i] == candidate2 )
            {
                count2++;
            }
            else if( count1 == 0 )
            {
                candidate1 = nums[i];
                count1 = 1;
            }
            else if( count2 == 0 )
            {
                candidate2 = nums[i];
                count2 = 1;
            }
            else 
            {
                count1--;
                count2--;
            }
        }
        
        if( count1 > 0 )
        {
            count1 = 0;
            for(int i = 0; i < nums.size(); i++ )
            {
                if( nums[i] == candidate1 )
                {
                    count1++;
                }
            }
            if( count1 > nums.size()/3 )
            {
                result.push_back(candidate1);
            }
        }
        if( count2 > 0 )
        {
            count2 = 0;
            for(int i = 0; i < nums.size(); i++ )
            {
                if( nums[i] == candidate2 )
                {
                    count2++;
                }
             if( count2 > nums.size()/3 )
            {
                result.push_back(candidate2);
            }
        }
        
        return result;
    }
};
