/*
Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.
*/
class Solution {
public:
    // Aditya's Solution
    int CalculateUniquePaths( vector<vector<int> > &obstacleGrid, int maxRows, int maxCols, int currRow, int currCol, map<pair<int,int>, int> &coordinateMap )
    {
        cout << "currRow: " << currRow << " currCol: " << currCol << endl;

        if( obstacleGrid[currRow][currCol] == 1 )
        {
            return 0;
        }
        if( (currRow == maxRows - 1 || currCol == maxCols - 1) &&  obstacleGrid[currRow][currCol] == 0)
        {
            return 1;
        }
        
        if( coordinateMap.find( make_pair( currRow, currCol ) ) != coordinateMap.end() )
        {
            return coordinateMap[ make_pair( currRow, currCol) ];
        }
        
        coordinateMap[ make_pair( currRow, currCol) ] =
                        CalculateUniquePaths( obstacleGrid, maxRows, maxCols, currRow, currCol + 1, coordinateMap ) +
                        CalculateUniquePaths( obstacleGrid, maxRows, maxCols, currRow + 1, currCol, coordinateMap );
                        
        return coordinateMap[ make_pair( currRow, currCol) ];                        
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        map<pair<int,int>, int> coordinateMap;
        coordinateMap.clear();
    
        int i = n - 1, flag = 0;
        
        //Modifying the last Row, such that, when an obstacle is encountered all the blocks prior to it are marked
        // as obstacles.
        while( i >= 0)
        {
            if( flag == 1 )
            {
                obstacleGrid[m-1][i] = 1;
                i--;
                continue;
            }
            if( obstacleGrid[m-1][i] == 0)
            {
                i--; continue;
            }
            else
            {
                flag = 1;
            }
        }
        
        i = m - 1, flag = 0;
        
        //Modifying the last Column, such that, when an obstacle is encountered all the blocks prior to it are marked
        // as obstacles.
        while( i >= 0)
        {
            if( flag == 1 )
            {
                obstacleGrid[i][n-1] = 1;
                i--;
                continue;
            }
            if( obstacleGrid[i][n-1] == 0)
            {
                i--; continue;
            }
            else
            {
                flag = 1;
            }
            
        }
        
        return CalculateUniquePaths( obstacleGrid, m, n, 0, 0, coordinateMap );
    }
};
