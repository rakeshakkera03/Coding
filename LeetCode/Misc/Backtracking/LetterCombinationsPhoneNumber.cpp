/*
Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
*/


class Solution {
public:
    vector<string> keypad = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
    
    void PrintLetterCombinations( string digits, int level, string &temp, vector<string> &result )
    {
        if( level == digits.size() )
        {
            result.push_back(temp);
            return;
        }
        
        for( int i = 0; i < keypad[digits[level] - '0'].size(); i++ )
        {
            temp.push_back(keypad[digits[level] - '0'][i]);
            
            PrintLetterCombinations( digits, level + 1, temp, result );
            
            temp.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        
        vector<string> result;
        result.clear();
        string temp;
        int level = 0;
        
        if( digits.size() == 0 )
            return result;
            
        PrintLetterCombinations( digits, level, temp, result );
        
    }
};
