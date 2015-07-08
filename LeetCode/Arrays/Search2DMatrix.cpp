/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
*/


// This problem can also be solve using Binary Search.. First binary search on last col.. and then the row
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        if( matrix.size() == 0 )
        {
            return false;
        }
        int rows = matrix.size();
        int cols = matrix[0].size();
        int i = 0;
        int j = cols - 1;
        while( i <=  rows - 1 && j >= 0)
        {
            if ( target == matrix[i][j] )
            {
                    return true;
            }
            else if( target < matrix[i][j] )
            {
                j--;
            }
            else if( target > matrix[i][j])
            {
                i++;
            }
        }
        
        return false;
    }
};
