/*
Given an array of strings, find if the strings can be chained to form a circle
Given an array of strings, find if the given strings can be chained to form a circle. A string X can be put before another string Y in circle if the last character of X is same as first character of Y.

Examples:

Input: arr[] = {"geek", "king"}
Output: Yes, the given strings can be chained.
Note that the last character of first string is same
as first character of second string and vice versa is
also true.
*/

#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;


int CheckIfChained( vector<string>&v, vector<string>&r, int used[], int level, int prev )
{
	int ret;
	if( level == v.size() )
	{
		return 1;
	}

	for( int i = 0; i < v.size(); i++ )
	{
		if(used[i] == 1)
			continue;
		
		if( level == 0 )
		{
			used[i] = 1;
			r.push_back(v[i]);
			ret = CheckIfChained(v, r, used, level + 1, i);
		}
		else
		{
			if( v[prev].at(v[prev].length() - 1) == v[i].at(0) )
			{
				used[i] = 1;
				r.push_back(v[i]);
				ret = CheckIfChained(v, r, used, level + 1, i);
			}
			else
				continue;
		}
		
		if( ret == 1 )
			return ret;
		r.pop_back();
		used[i] = 0;
	}

	return 0;
	
}

int main()
{
	vector<string> v;
	vector<string> r;

	v.push_back("aaa");
	v.push_back("bbb");
	//v.push_back("for");
	//v.push_back("geek");
	//v.push_back("rig");
	//v.push_back("kaf");

	int used[v.size()];
	memset(used, 0, sizeof(int) * v.size());
	int ret =  CheckIfChained(v, r, used, 0, -1);

	if( ret )
	{
		cout << "Chanied" << endl;
	}
	else
		cout << "Not Chanied" << endl;

	for(int i = 0; i < r.size(); i++)
	{
		cout << r[i] << endl;
	}
	return 0;
}
