/*
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =

[
  ["ABCE"],
  ["SFCS"],
  ["ADEE"]
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.
*/

class Solution {
public:
    
    bool Search( vector<vector<char> > &board, string &word, int index, int row, int col)
    {
        if( index == word.size() )
        {
            return true;
        }
        if( row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || board[row][col] != word[index])
        {
            return false;
        }
        
            board[row][col] = '-';
            
            if( Search(board, word, index + 1, row + 1, col) )
            {
                return true;
            }
            else if ( Search(board, word, index + 1, row - 1, col) )
            {
                return true;
            }
            else if ( Search(board, word, index + 1, row, col + 1) )
            {
                return true;
            }
            else if ( Search(board, word, index + 1, row, col - 1) )
            {
                return true;
            }
            else
            {
               board[row][col] = word[index];
               return false;
            }
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        
        if(board.size() == 0 || word.size() == 0 )
            return false;
        
        for( int i = 0; i < board.size(); i++ )
        {
            for( int j = 0; j < board[0].size(); j++ )
            {
                if( board[i][j] == word[0] )
                {
                    bool res = Search( board, word, 0, i, j );
                    
                    if ( res )
                        return true;   
                }
            }
        }
        
        return false;
        
    }
};
