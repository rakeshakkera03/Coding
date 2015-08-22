/*

*/
class Solution {
public:
bool isOneEditDistance(string s, string t)
{	
	int n = 0, m = 0;
	if( (s.size() == 0 && t.size() == 0) )
		return true;
	
	if( s.size() > t.size() )
	{
		n = s.size();
		m = t.size();
	}
	else
	{
		n = t.size();
		m = s.size();
		string k = s;
		s = t;
		t = k;
	}

	if( n - m >  1 )
		return false;
	
	int i = 0, j = 0;
	int edit = 0;
	if( n - m == 1 )
	{
		while( i < n && j < m )
		{
			if( s[i] == t[i] )
			{
				i++;
				j++;
				continue;
			}
			else
			{
				if( edit == 0 )
				{
					edit = 1;
					i++;
				}
				else
				{
					return false;
				}
			}
		}
	}
	else
	{
		while( i < n && j < m )
		{
			if( s[i] == t[i] )
			{
				i++;
				j++;
				continue;
			}
			else
			{
				if( edit == 0 )
				{
					edit = 1;
					i++;
					j++;
				}
				else
					return false;
			}
		}
	}
	
	if ( n == 1 && m == 0 )	return true;

	return ( (edit == 1)? true: false );


}
};
