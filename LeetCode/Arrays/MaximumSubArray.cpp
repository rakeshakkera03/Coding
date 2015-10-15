/*
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
the contiguous subarray [4,−1,2,1] has the largest sum = 6.
*/

// Solution 1:

int maxSubArraySum(int a[], int size)
{
   int max_so_far = a[0];
   int curr_max = a[0];
 
   for (int i = 1; i < size; i++)
   {
        curr_max = max(a[i], curr_max+a[i]);
        max_so_far = max(max_so_far, curr_max);
   }
   return max_so_far;
}


//Solution 2:

int FindMaxCrossing( vector<int>& nums, int low, int mid, int high )
    {
        int curr_sum = 0;
        int left_sum = INT_MIN;  // Here setting this to INT_MIN is necessary; if set to 0, for input [-2,-1], output is 0
        int right_sum = INT_MIN; // but the expected output is '-1'
        
        for( int i = mid; i >= low; i-- )
        {
            curr_sum = curr_sum + nums[i];
            if( curr_sum > left_sum )
            {
                left_sum = curr_sum;
            }
        }
        curr_sum = 0;
        
        for( int i = mid + 1; i <= high; i++ )
        {
            curr_sum = curr_sum + nums[i];
            if( curr_sum > right_sum )
            {
                right_sum = curr_sum;
            }
        }
        
        return (left_sum + right_sum);
        
    }
    int FindMaxSubArray( vector<int>& nums, int low, int high )
    {
        if( low == high )
        {
            return nums[low];
        }
        
        int mid = (low + high)/2;
        
        int left = FindMaxSubArray( nums, low, mid );
        int right = FindMaxSubArray( nums, mid + 1, high );
        int crossing = FindMaxCrossing( nums, low, mid, high );
        
        cout << left << " " << right << " " << crossing << endl;
        
        return (left > right)?(left > crossing? left : crossing) : (right > crossing? right : crossing);
        
    }
    int maxSubArray(vector<int>& nums) {
        
        if( nums.size() == 0 )
        {
            return 0;
        }
        
        return FindMaxSubArray( nums, 0, nums.size() - 1 );
        
    }
