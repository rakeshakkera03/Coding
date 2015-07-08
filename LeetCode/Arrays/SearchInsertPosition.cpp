/*
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0
*/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        int size = nums.size();
        
        if( size == 0)
        {
            return 0;
        }
        int low = 0, high = size - 1;
        return search(nums, target, low, high);
        
    }
    
    int search( vector<int>&nums, int target, int low, int high)
    {
        if( low > high)
        {
            return low;
        }
        
        int mid = (low + high)/2;
        
        if( nums[mid] == target)
            return mid;
            
        if( nums[mid] > target)
        {
            return search(nums, target, low, mid - 1);
        }
        else
            return search( nums, target, mid + 1, high);
    }
};
