/*

****** Look at GEEKSFORGEEKS for better explanation of question  *******

A peak element is an element that is greater than its neighbors.

Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.

The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that num[-1] = num[n] = -∞.

For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.
*/

class Solution {
public:
    
    int findPeak(vector<int>&nums, int low, int high )
    {
        if( low > high)
        {
            // this condition is never reached
            return -1;
        }
        
        int mid = (low + high)/2;
        
        if( mid == 0 )
            return mid;
        else if ( mid == nums.size() - 1)
            return nums.size() - 1;
        else if ( nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1] )
        {
            return mid;
        }
        else if ( nums[mid] > nums[mid - 1] )
        {
            return findPeak(nums, mid + 1, high);
        }
        else 
        {
            // here we do from low to mid .. not to mid - 1 .. otherwise it fails for input [3, 4, 3, 2, 1];
            return findPeak(nums, low, mid );
        }
    }
    
    int findPeakElement(vector<int>& nums) {
        
        if( nums.size() == 0 )
            return -1;
        else if ( nums.size() == 1 )
            return 0;
        else if ( nums.size() == 2 )
            return nums[0] > nums[1]? 0 : 1;
            
        return findPeak(nums, 0, nums.size() - 1);
    }
};
