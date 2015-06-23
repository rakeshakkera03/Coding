/*
Find Excel column name from a given column number
MS Excel columns has a pattern like A, B, C, … ,Z, AA, AB, AC,…. ,AZ, BA, BB, … ZZ, AAA, AAB ….. etc. In other words, column 1 is named as “A”, column 2 as “B”, column 27 as “AA”.

Given a column number, find its corresponding Excel column name. Following are more examples.

Input          Output
 26             Z
 51             AY
 52             AZ
 80             CB
 676            YZ
 702            ZZ
 705            AAC
*/

#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;


void PrintColumn(int a )
{
	string s;
	while( a )
	{
		int x = a % 26;
		
		if( x == 0)
		{
			s.push_back('Z');
		}
		else 
		{
			s.push_back('A' + x -1 );
		}

		a = a/26;
	}
	
	for(string::reverse_iterator rit = s.rbegin(); rit != s.rend(); ++rit)
	cout <<  *rit;
	cout << endl;
}


int main()
{
	PrintColumn(731);
	return 0;
}
