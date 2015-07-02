class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        int i = 0;
        if( s.empty() )
        {
                return true;
        }
        
        while( i < s.length() )
        {
            if( s[i] == '(' || s[i] == '{' || s[i] == '[' )
            {
                stk.push(s[i]);
            }
            else if( s[i] == ')' )
            {
                // Here checking for stk.empty() is important. Otherwise you will pop an empty stack - seg fault
                if( stk.empty() || stk.top() != '(' )
                {
                    return false;
                }
                else 
                {
                    stk.pop();
                }
            }
            else if( s[i] == '}' )
            {
                if( stk.empty() || stk.top() != '{' )
                {
                    return false;
                }
                else 
                {
                    stk.pop();
                }
            }
            else if( s[i] == ']' )
            {
                if( stk.empty() || stk.top() != '[' )
                {
                    return false;
                }
                else 
                {
                    stk.pop();
                }
            }
            i++;
        }
        
        if( !stk.empty() )
        {
            return false;
        }
        
        return true;
        
        
    }
};
