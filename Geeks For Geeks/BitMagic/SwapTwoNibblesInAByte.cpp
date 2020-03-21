#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<string>
#include<map>

using namespace std;

unsigned char swapNibbles( unsigned char x )
{
	return ( (x & 0x0F) << 4 ) | ( (x & 0xF0) >> 4 );
}


int main(void)
{
	unsigned char x = 100;
	printf( "%d , %d \n", x, swapNibbles(x));
	return 0;
}
