/*
Given an array of n integers where n > 1, nums, return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Solve it without division and in O(n).

For example, given [1,2,3,4], return [24,12,8,6].
*/

vector<int> productExceptSelf(vector<int>& nums) {
        
        vector<int> prods(nums.size());
        
        if( nums.size() == 0 )
            return prods;
        
        int temp = 1;
        
        for( int i = 0; i < nums.size(); i++ )
        {
            prods[i] = temp;
            temp = temp * nums[i];
        }
        
        temp = 1;
        
        for(int i = nums.size() - 1; i >= 0; i-- )
        {
            prods[i] = prods[i] * temp;
            temp = temp * nums[i];
        }
        
        return prods;
        
    }
