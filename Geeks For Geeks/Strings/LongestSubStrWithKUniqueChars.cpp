#include<iostream>
#include<string>
#include<vector>

#define MAX 256

using namespace std;

bool isValid(int count[], int k )
{
	int u = 0;
	for(int i = 0; i < MAX; i++ )
	{
		if( count[i] > 0 )
		{
			u++;
		}
	}

	return (k >= u);
}

void getLongestSubStr(string s, int k)
{
	int count[MAX];
	memset(count, 0, sizeof(int) * MAX);
	
	int u = 0;

	if( k == 0 )
	{
		printf("\n Error: k = 0 \n");
		return;
	}

	for(int i = 0; i < s.length(); i++)
	{
		if(count[s[i] - 'a'] == 0)
		{
			u++;
			count[s[i] - 'a'] = 1;
		}
		else
		{
			count[s[i] - 'a']++;
		}
	}

	if( u < k )
	{
		printf("\n There are less unique chars than k \n");
		return;
	}

	memset(count , 0 , sizeof(int) * MAX);

	int curr_start = 0, curr_end = 0, max_substr_start = 0, max_length = 1;

	count[s[0] - 'a']++;

	for(int i = 1; i < s.length(); i++)
	{
		count[s[i] - 'a']++;
		curr_end++;

		//Check if current sub-string is valid (i.e unique count <= k)
		while( !isValid(count, k))
		{
			count[s[curr_start] - 'a']--;
			curr_start++;
		}


		if( (curr_end - curr_start + 1) > max_length )
		{
			max_length = curr_end - curr_start + 1;
			max_substr_start = curr_start;
		}
	}

	cout << "Max substring is: " << s.substr(max_substr_start, max_length) << " with lenght " << max_length << endl;
}

int main()
{
	string s = "aabacbebebe";
	int k = 3;

	getLongestSubStr(s, k);
	
	return 0;
}
