//Given a sorted and rotated array, find if there is a pair with a given sum
// Find the minimum element in a sorted and rotated array

#include<stdio.h>
#include<stdlib.h>

int binarySearch(int a[], int low, int high)
{
	int mid;

	mid = (low+high)/2;
printf("low = %d mid = %d high = %d\n", low, mid, high);
printf("l = %d m = %d h = %d\n", a[low], a[mid], a[high]);
	
	if(low > high)
		return 0;
	
	if(mid>low && a[mid]<a[mid-1])
		return mid;
	if(mid<high && a[mid]>a[mid+1])
		return mid+1;

	if(a[low] > a[mid])
		return(binarySearch(a, low, mid-1));
	else
		return(binarySearch(a, mid+1, high));
}



int main()
{

	int a[] = {11, 15, 26, 38, 9, 10};
	int sum = 45;
	int temp =0;
	int n = sizeof(a)/sizeof(a[0]);
	int least = binarySearch(a, 0, sizeof(a)/sizeof(a[0])-1);

	printf("%d \n", a[least]);

	int i = least, j = least-1;

	while(i!=j)
	{
		temp = a[i] + a[j];
		if(a[i] + a[j] == sum)
		{
			printf("%d+%d = %d\n", a[i], a[j], sum);
			return 0;
		}

		if(temp > sum)
		{
			j--;
			if(j<0)
			{
				j = n-1;
			}
		}
		else if(temp < sum)
		{
			i++;
			if(i == n)
			{
				i = 0;
			}
		}
	}

	return 0;

}
