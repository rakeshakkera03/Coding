class Solution {
public:
    int lengthOfLastWord(string s) {
        
        int start = 0, end = 0;
        int length = 0;
        int flag = 0;
        if( s.empty() )
            return 0;
        
        while( s[start] == ' ')
        {
            start++;
            end++;
        }
        
        while( end < s.length() )
        {
            if( flag == 0) {
                while( end < s.length() && s[end] != ' ')
                {
                    end++;
                    length++;
                }
                flag = 1;
            }
            
            if( flag == 1 )
            {
                while( end < s.length() && s[end] == ' ')
                {
                    end++;
                }
                if( end < s.length() )
                {
                    start = end;
                    length = 0;
                    flag = 0;
                }
            }
        }
        
        return length;
        
    }
};
