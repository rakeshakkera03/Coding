/*
Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

For example,
Given nums = [0, 1, 3] return 2.
*/

void print ( vector<int> nums )
    {
        for(int i = 0; i< nums.size(); i++ )
        {
            cout << nums[i] << " ";
        }
        cout << endl;
    }
    int missingNumber(vector<int>& nums) {
        
        if( nums.size() == 0 )
            return 0;
        
        int i = 0;
        while( i < nums.size() )
        {
            if( nums[i]== INT_MIN )
            {
                nums[0] = nums[0] * - 1;
            }
            else if( abs(nums[i]) >= nums.size() )
            {

            }
            else if( nums[abs(nums[i])] == 0 )
            {
                nums[abs(nums[i])] = INT_MIN;
            }
            else
            {
                nums[abs(nums[i])] = nums[abs(nums[i])] * - 1;
            }
            i++;
            
        }
        
        print(nums);
        
        i = 0;
        while( i < nums.size() )
        {
            if( nums[i] >= 0 )
            {
                return i;
            }
            i++;
        }
        return i;
    }
