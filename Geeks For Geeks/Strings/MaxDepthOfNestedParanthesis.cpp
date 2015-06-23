/*
Find maximum depth of nested parenthesis in a string
We are given a string having parenthesis like below
     “( ((X)) (((Y))) )”
We need to find the maximum depth of balanced parenthesis, like 4 in above example. Since ‘Y’ is surrounded by 4 balanced parenthesis.

If parenthesis are unbalanced then return -1.
*/

#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main()
{
	string s = "(b) ((c) ()";

	int open_count = 0, close_count = 0, max_depth = 0; 

	for(int i = 0; i < s.length(); i++ )
	{
		if(s[i] == '(' )
		{
			open_count++;
		}
		else if(s[i] == ')' )
		{
			close_count++;
		}

		if( close_count > open_count )
		{
			cout << " paranthesis are unbalanced " << endl;
			return -1;
		}
		if( (open_count - close_count) > max_depth )
		{
			max_depth = open_count - close_count;
		}

	}

	if( open_count != close_count )
	{
		cout << " paranthesis are unbalanced " << endl;
		return -1;
	}
	else
	{
		cout << "Max depth is : " << max_depth << endl;
	}

	return 0;
}
