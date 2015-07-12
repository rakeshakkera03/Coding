/*
Given an integer, write a function to determine if it is a power of two.
*/

class Solution {
public:
    bool isPowerOfTwo(int n) {
        
        cout << n << " " << n - 1 << " " << (n & (n-1)) << endl;
        
        if ( n > 0 && (n & (n-1)) == 0)
            return true;
        else 
            return false;
        
    }
};
