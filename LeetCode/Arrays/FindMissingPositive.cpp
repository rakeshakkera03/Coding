/*
Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space.
*/

void print( vector<int> nums )
    {
        for( int i = 0; i < nums.size(); i++ )
        {
            cout << nums[i] << " ";
        }
        cout << endl;
    }
    int firstMissingPositive(vector<int>& nums) {
        
        if( nums.size() == 0 )
            return 1;
        if( nums.size() == 1 )
        {
            if( nums[0] == 1 )
                return 2;
            else 
                return 1;
        }        
            
        int i = 0, j = nums.size() - 1;
        while( i <= j )    // modify array to negative followed by positive; here <"=" is necessary; ex: i=0,j=2, [-2,-6,2]
        {
            if ( nums[i] <= 0 )
            {
                i++;
            }
            else if ( nums[j] > 0 )
            {
                j--;
            }
            else
            {
                int x = nums[i];
                nums[i] = nums[j];
                nums[j] = x;
                i++; j--;
            }
        }
        
        j = 0;
        while( j < i )  // make all array elements positive
        {
            nums[j] = abs(nums[j]);
            j++;
        }

        while( i < nums.size() ) // setting index elements negative
        {
            if( (abs(nums[i]) - 1) >= nums.size() || nums[abs(nums[i]) - 1] < 0)
            {
                i++;
            }
            else if( nums[abs(nums[i]) - 1] == 0)
            {
                nums[abs(nums[i]) - 1] = INT_MIN;
                i++;
            }
            else 
            {
                nums[abs(nums[i]) - 1] *= -1;
                i++;
            }
        }
        
        for( int i = 0; i < nums.size(); i++ )
        {
            if( nums[i] >= 0 )
            {
                return i + 1;
            }
        }
        
        return nums.size() + 1;
        
    }
