// Look at commented code below..

#include<iostream>
#include<vector>
#include<map>
#include<algorithm>


using namespace std;

pair<int,int> flip_pair(const pair<int,int> &p)
{
	return pair<int,int>(p.second, p.first);
}

multimap<int,int> flip_map( const map<int,int> &src)
{
	multimap<int, int> dst;

	transform(src.begin(), src.end(), inserter(dst, dst.begin()), flip_pair );

	return dst;
}



int main()
{
	int a[] = {2, 5, 2, 8, 5, 6, 8, 8 };	
	int n = sizeof(a)/sizeof(a[0]);

	map<int, int> m;
	
	for(int i = 0; i < n; i++)
	{
		if( m[a[i]] )
			m[a[i]]++;
		else
		{
			m[a[i]] = 1;
		}
	}

	multimap<int, int> dest = flip_map(m);

	int i = n - 1;

	for ( multimap<int, int>::iterator itr = dest.begin(); itr != dest.end(); ++itr )
	{
        int k = itr->first;
        while ( k-- )
        {
            // cout<< itr->second << "\t";
            a[i] = itr->second;
            --i;
        }
    }

    for (int i = 0; i < n; ++i)
    {
        cout << a[i] << "\t" ;
    }
    cout << endl;
	return 0;
}


/*

#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

pair<int,int> flip_pair(const pair<int, int> &p)
{
    return pair<int, int> ( p.second, p.first );

}
multimap<int, int> flip_map(const map<int, int> &myMap)
{
    multimap<int, int> res;
    transform(myMap.begin(), myMap.end(), inserter(res, res.begin()), flip_pair );
    return res;
}
void
sortbyfreq(int* a, int size)
{
    map<int,int> myMap;

    for (int i = 0; i < size; ++i)
    {
        if ( myMap[a[i]] )
            myMap[a[i]] += 1;
        else
            myMap[a[i]] = 1;
    }

    multimap<int, int> result = flip_map(myMap);

    int i = size -1 ;
    for ( multimap<int, int>::iterator itr = result.begin(); itr != result.end(); ++itr )
    {
        int k = itr->first;
        while ( k-- )
        {
            // cout<< itr->second << "\t";
            a[i] = itr->second;
            --i;
        }
    }
    cout << endl ;
}
int main(int argc, char *argv[])
{
    int a[] = {2, 5, 2, 8, 5, 6, 8, 8};
    int size = sizeof (a) / sizeof(a[0]);
    sortbyfreq(a, size);

    for (int i = 0; i < size; ++i)
    {
        cout << a[i] << "\t" ;
    }
    cout << endl;
    return 0;
}

*/
