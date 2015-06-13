#include<stdio.h>
#include<stdlib.h>


void printIncreasingSequence(int a[], int b[], int level, int n, int k)
{
	if( level == k)
	{
		for(int i = 0; i < k ; i++)
		{
			printf("%d ", b[i]);
		}
		printf("\n");
		return;
	}

	for(int i = 0; i <= n-1; i++)
	{
		b[ level ] = a[ i ];

		printIncreasingSequence(a, b, level + 1, n, k);

	}
}

int main()
{
	int n = 2, k = 3;
	int a[n];
	int b[n];

	for(int i = 0; i < n; i ++)
	{
		a[i] = i+1;
	}

	printIncreasingSequence(a, b, 0, n, k);

	return 0;
}	
