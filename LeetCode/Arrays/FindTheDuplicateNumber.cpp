/*
Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.

Note:
You must not modify the array (assume the array is read only).
You must use only constant, O(1) extra space.
Your runtime complexity should be less than O(n2).
There is only one duplicate number in the array, but it could be repeated more than once.
*/

/* Sorting Solution

    int findDuplicate(vector<int>& nums) {
        
        if( nums.size() == 0 )
            return -1;
            
        sort( nums.begin(), nums.end() );
        
        int i = 0;
        while( (i + 1) <= (nums.size() - 1) )
        {
            if( nums[i] == nums[i + 1] )
            {
                return nums[ i ];
            }
            
            i++;
        }
        
        return -1; 
        
    }
*/    

// Index based solution;
    int findDuplicate(vector<int>& nums) {
     
        if ( nums.size() == 0 || nums.size() == 1 )
            return -1;
        
        for( int i = 0; i < nums.size(); i++ )
        {
            if( nums[ abs(nums[i]) ] < 0 )
            {
                return abs(nums[i]);
            }
            else
            {
                nums[ abs(nums[i]) ] = - nums[ abs(nums[i]) ];
            }
        }
        
        return -1;
    
    }
