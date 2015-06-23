/*
Recursively print all sentences that can be formed from list of word lists
*/

#include<iostream>
#include<vector>
#include<string>

using namespace std;

void PrintSentences(vector<vector<string> >&v, vector<string>&r, int level)
{
	if( level == v.size() )
	{
		for( int i = 0; i < r.size(); i++ )
		{
			cout << r[i] << " ";
		}
		cout << endl;
		return;
	}

	for( int i = 0; i < v[level].size(); i++ )
	{
		r.push_back(v[level][i]);
		PrintSentences(v, r, level + 1 );
		r.pop_back();
	}
}

int main()
{
	vector< vector<string> > v;
	vector<string> s;
	vector<string> r;

	s.push_back("you");
	s.push_back("we");
	v.push_back(s);
	s.clear();

	s.push_back("have");
	s.push_back("are");
	v.push_back(s);
	s.clear();

	s.push_back("sleep");
	s.push_back("eat");
	s.push_back("drink");
	v.push_back(s);
	s.clear();

	for(int i = 0; i < v.size(); i++)
	{
		for( int j = 0; j < v[i].size(); j++ )
		{
//			cout << v[i][j] << " ";
		}
		cout << endl;
	}
	PrintSentences(v, r, 0);
	return 0;
}

