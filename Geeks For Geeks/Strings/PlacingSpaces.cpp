/*ill possible strings that can be made by placing spaces
Given a string you need to print all possible strings that can be made by placing spaces (zero or one) in between them.

Input:  str[] = "ABC"
Output: ABC
        AB C
        A BC
        A B C
*/

#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

void PrintSpaces(string &s, string &r, int level)
{
	if( s.empty() )
		return;

	if( level == s.length() )
	{
		cout << r << endl;
		return;
	}
		
		r.push_back(s[level]);
		PrintSpaces(s, r, level + 1);
		r.pop_back();

		if( level != s.length() - 1 )
		{
			r.push_back(s[level]);
			r.push_back(' ');

			PrintSpaces(s, r, level + 1);
			r.pop_back();
			r.pop_back();
		
		}
}

int main()
{

	string s = "ABC";
	string r;
	
	PrintSpaces(s, r, 0);
	return 0;
} 
