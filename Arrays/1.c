#include<stdio.h>
#include<stdlib.h>

void FindLargestPairSum(int a[], int n)
{
	int l = 0, s = 0;

	if( n <= 1 )
		return; 

	l = a[0]; s = a[0];
	for( int i = 2; i < n; i++)
	{
		if(a[i] >= l)
		{
			s = l;
			l = a[i];
			continue;
		}
		if(a[i] > s)
		{
			s = a[i];
		}
	}

	printf("\nLargest sum = %d\n", s + l);
}

int main()
{
	int a[] = {-3, -5, -6 ,-8, -2, -15};
	
	FindLargestPairSum(a, sizeof(a)/sizeof(a[0]));
}

