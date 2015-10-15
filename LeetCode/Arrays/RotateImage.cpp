/*
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Follow up:
Could you do this in-place?
*/

void rotate(vector<vector<int>>& matrix) {
        
        if( matrix.size() == 0 )
        {
            return;
        }
        
        int n = matrix.size();
        int offset = 0;
        int temp;
        
        for(int layer = 0; layer < n/2 ; layer++ )
        {
            int first = layer;
            int last = n - 1 - layer;
            
            for( int i = first; i < last; i++ )
            {
                int offset = i - first;
                
                int top = matrix[first][i];
                
                matrix[first][i] = matrix[last - offset][first];
                
                matrix[last - offset][first] = matrix[ last ][ last - offset ];
                
                matrix[ last ][ last - offset ] = matrix[ i ][ last ];
                
                matrix[ i ][ last ] = top;
            }
        }
        
        
    }
