/*
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].

Note:
You must do this in-place without making a copy of the array.
Minimize the total number of operations.
*/

//First Solution

void swap( vector<int>& nums, int i, int j )
    {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    
    void moveZeroes(vector<int>& nums) {
        
        if( nums.size() == 0 || nums.size() == 1 )
            return;
        
        int i = 0;
        
        while( i < nums.size() && nums[ i ] != 0 )
        {
            i++;
        }
        
        int j = i + 1; 
        
        while( j < nums.size() )
        {
            if( nums[ j ] == 0 )
            {
                j++;
                continue;
            }
            else
            {
                swap( nums, i , j );
                
                while( i < nums.size() && nums[ i ] != 0 )
                {
                    i++;
                }
                j = i + 1; 
            }
        }
    }


// Second solution without swapping. O(n) solution
    void moveZeroes(vector<int>& nums) {
        
        if( nums.size() == 0 )
            return;
        
        int replace_pointer = 0; 
        for( int i = 0; i < nums.size(); i++ )
        {
            if( nums[i] != 0 )
            {
                nums[replace_pointer++] = nums[i];
            }
        }
        while( replace_pointer < nums.size() )
        {
            nums[replace_pointer++] = 0;
        }
        
    }


