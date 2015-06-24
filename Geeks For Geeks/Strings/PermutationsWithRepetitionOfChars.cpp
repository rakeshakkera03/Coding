/*
Print all permutations with repetition of characters
Given a string of length n, print all permutation of the given string. Repetition of characters is allowed. Print these permutations in lexicographically sorted order 
Examples:

Input: AB
Ouput: All permutations of AB with repetition are:
      AA
      AB
      BA
      BB

Input: ABC
Output: All permutations of ABC with repetition are:
       AAA
       AAB
       AAC
       ABA
       ...
       ...
       CCB
       CCC
*/

#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

void PrintPermutationsWithRepetitions(string &s, int level, string &r)
{
	if(level > s.length())
	{
		cout << r << endl;
		return;
	}

	for(int i =0 ; i < s.length(); i++)
	{
		r.push_back(s[i]);
		PrintPermutationsWithRepetitions(s, level + 1, r);
		r.pop_back();
	}

}

int main()
{
	string s = "AB";
	string r;
	PrintPermutationsWithRepetitions(s, 0, r);

	return 0;
}
