#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define d 256

void search(char* a, char* b, int q)
{
	int n = strlen(a);
	int m = strlen(b);

	int h = 1, p = 0, t = 0, j;

	for( int i = 0; i < m-1 ; i++ )
	{
		h = d*h % q;	
	}

	for( int i = 0; i < m; i++ )
	{
		p = (d*p + b[i]) % q;
		t = (d*t + a[i]) % q;
	}

	for( int i = 0; i <= n - m; i++ ) 
	{
		if( p == t )
		{
			printf("\n Got a spurious hit .. check if it is a hit at index %d\n", i);

			for( j = 0; j <  m; j++ )
			{
				if( a[i + j] != b[j] )
					break;
			}
			if( j == m )
			{
				printf("\n Got a hit at index %d\n", i );
			}
		}

		if( i < n-m )
		{
			t = ( (t - a[i]*h)*d + a[i + m] ) % q;
		}
		
		if( t < 0 )
			t = t + q;
		//	printf("\n hash starting at %c is %d \n", a[i+1], t);
	}
}




int main()
{
	char* A = "23590131415267314159921";
	char* B = "31415";

	printf("\n Text = \t%s", A);
	printf("\n Patt = \t%s", B);
	int q = 101;
	search(A, B, q);

	return 0;
}
