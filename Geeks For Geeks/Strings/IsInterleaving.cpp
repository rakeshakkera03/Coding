/*
Check whether a given string is an interleaving of two other given strings
*/

#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

int isInterleaving(char* s1, char* s2, char* s3)
{
	int flag1 = 0, flag2 = 0;
	if( *s1 == '\0' && *s2 == '\0' && *s3 == '\0' )
	{
		return 1;
	}
	if( *s3 != *s1 && *s3 != *s2 )
	{
		return 0;
	}

	if( *s3 == *s1 )
	{
		flag1 = isInterleaving( s1+1, s2, s3+1 );
	}
	
	if ( *s3 == *s2 )
	{
		flag2 = isInterleaving( s1, s2 + 1, s3 + 1 );
	}

	return (flag1 || flag2);
	
}


int main()
{
	char* s1 = "ADFB";
	char* s2 = "BDGY";
	char* s3 = "ABDGDFYB";

	if( strlen(s3) != (strlen(s1) + strlen(s2)))
	{
		cout << "Not an interleaving " << endl;
		return 0;
	}

	if( isInterleaving(s1, s2, s3) )
	{
		cout << "Interleaving" << endl;
	}
	else
		cout << "Not Interleaving" << endl;
		

	return 0;

}
