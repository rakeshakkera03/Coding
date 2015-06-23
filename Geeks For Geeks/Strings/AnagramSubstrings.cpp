/* Anagram Substring Search (Or Search for all permutations)
Given a text txt[0..n-1] and a pattern pat[0..m-1], write a function search(char pat[], char txt[]) that prints all occurrences of pat[] and its permutations (or anagrams) in txt[]. You may assume that n > m. 
Expected time complexity is O(n)

Examples:

1) Input:  txt[] = "BACDGABCDA"  pat[] = "ABCD"
   Output:   Found at Index 0
             Found at Index 5
             Found at Index 6
2) Input: txt[] =  "AAABABAA" pat[] = "AABA"
   Output:   Found at Index 0
             Found at Index 1
             Found at Index 4
*/

#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

template <typename Map>
bool map_compare (Map const &lhs, Map const &rhs)
{
    // No predicate needed because there is operator== for pairs already.
    return ( lhs.size() == rhs.size() ) && equal( lhs.begin(), lhs.end(), rhs.begin() );
}


void AnagramSubstringSearch(string &A, string &B, map<char, int> &m, int pat_hash)
{
	int str_sum = 0, str_hash = 0;
	int nn = A.length(), mm = B.length();
	map<char, int>n;
	map<char, int>::iterator it;

	//Calculate the hash of the first window in the string A.

	for(int i = 0; i < B.length(); i++ )
	{
		it = n.find(B[i]);
		if( it == n.end() )
		{
			n[A[i]] = 1;
		}
		else
		{
			n[A[i]]++;
		}
		str_sum = str_sum + A[i];		
	}
	str_hash = str_sum % 257;

	for( int i = 0; i < nn - mm; i++ ) 
	{
		if(str_hash == pat_hash)
		{
			if ( map_compare( n, m ) )
			{
				cout << "Anagram found at index : " << i  << endl;
			}

		}
		
		str_hash = (str_hash + 257 - A[i] + A[i + mm - 1] ) % 257; 
	}
}

int main()
{
	string A = "BACDGABCDA";
	string B = "ABCD";
	
	map<char, int> m;
	map<char, int>::iterator it;
	int pat_hash = 0, pat_sum = 0;
	int str_hash = 0, str_sum = 0;

	if( A.empty() || B.empty() || B.length() > A.length() )
	{
		return -1;
	}

	for(int i = 0; i < B.length(); i++ )
	{
		it = m.find(B[i]);
		if( it == m.end() )
		{
			m[B[i]] = 1;
		}
		else
		{
			m[B[i]]++;
		}
		pat_sum = pat_sum + B[i];
	}
	pat_hash = pat_sum % 257;

	AnagramSubstringSearch(A, B, m, pat_hash);

	return 0;
}
