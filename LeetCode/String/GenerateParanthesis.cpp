#include<iostream>
#include<string>
#include<vector>

using namespace std;

    void generate(vector<string>&r, string &s, int n, int open, int close, int len )
    {
        if( open > n || close > n || close > open )
        {
                return;
        }
        if( len == 2*n )
        {
	    cout << s << endl;
            r.push_back(s);
        }
        
        s.push_back('(');
        generate(r, s, n, open + 1, close, len + 1);
        s.pop_back();
        
        s.push_back(')');
        generate(r, s, n, open, close + 1, len + 1);
        s.pop_back();
    }

    vector<string> generateParenthesis(int n) {
        
        vector<string> r;    
        string s;
        generate( r, s, n , 0, 0, 0 );
        
    	return r;
    }

int main()
{
	int n  = 3;
	
	generateParenthesis(n);
		
	return 0;
}
