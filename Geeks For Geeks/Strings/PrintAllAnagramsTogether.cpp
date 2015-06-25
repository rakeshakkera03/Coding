/*
Given an array of words, print all anagrams together. For example, if the given array is {“cat”, “dog”, “tac”, “god”, “act”}, then output may be “cat tac act dog god”.
*/

#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;


void PrintAnagramsTogether(vector<string>&s, map<string, int>&m, vector<string>&r )
{
	if( s.size() == 0 )
		return;
	
	int used[s.size()];
	memset(used, 0, sizeof(int) * s.size());


	for( int i = 0; i < s.size(); i++ )
	{
		if( used[i] != 1 )
		{
			used[i] = 1;
			r.push_back(s[i]);
		
			for( int k = i+1; k < s.size(); k++)
			{
				if( s[i].length() != s[k].length() )
					continue;
				if(m[s[i]] != m[s[k]])
					continue;

				string out = s[ k ];
            			string in  = s[ i ];

            			sort( in.begin(), in.end() );
            			sort( out.begin(), out.end() );

           	 		if( out.compare( in ) != 0 )
            			{
                			continue;
            			}
				else 
				{
					used[k] = 1;
					r.push_back(s[k]);

				}

			}
		}
	}
	for(int i= 0 ; i < r.size(); i++)
	{
		cout << r[i] << endl;	
	}

}


int CalculateHashValue(string str)
{
	int sum = 0;
	for(int i = 0; i < str.length(); i++)
	{
		sum = sum + (str[i] - '0');
	}
	return sum;
}

void CreateHashMap(vector<string>&s, map<string, int>&m)
{
	map<string, int>::iterator it;
	for( int i = 0; i < s.size(); i++ )
	{
		it = m.find(s[i]);
		if( it == m.end() )
		{
			m[s[i]] = CalculateHashValue(s[i]);
		}
	}
}

int main()
{
	vector<string> input;
	vector<string> r;
	map<string, int> m;

	    input.push_back( "aidtya" );
    input.push_back( "mamd" );
    input.push_back( "cat" );
    input.push_back( "dog" );
    input.push_back( "hell" );
    input.push_back( "acbd" );
    input.push_back( "tac" );
    input.push_back( "bell" );
    input.push_back( "god" );
    input.push_back( "aditya" );
    input.push_back( "idaayt" );
    input.push_back( "admm" );
    input.push_back( "act" );
    input.push_back( "abcd" );
    input.push_back( "dbab" );
	CreateHashMap( input, m );
	PrintAnagramsTogether(input, m, r);
	return 0;
}
