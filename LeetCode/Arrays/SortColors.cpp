/*
Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int i = 0, j = nums.size() - 1, k = 0;
        
        if( nums.size() == 0 || nums.size() == 1)
        {
                return;
        }
        
        // The idea is to have two pointers, one for 0's from start (i) and other for 2's from end (j).
        // When the value is '0' at the kth index, swap it with the value at i, if '2' with j;
        while( nums[i] == 0)
        {
            i++;
        }
        while( nums[j] == 2)
        {
            j--;
        }
 
        for(int k = i; k <= j; )
        {
            if( nums[k] == 0 && k != i)
            {
                swap(nums, i, k);
                i++;
                continue;
            }
            if( nums[k] == 2 && k != j)
            {
                swap(nums, j, k);
                j--;
                continue;
            }
            k++;
        }
    }
    
    void swap( vector<int>&nums, int x, int y)
    {
        int temp;
        
        temp = nums[x];
        nums[x] = nums[y];
        nums[y] = temp;
    }
    
};
