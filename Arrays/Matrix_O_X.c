#include<stdio.h>
#include<stdlib.h>

#define M 6
#define N 6

int Fill( char mat[M][N], int i, int j)
{
	if(  i-1 < 0 || j-1 < 0 || i+1 >= M || j+1 >= N)
		return 0;


	if( mat[i-1][j] != 'O' && mat[i+1][j] != 'O' && mat[i][j-1] != 'O' && mat[i][j+1] != 'O' ) { 
		mat[i][j] = 'X';
		return 1;
	}

	mat[i][j] = '-';
	
	int left = 1, right = 1, top = 1, down = 1;
	if( mat[i - 1][j] == 'O' )
	{
        	left = Fill(mat, i - 1, j);
	}
	if( mat[i + 1][j] == 'O' )
	{
        	right = Fill(mat, i + 1, j);
	}
	if( mat[i][j - 1] == 'O' )
	{
        	down = Fill(mat, i, j - 1);
	}
	if( mat[i][j + 1] == 'O' )
	{	
        	top = Fill(mat, i, j + 1);
	}

	if( left && right && top && down )
	{
		mat[i][j] = 'X';
		return 1;
	}
	else
	{
		mat[i][j] = 'O';
		return 0;
	}

}
int main()
{
	char mat[M][N] =  	{{'X', 'O', 'X', 'X', 'X', 'X'},
                     		{'X', 'O', 'X', 'X', 'O', 'X'},
                     		{'X', 'X', 'X', 'O', 'O', 'X'},
                     		{'O', 'X', 'X', 'X', 'X', 'X'},
                     		{'X', 'X', 'X', 'O', 'X', 'O'},
                     		{'O', 'O', 'X', 'O', 'O', 'O'},
                    		};
	for(int i = 0; i < M; i++)
	{
		for(int j = 0; j<N; j++)
		{
			printf("\t %c", mat[i][j]);
		}
		printf("\n");
	}

	for(int i = 0; i < M; i++)
	{
		for(int j = 0; j<N; j++)
		{
			if( mat[i][j] == 'O')
			{
				Fill(mat, i, j);
			}
		}
	}

		printf("\n");
		printf("\n");
	for(int i = 0; i < M; i++)
	{
		for(int j = 0; j<N; j++)
		{
			printf("\t %c", mat[i][j]);
		}
		printf("\n");
	}
	return 0;
}
