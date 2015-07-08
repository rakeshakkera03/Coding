/*
Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

For example,
Given n = 3,

You should return the following matrix:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
*/

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
     
     // This is how you initialize a 2-dimentional vector of fixed size to '0'   
     vector<vector<int> > matrix(n, vector<int> (n, 0) );
     if( n == 0)
        return matrix;
     int rows = n;
     int cols = n;
     int count = 1;
     
     // Setting up all 4 boundaries 
     int west_boundary = rows - 1;
     int south_boundary = cols - 1;
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
             matrix[north_boundary][i] = count++;
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
             matrix[i][west_boundary] = count++;
         }
         north_boundary++;
         for(int i = west_boundary - 1; i >= east_boundary && north_boundary <= south_boundary; i-- )
         {
             matrix[south_boundary][i] = count++;
         }
         west_boundary--;
         for(int i = south_boundary - 1; i >= north_boundary && east_boundary <= west_boundary; i-- )
         {
             matrix[i][east_boundary] = count++;
         }
         south_boundary--;
     }
     
     return matrix;
    }
};
