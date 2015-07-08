/*
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5].
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
     
     vector<int> result;
     if( matrix.size() == 0)
        return result;
     int m = matrix.size();
     int n = matrix[0].size();
     
     // Setting up all 4 boundaries 
     int west_boundary = n - 1;
     int south_boundary = m - 1;
     int east_boundary = 0;
     int north_boundary = 0;
     
     // This initial boundary condition is necessary since we don't want to 
     // increment the east boundary on the very first iteration.
     int flag = 0;
     int initial_boundary = east_boundary;
     
     // The idea here is to collapse the boundary by 1 after a complete traversal on the boundary.. 
     // Thus after every boundary traversal, we increment the boundary by 1.
     
     while( east_boundary <= west_boundary && north_boundary <= south_boundary )
     {
         if( flag == 1 )
            initial_boundary = east_boundary + 1;
         for(int i = initial_boundary; i <= west_boundary && north_boundary <= south_boundary; i++ )
         {
             result.push_back(matrix[north_boundary][i]);
         }
         if( flag == 1 )
            east_boundary++;
         flag = 1;
         
         // Here we start at north_boundary since in the east_boundary traversal would have already
         // printed the element intersecting east_boundary and north_boundary.
         // The condition "east_boundary <= west_boundary" is necessary, for inputs like having only one 
         // row, to avoid traversing backwards on already printed row.
         for(int i = north_boundary + 1; i <= south_boundary && east_boundary <= west_boundary; i++ )
         {
             result.push_back(matrix[i][west_boundary]);
         }
         north_boundary++;
         for(int i = west_boundary - 1; i >= east_boundary && north_boundary <= south_boundary; i-- )
         {
             result.push_back(matrix[south_boundary][i]);
         }
         west_boundary--;
         for(int i = south_boundary - 1; i >= north_boundary && east_boundary <= west_boundary; i-- )
         {
             result.push_back(matrix[i][east_boundary]);
         }
         south_boundary--;
     }
     
     return result;
    }
};
