/*
Given an array of n positive integers and a positive integer s, find the minimal length of a subarray of which the sum ≥ s. If there isn't one, return 0 instead.

For example, given the array [2,3,1,2,4,3] and s = 7,
the subarray [4,3] has the minimal length under the problem constraint.
*/

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        
        if( nums.size() == 0 )
            return 0;
        
        int start = 0, end = 0, min_window_size = -1, curr_sum = nums[start];
        
        while( end < nums.size() )
        {            
            if ( curr_sum >= s)
            {
                if( min_window_size == -1 || min_window_size > end - start + 1 )
                {
                    min_window_size = end - start + 1;
                }
                
                curr_sum = curr_sum - nums[start];
                start++;
                
                if( end < start )
                {
                    end = start;
                    if( end < nums.size() )
                    {
                        curr_sum = curr_sum + nums[ end ];
                    }
                }
            }
            else
            {
               if( end + 1 < nums.size() )
                {
                    end++;
                    curr_sum = curr_sum + nums[end];
                }
                else
                    break;
            }                         
        }
        
        return (min_window_size == -1)? 0:min_window_size;
        
    }
};
