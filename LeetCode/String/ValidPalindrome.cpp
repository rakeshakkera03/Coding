class Solution {
public:

    string Convert( string s )
    {
        string r;
        int i = 0;
        while( i < s.length() )
        {
            if( s[i] >= 'A' && s[i] <= 'Z')
            {
                r +=  'a' + (s[i] - 'A');
            }
            else
                r += s[i];
            i++;
        }
        return r;
    }
    bool isPalindrome(string s) {
        
        string S = Convert(s);
        int i = 0, j = S.length() - 1;
        
        while( i <= j )
        {
            if( !((S[i] >= 'a' && S[i] <= 'z') || (S[i] >= '0' && S[i] <= '9')) )
            {
                i++;
                
            }
            else if( !((S[j] >= 'a' && S[j] <= 'z') || (S[j] >= '0' && S[j] <= '9')) )
            {
                j--;
            }
            else
            {
                if( S[i] != S[j])
                {
                    return false;
                }
                    i++;
                    j--;
            }
        }
        
        return true;
        
        
    }
};
