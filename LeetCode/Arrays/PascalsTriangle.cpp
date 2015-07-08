/*
Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
*/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int> > result;
        vector<int> temp;
        if(numRows == 0 )
        {
            return result;
        }
        else if (numRows == 1 )
        {
            temp.push_back(1);
            result.push_back(temp);
            return result;
        }
        else 
        {
            temp.push_back(1);
            result.push_back(temp);
            temp.push_back(1);
            result.push_back(temp);
            temp.clear();
        }
        
        for( int i = 2; i < numRows; i++)
        {
            for( int j = 0; j <= i; j++ )
            {
                if( j == 0 )
                {
                    temp.push_back(1);
                }
                else if( j == i )
                {
                    temp.push_back(1);
                }
                else
                {
                    temp.push_back( result[i - 1][j - 1] + result[i - 1][j] );
                }
            }
            result.push_back(temp);
            temp.clear();
        }
        
        return result;
        
    }
};
