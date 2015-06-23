/*
Count Possible Decodings of a given Digit Sequence
Let 1 represent ‘A’, 2 represents ‘B’, etc. Given a digit sequence, count the number of possible decodings of the given digit sequence.

Examples:

Input:  digits[] = "121"
Output: 3
// The possible decodings are "ABA", "AU", "LA"

Input: digits[] = "1234"
Output: 3
// The possible decodings are "ABCD", "LCD", "AWD"
*/

#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<cstdlib>

using namespace std;


void PrintDecodings(char* digits, int level, int end, string s)
{
	if(level > end)
	{
		cout << s << endl;
		return;
	}

	int x = digits[level] - '0';
	
	s.push_back('A' + x - 1);
	PrintDecodings(digits, level+1, end, s);

	s.pop_back();

	if( level + 1 <= end )
	{
		x = (digits[level] - '0') * 10 + (digits[level+1] - '0');

		if( x <= 26 )
		{
			s.push_back('A' + x - 1);
			PrintDecodings(digits, level + 2, end, s);
			s.pop_back();
			s.pop_back();
		}
	}

	return;

}

int main()
{

	char digits[] = "1234";

	int n = strlen(digits);
	string s;
	PrintDecodings(digits, 0, n -1, s);

	return 0;
}
	

