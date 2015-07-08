/*
Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1]
*/

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        
        vector<int> result;
        vector<int> temp;

        if( rowIndex == 0 )
        {
            result.push_back(1);
            return result;
        }
        else
        {
            temp.push_back(1);
            temp.push_back(1);
        } 
        
        for( int i = 2; i <= rowIndex; i++ )
        {
            for( int j = 0; j <= i; j++ )
            {
                if( j == 0 )
                {
                    result.push_back(1);
                }
                else if ( j == i )
                {
                    result.push_back(1);
                }
                else
                {
                    result.push_back( temp[j - 1] + temp[j]);
                }
            }
            temp.clear();
            temp = result;
            result.clear();
        }
        
        result = temp;
        
        return result;
    }
};
