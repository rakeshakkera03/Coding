/*
Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
*/


class Solution {
public:
    int expandAroundCenter( string &s, int left, int right )
    {
        int l = left, r = right;
        while( l >= 0 && r < s.size() && s[l] == s[r] )
        {
            l--;
            r++;
        }
        
        // understand why u are returning below.. because l and r point to indices after the palindrome and thus break
        return r - l - 1;
    }
    string longestPalindrome(string s) {
        
        if( s.size() == 0 )
            return NULL;
        
        int start = 0, end = 0;
        
        for( int i = 0; i < s.size(); i++ )
        {
            int len1 = expandAroundCenter( s, i, i );
            int len2 = expandAroundCenter( s, i, i + 1 );
            
            int len = max( len1, len2 );
            
            if( len > (end - start) )
            {
                start = i - (len - 1)/2;
                end = i + len/2;
            }
         }
         
         return s.substr(start, end - start + 1);
        
    }
};
