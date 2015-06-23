/*
Remove spaces from a given string
Given a string, remove all spaces from the string and return it.

Input:  "g  eeks     for ge  eeks  "
Output: "geeksforgeeks"

*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main()
{
	char A[] = "g  eeks     for ge  eeks  ";
	int replace = 0, iterator = 0;

	if( !A ) 
		return 0;
	
	for(iterator = 0; iterator < strlen(A);)
	{
		if( A[iterator] != ' ')
		{
			A[replace++] = A[iterator++];
		}
		else
		{
			iterator++;
		}	
	}

	A[replace] = '\0';

	printf("\n%s\n", A);
	
	return 0;
}
