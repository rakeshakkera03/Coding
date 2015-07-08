/*
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
*/


//DP question.. Need to use map to reduce complexity
class Solution {
public:
    int FindMin(vector<vector<int> > &triangle, int i, int j, map<pair<int, int>, int> &m)
    {
        if( i == triangle.size() )
            return 0;
        if( j == triangle[i].size())
            return INT_MAX;
        
        if(m.find(make_pair(i,j)) != m.end() )
            return m[make_pair(i,j)];
        
        m[make_pair(i,j)] = triangle[i][j] + min( FindMin(triangle, i+1, j, m), FindMin(triangle, i+1, j+1, m) );
        
        return ( m[make_pair(i,j)] );
    }
    
    int minimumTotal(vector<vector<int> > &triangle) {
        int min = 0;
        map<pair<int, int>, int> m;
        m.clear();
        
        if(triangle.size() == 0)
            return 0;
            
        min = FindMin(triangle, 0, 0, m);
        
        return min;
        
    }
    
};
