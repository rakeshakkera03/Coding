/*
Given an integer n, return the number of trailing zeroes in n!.
*/

class Solution {
public:
/*
    int trailingZeroes(int n) {
        
        int count = 0;
        
        for(int i = 5; n/i > 0; i = i*5 )
        {
            count = count + n/i;
        }
        
        return count;
    }
*/
    int trailingZeroes(int n)
    {
       return n/5+n/25+n/125+n/625+n/3125+n/15625+n/78125+n/390625+n/1953125+n/9765625+n/48828125+n/244140625+n/1220703125;
    }    
};
