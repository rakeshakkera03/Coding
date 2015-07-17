/*
Given a list of non negative integers, arrange them such that they form the largest number.

For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.

Note: The result may be very large, so you need to return a string instead of an integer.
*/

class Solution {
public:
    static int myCompare( string X, string Y )
    {
        string XY = X + Y;
        string YX = Y + X;
        
        return XY.compare(YX) > 0 ? 1 : 0;
    }
    
    string largestNumber(vector<int>& nums) {
        
        vector<string> s(nums.size());
        string result;
        
        for( int i = 0 ; i < nums.size(); i++ )
        {
            s[i] = to_string(nums[i]);
        }
        
        sort( s.begin(), s.end(), myCompare);
        
        for( int i = 0; i < s.size(); i++ )
            result = result + s[i];
          
        // This block of code is if the input is [0,0], the output you would get is "00", but the 
        // actual result should be just "0"
        int res = atoi(result.c_str());
        if ( res == 0 )
            return "0";
        
        
        cout << result << endl;
        return result;
            
        
    }
};
