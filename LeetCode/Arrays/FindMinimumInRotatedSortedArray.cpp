/*
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

You may assume no duplicate exists in the array.
*/

int findMinimum( vector<int>&nums, int low , int high )
    {
        if( low > high ) // this condition is never reached;
            return INT_MAX; 
        
        int mid = (low + high)/2;
        
        if( (mid - 1) >= 0 && nums[mid] < nums[mid - 1] ) // base condition; min element in the middle
        {
            return nums[mid];
        }
        else if( mid == low && (mid + 1) <= high ) // 2-element case
        {
            if( nums[mid + 1] < nums[mid] )
                return nums[mid + 1];
            else 
                return nums[mid];
        }
        else if( mid == high ) // One element case and completely decreasing sequence case
        {
            return nums[mid];
        }
        else if ( nums[mid] > nums[low] ) 
        {
            if( nums[high] > nums[mid]) // Completely increasing sequence case; both return values below are correct
            {
                //return findMinimum( nums, low, mid - 1 );
                return nums[low];
            }
            else 
            {
                return findMinimum( nums, mid + 1, high );
            }
        }
        else 
        {
            if( nums[high] < nums[mid] ) // Completely decreasing sequence case; both return values below are correct
            {
                //return findMinimum( nums, mid + 1, high );
                return nums[high];
            }
            else 
            {
                return findMinimum( nums, low, mid - 1 );
            }
        }
        
    }
    
    int findMin(vector<int>& nums) {
        
        if( nums.size() == 0 )
            return 0;
        else if ( nums.size() == 1 )
            return nums[0];
        
        return findMinimum( nums, 0, nums.size() - 1 );
        
        
    }
