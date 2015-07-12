/*
Determine whether an integer is a palindrome. Do this without extra space.

Check for overflow as well
*/

class Solution {
public:
    long ReverseInteger(int x)
    {
        int temp;
        // Even if the reversed value is overflows, the value would be stored correctly in 'long'
        long result = 0;
        while( x > 0)
        {
            temp = x % 10;
            x = x / 10;
            result = result * 10 + temp;
        }
        return result;
    }
    bool isPalindrome(int x) {
        
        int sign = 1;
        if(x < 0)
            return false;
        long result = 0;
        
        result = ReverseInteger(x);
        
        if( result > INT_MAX || result < INT_MIN )
            return false;
            
        if( result == x )
            return true;
        else 
            return false;
    }
};
