/* Function to find Number of customers who could not get a computer */

#include<iostream>
#include<vector>
#include<map>
#include<string>

using namespace std;


int main()
{

	int computers = 1;
	string s = "ABCBCADEED";
	int remaining = computers;
	int no_access = 0;

	map<char, pair<int, bool> > m;

	for( int i = 0; i< s.length(); i++ )
	{
		map<char, pair<int, bool> >::iterator it;
		it = m.find(s[i]);
		if( it == m.end() )
		{
			if( remaining > 0 )
			{
				remaining--;
				m[s[i]].first = 1;
				m[s[i]].second = true;
			}
			else
			{
				m[s[i]].first = 1;
				m[s[i]].second = false;
			}
		}
		else
		{
			if( m[s[i]].second == true )
			{
				remaining++;
				m.erase(s[i]);
			}
			else
			{
				no_access++;
				m.erase(s[i]);
			}
		}
	}

	cout << "Number of Users with no access : " << no_access << endl;
	return 0;
}
