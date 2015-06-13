#include<stdio.h>
#include<stdlib.h>


void printIncreasingSequence(int a[], int b[], int level, int n, int k, int start, int end)
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

	for(int i = start; i <= end; i++)
	{
		b[ level ] = a[ i ];

		printIncreasingSequence(a, b, level + 1, n, k, i + 1, end);

	}
}

int main()
{
	int n = 5, k = 1;
	int a[n];
	int b[n];

	for(int i = 0; i < n; i ++)
	{
		a[i] = i+1;
	}

	printIncreasingSequence(a, b, 0, n, k, 0, n-1);

	return 0;
}	
