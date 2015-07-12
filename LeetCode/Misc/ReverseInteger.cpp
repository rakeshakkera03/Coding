/*
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321
Did you notice that the reversed integer might overflow? Assume the input is a 32-bit integer, then the reverse of 1000000003 overflows. How should you handle such cases?

For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
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
    int reverse(int x) {
        
        int sign = 1;
        long result = 0;
        
        if( x < 0 )
            sign = -1;
            
        // here abs() is necessary.. otherwise the function returns 0 for negative numbers..
        result = ReverseInteger(abs(x));
        
        if( result > INT_MAX || result < INT_MIN )
            return 0;
        else
            return (sign * result);
            
        
        
    }
};
