/*
Implement a basic calculator to evaluate a simple expression string.

The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .

You may assume that the given expression is always valid.
*/

class Solution {
public:
    void Calculate(int &curr_sum, int &n, char operation)
    {
        if( operation == '+')
        {
            curr_sum += n;
        }
        else if( operation == '-')
        {
            curr_sum -= n;
        }
        else
        {
            cout << "Wrong Operator" << endl;
        }
    }
    int calculate(string s) {
        
        int i = 0; 
        int curr_sum = 0, n, prev_sum = 0;
        char operation = '+';
        string num;
        stack<int> int_stack;
        stack<char> op_stack;
        
        while( i < s.size() )
        {
            if( s[i] == ' ')
            {
                while( s[i] == ' ')
                {
                    i++;
                }
            }
            else if( s[i] >= '0' && s[i] <= '9' )
            {
                while ( s[i] >= '0' && s[i] <= '9' )
                {
                    num += s[i++];
                }
                n = atoi(num.c_str());
                Calculate( curr_sum, n, operation);
                num.clear();
            }
            else if( s[i] == '+' || s[i] == '-')
            {
                operation = s[i++];
            }
            else if ( s[i] == '(' )
            {
                int_stack.push(curr_sum);
                op_stack.push(operation);
                curr_sum = 0;
                operation = '+';
                i++;
            }
            else if ( s[i] == ')')
            {
                prev_sum = int_stack.top();
                int_stack.pop();
                operation = op_stack.top();
                op_stack.pop();
                Calculate( prev_sum, curr_sum, operation);
                curr_sum = prev_sum;
                i++;
            }
            
            
        }
        
        return curr_sum;
        
    }
};
