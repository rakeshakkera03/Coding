#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

    string removeSpaces( string s )
    {
        string r;
        int i = 0;
        while( i < s.length() )
        {
            if((s[i] >= '0' && s[i] <= '9') || s[i] == '-' || s[i] == '+')
            {
                r += s[i];
            }
            i++;
        }

        return r;
    }
    int myAtoi(string str) {
        
        string r = removeSpaces(str);
        int result = 0;
        reverse(r.begin(), r.end());
        
        while( !r.empty() )
        {
            string::iterator it = r.end() - 1;
            if( *it == '+' || *it == '-')
	    {
                r.pop_back();
		continue;
	    }
            result = result * 10 + (*it - '0');
            r.pop_back();
        }
        
	cout << result << endl;
        return result;
        
    }


int main()
{
	string s = "-abc";
	myAtoi(s);
	return 0;
}
