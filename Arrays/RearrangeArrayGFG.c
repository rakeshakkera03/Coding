#include<stdio.h>
#include<stdlib.h>


void RearrangeArray(int a[], int n, int level)
{
	if( level == n )
	{
		return;
	}

	int x = a[ level ];

	RearrangeArray( a, n, level + 1);

	a[ x ] = level;
}


int main()
{
	//int a[] = { 1, 3, 0, 2 };
	int a[] = { 3, 2, 1, 0 };
//	int a[] = { 2, 0, 1, 4, 5, 3 };
	int n = sizeof(a)/sizeof(a[0]);

	for(int i = 0 ; i < n ; i++)
	{
		printf("\t%d", a[i]);
	}

	RearrangeArray( a, sizeof(a)/sizeof(a[0]), 0 );

	printf("\n");

	for(int i = 0 ; i < n ; i++)
	{
		printf("\t%d", a[i]);
	}
	printf("\n");
	
	return 0;
}
