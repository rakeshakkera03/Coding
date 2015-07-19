/*
Print all interleavings of given two strings
*/

#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;


void PrintInterleavings(string &s1, int first, string &s2, int second, string &r)
{
	if( r.length() == s1.length() + s2.length() )
	{
		cout << r << endl;
	}

	if( first < s1.length() )
	{	
		r.push_back(s1[first]);
		PrintInterleavings(s1, first+1, s2, second, r);
		r.pop_back();
	}
	if( second < s2.length())
	{
		r.push_back(s2[second]);
		PrintInterleavings(s1 ,first, s2, second + 1, r);
		r.pop_back();
	}

}

int main()
{
	string s1 = "ab";
	string s2 = "cd";
	string r;
	PrintInterleavings( s1, 0, s2, 0, r );
	return 0;
}
