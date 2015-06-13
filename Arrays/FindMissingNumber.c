#include<stdio.h>
#include<stdlib.h>

int main()
{
	int a[] = { 0, 1, 2, 3, 5, 6, 7 , 8 };
	int low = 0 , high = sizeof(a)/sizeof(a[0]);
	int mid;

	if( a[low] == low && a[high] == high )
		return 0;

	while ( low <= high )
	{
		mid = (low + high)/2;

		if( a[mid] == mid )
		{
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}
	}
	
	printf("\n %d\n", low);
	
	return 0;
}
