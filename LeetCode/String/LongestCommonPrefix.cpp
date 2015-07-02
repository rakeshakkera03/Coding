class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        string result;
        string temp;
        if( strs.size() == 0)
            return "";
        else if( strs.size() == 1 )
            return strs[0];
        else
            result = strs[0];
            
        for(int i = 1; i < strs.size(); i++ )
        {   
                int j = 0;
                while( j < result.length() && j < strs[i].length())
                {
                    if(result[j] == strs[i][j])
                    {
                        temp += result[j];
                    }
                    else
                        break;
                    j++;
                }
                result = temp;
                temp.clear();
        }
        
        return result;
    }
};
