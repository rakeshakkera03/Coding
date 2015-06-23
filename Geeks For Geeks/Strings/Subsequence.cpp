/*
Given two strings, find if first string is a subsequence of second
Given two strings str1 and str2, find if str1 is a subsequence of str2. A subsequence is a sequence that can be derived from another sequence by deleting some elements without changing the order of the remaining elements (source: wiki). Expected time complexity is linear.

Examples:

Input: str1 = "AXY", str2 = "ADXCPY"
Output: True (str1 is a subsequence of str2)
*/

#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int isSubSequence(string str1, string str2, int m, int n)
{
	if( m < 0 )
		return 1;

	if( n < 0 )
		return 0;
	
	if( str1[ m ] == str2[ n ] )
	{
		return isSubSequence(str1, str2, m -1, n -1 );
	}
	else
		return isSubSequence(str1, str2, m, n - 1);
		

}

int main()
{
	string str1 = "gksrek";
	string str2 = "geeksforgeeks";
	int j = 0, i = 0;

	if( str1.empty() || str2.empty() )
		return -1;
	while( j < str2.length() && i < str1.length() )
	{
		if(str1[i] == str2[j])
		{
			i++;
			j++;
		}
		else
			j++;
	}
	if( i == str1.length() )
	{
		cout << "Is a subsequence" << endl;
	}

	int ret = isSubSequence(str1, str2, str1.length() - 1, str2.length() -1 );

	if( ret )
		cout << "Recursive: is subsequence" << endl;
	else
		cout << "Recursive: is NOT subsequence" << endl;

	return 0;
}
