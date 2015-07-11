/*
Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?
*/

class Solution {
public:
    bool SearchRotatedArray(vector<int>& nums, int target, int low, int high)
    {
        if( low > high )
            return false;
        
        int mid = (low + high)/2;
        
        if( nums[mid] == target)
            return true;
        
        // This is the only extra condition when duplicates are present.. Think about this input 
        // 0 2 2 2 2 -> 2 0 2 2 2 -> 2 2 2 0 2 to understand
        if( nums[low] == nums[mid] && nums[mid]== nums[high] )
        {
            return (SearchRotatedArray(nums, target, low, mid - 1) || SearchRotatedArray(nums, target, mid + 1, high));
        }
        else if( nums[mid] >= nums[low])
        {
            cout << nums[low] << " " << nums[mid] <<  " " << nums[high] << endl;
            if( nums[low] <= target && target < nums[mid] )
            {
                return SearchRotatedArray(nums, target, low, mid - 1); 
            }
            else 
            {
                return SearchRotatedArray(nums, target, mid + 1, high);
            }
        }
        else if( nums[mid] < nums[low] )
        {
            if( nums[mid] < target && target <= nums[high] )
            {
                return SearchRotatedArray(nums, target, mid + 1, high);
            }
            else
            {
                return SearchRotatedArray(nums, target, low, mid - 1); 
            }
        }
    }
    
    bool search(vector<int>& nums, int target) {
        
        if( nums.size() == 0)
            return false;
        
        return SearchRotatedArray(nums, target, 0, nums.size() - 1);
        
    }
};
