// Find a common element in all rows of a given row-wise sorted matrix

#include<stdio.h>
#include<stdlib.h>


int findCommon(int mat[m][n])
{
	int column[m];
	int min_row = 0;
	int min_element= mat[0][n-1];

	for(i = 0; i 
	for(int i = 1; i < m; i++)
	{
		if(mat[i][n-1] < min_element)
		{
			min_row = i;
			min_element = mat[i][n-1];
		}
	}

	while(column
}
