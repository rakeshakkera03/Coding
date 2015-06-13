#include<stdio.h>
#include<stdlib.h>


int findMaxDifference(int a[], int s, int n)
{

	int min = 0;
	int max_sum = 0;
	
	if(a == NULL)
		return 0;

	min = a[s];
	for(int i = s + 1; i <= n; i++)
	{
		if((a[i] - min) > max_sum)
		{
			max_sum = a[i] - min;
		}

		if(a[i] < min)
			min = a[i];
	}

	return max_sum;
}

int main(void)
{
	int a[] = {100, 30, 15, 10, 8, 25, 80};
	int n = sizeof(a)/sizeof(a[0]);
	int max_sum = 0;
	max_sum = findMaxDifference(a, 0,  n-1);
	
	printf("%d \n", max_sum);
	for(int i = 1; i < n - 2; i++)
	{
		int first = findMaxDifference(a, 0, i);
		int second = findMaxDifference(a, i+1, n-1);

		if(max_sum <(first + second))
		{
			max_sum = first + second;
		}
	}
	printf("%d \n", max_sum);
	return 0;
}
