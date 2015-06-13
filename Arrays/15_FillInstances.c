//Fill two instances of all numbers from 1 to n in a specific way

#include<stdio.h>
#include<stdlib.h>


int fillUtil(int res[], int curr, int n)
{
	int i;

	if(curr == 0)
		return true;
	
	for(i = 0; i < 2*n-curr-1; i++)
	{
		if(res[i] == 0 && res[i+curr+1] == 0)
		{
			res[i] = res[i+curr+1] = curr;
		}
	}



}
