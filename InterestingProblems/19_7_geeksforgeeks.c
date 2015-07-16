//Largest sum contiguous subarray (crack the coding interview)

/*Kadane's algorithm:

Initialize max_so_far = 0
	   max_ending_here = 0

Loop for each element of the array
 a) max_ending_here = max_ending_here + a[i]
 b) if(max_ending_here < 0)
 	max_ending_here = 0;
 c) if(max_so_far < max_ending_here)
 	max_so_far = max_ending_here
return max_so_far
*/

#include<stdio.h>
#include<stdlib.h>

int maxCrossingSum(int a[], int l, int m, int h, int* l_index, int* r_index)
{
	int sum = 0;
	int left_sum = 0, right_sum = 0;

	for(int i = m; i >= l; i--)
	{
		sum = sum + a[i];
		if(sum > left_sum) {
			left_sum = sum;
			*l_index = i;
		}
	}

	sum = 0;
	right_sum = 0;
	for(int i = m+1; i <= h; i++)
	{
		sum = sum + a[i];
		if(sum > right_sum) {
			right_sum = sum;
			*r_index = i;
		}
	}

	return (left_sum + right_sum);
}

int maxSubArraySum(int a[], int l, int h, int* l_index, int* r_index)
{
	int ll = 0, lh = 0, ml = 0, mh = 0, rl = 0 , rh = 0;
	int m = 0, left = 0, right = 0, crossing = 0;

	if(l == h) {
		*l_index = l;
		*r_index = l;
		return a[l];
	}
	
	m = (l+h)/2;
//printf("l = %d, m = %d, h = %d\n", l, m, h);	
	left = maxSubArraySum(a, l, m, &ll, &lh);
	right = maxSubArraySum(a, m+1, h, &rl, &rh);
	crossing = maxCrossingSum(a, l , m , h, &ml, &mh);
//printf("left = %d, crossing = %d, right = %d, l = %d, m = %d, h = %d\n", left, crossing, right, l, m, h);
	if(left >= right)
	{
		if(left >= crossing)
		{
			*l_index = ll;
			*r_index = lh;
			return left;
		}
		else {
			*l_index = ml;
			*r_index = mh;
			return crossing;
		}
	}
	else {
		if(right >= crossing)
		{
			*l_index = rl;
			*r_index = rh;
			return right;
		}
		else {
			*l_index = ml;
			*r_index = mh;
			return crossing;
		}
	}
		
}

int maxSubArray(int a[], int n)
{
	int max_so_far = 0, max_ending_here = 0;
	int i = 0;
	for(i = 0;i<n;i++)
	{
		max_ending_here = max_ending_here + a[i];

		if(max_ending_here < 0)
			max_ending_here = 0;
		if(max_so_far < max_ending_here)
			max_so_far = max_ending_here;
	}
	return max_so_far;

}
int main(void)
{
	int l_index, r_index;
//	int a[] = {-2,-3,4,-1,-2,1,5,-3};
//	int a[] = {13, 14, -6, -2, -3, -1, -5, -6};
	int a[] = {-2, -5, 6, -2, 3, -10, 5, -6};
	int n = sizeof(a)/sizeof(a[0]);
	int max_sum = maxSubArray(a,n);
	printf("Maximum Contiguous sum is %d\n", max_sum);


	max_sum = maxSubArraySum(a, 0, n-1, &l_index, &r_index);
	printf("Maximum Contiguous sum is %d, l_index = %d, r_index = %d\n", max_sum, l_index, r_index);
	return 0;
}
