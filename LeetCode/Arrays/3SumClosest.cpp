/*
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.
*/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) 
    {
        sort( nums.begin(), nums.end() );
        
        unsigned int three = nums.size() - 1;
        unsigned int one = 0;
        unsigned int two = three - 1;
        
        int returnSum = nums[ one ] + nums[ two ] + nums[ three ];
        
        for( three = nums.size() - 1; three >= 2; three-- )
        {
            one = 0;
            two = three - 1;
            
            while( one < two )
            {
                int tempSum = nums[ one ] + nums[ two ] + nums[ three ];
                
                if( tempSum == target )
                {
                    return target;
                }
                
                if( abs( target - returnSum) > abs( target - tempSum ) )
                {
                    returnSum = tempSum;
                }
                
                if( tempSum > target )
                {
                    two--;
                }
                else
                {
                    one++;
                }
            }
        }
        
        return returnSum;
    }
};
