/*
Find the contiguous subarray within an array (containing at least one number) which has the largest product.

For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6.
*/

int maxProduct(vector<int>& nums) {
        
        if( nums.size() == 0 )
            return 0;
            
        int res = nums[0];
        int maxp = nums[0];
        int minp = nums[0];
        
        for( int i = 1; i < nums.size(); i++ )
        {
            int temp_max = maxp;
            int temp_min = minp;
            
            maxp = max( max( temp_max * nums[i], temp_min * nums[i] ), nums[i] );
            minp = min( min( temp_max * nums[i], temp_min * nums[i] ), nums[i] );
            
            if( maxp > res )
                res = maxp;
        }
        
        return res;
        
    }
