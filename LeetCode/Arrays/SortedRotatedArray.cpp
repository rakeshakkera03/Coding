/*
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int size = nums.size();
        int low = 0, high = size - 1;
        if( size == 0)
            return -1;
        
        return se(nums, target, low, high);
    }
    
    int se(vector<int>& nums, int target, int low, int high)
    {
        if( low > high)
        {
                return -1;
        }
        int mid = (low + high)/2;
        
        if( nums[mid] == target)
            return mid;
        
        if( nums[mid] >= nums[low])     // Here ">=" is important. If you just put ">" it is going to fail for input [3, 1] and 1.
        {
            if( target < nums[mid] && target >= nums[low])
            {
                return se(nums, target, low, mid - 1);
            }
            else
                return se(nums, target, mid + 1, high);
        }
        else
        {
            if( target > nums[mid] && target <= nums[high])
            {
                return se(nums, target, mid + 1, high);
            }
            else
                return se(nums, target, low, mid - 1);
        }
    }
};
