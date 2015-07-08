/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?
*/

class Solution {
public:
    // Aditya's Solution
    int CalculateUniquePaths( int maxRows, int maxCols, int currRow, int currCol, map<pair<int,int>, int> &coordinateMap )
    {
        if( currRow == maxRows - 1 || currCol == maxCols - 1 )
        {
            return 1;
        }
        
        if( coordinateMap.find( make_pair( currRow, currCol ) ) != coordinateMap.end() )
        {
            return coordinateMap[ make_pair( currRow, currCol) ];
        }
        
        coordinateMap[ make_pair( currRow, currCol) ] =
                        CalculateUniquePaths( maxRows, maxCols, currRow, currCol + 1, coordinateMap ) +
                        CalculateUniquePaths( maxRows, maxCols, currRow + 1, currCol, coordinateMap );
                        
        return coordinateMap[ make_pair( currRow, currCol) ];                        
    }
    
    int uniquePaths(int m, int n)
    {
        map<pair<int,int>, int> coordinateMap;
        coordinateMap.clear();
        
        return CalculateUniquePaths( m, n, 0, 0, coordinateMap );
    }
};
