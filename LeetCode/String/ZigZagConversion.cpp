class Solution {
public:
    string convert(string s, int numRows) {
        
        vector<string> v(numRows);
        string result;
        
        if( s.empty() || numRows == 1)
        {
            return s;
        }
        int i = 0, j = 0;
        int flag = 0;
        while( i < s.length() )
        {
            if( flag == 0 && j <= numRows - 1 )
            {
                v[j] = v[j] + s[i];
                if( j == numRows - 1)
                {
                    flag = 1;
                    j--;
                }
                else
                {
                    j++;
                }
            }
            else if( flag == 1 && j >= 0)
            {
                v[j] = v[j] + s[i];
                if( j == 0 )
                {
                    flag = 0;
                    j++;
                }
                else
                {
                    j--;
                }
            }
            i++;
        }
        for( int i = 0 ; i < numRows; i++)
        {
            result = result + v[i];
        }
        
        return result;
    }
};
