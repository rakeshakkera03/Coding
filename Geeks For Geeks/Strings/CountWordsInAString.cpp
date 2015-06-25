/*
Count words in a given string
Given a string, count number of words in it. The words are separated by following characters: space (‘ ‘) or new line (‘\n’) or tab (‘\t’) or a combination of these.
*/

#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;


void CountWords(char* str)
{
	bool firstChar = true;
 	int count = 0;
	if( str == '\0' )
		return;

	int i = 0;
	while( str[i] != '\0' )
	{
		if( str[i] == ' ' || str[i] == '\n' || str[i] == '\t' )
		{
			firstChar = true;
			i++;
			continue;
		}
		else
		{
			if( firstChar == true )
			{
				firstChar = false;
				count++;
				i++;
			}
			else
			{
				i++;
			}
		}

	}

	cout << "Count of Words is : " << count << endl;
}

int main()
{
	char str[] = "One two          three\n  four\nfive  ";

	CountWords(str);
	return 0;
}
