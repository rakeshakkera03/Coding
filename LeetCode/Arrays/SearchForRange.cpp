/*
Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).
*/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> v;
        v.push_back(-1);
        v.push_back(-1);
        if( nums.size() == 0)
            return v;
        v.clear();
        
        int low = 0, high = nums.size() - 1;
        int first = firstOccurance( nums, target, low, high);
        int last =  lastOccurance( nums, target, low, high);
        v.push_back(first);
        v.push_back(last);
        return v;
    }
    
    int firstOccurance(vector<int>&nums, int target, int low, int high)
    {
        if(low > high)
            return -1;
        int mid = (low + high)/2;
        
        
        if( nums[mid] == target )
        {
            if( low == high )
                return mid;
                
            if( mid > 0 && nums[mid - 1] == target)
                return (firstOccurance(nums, target, low, mid - 1));
            else 
                return mid;
        }
        if( target < nums[mid])
        {
            return (firstOccurance(nums, target, low, mid - 1));
        }
        else
            return (firstOccurance(nums, target, mid + 1, high));
        
    }
    int lastOccurance(vector<int>&nums, int target, int low, int high)
    {
        if(low > high)
            return -1;
        int mid = (low + high)/2;
        
        
        if( nums[mid] == target )
        {
            if( low == high )
                return mid;
                
            if( ( mid < nums.size() - 1) && nums[mid + 1] == target)
                return (lastOccurance(nums, target, mid + 1, high));
            else 
                return mid;
        }
        if( target < nums[mid])
        {
            return (lastOccurance(nums, target, low, mid - 1));
        }
        else
            return (lastOccurance(nums, target, mid + 1, high));
        
    }
};
