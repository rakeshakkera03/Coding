class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        
        vector<string> result;
        string s;
        int start = 0, end = 0;
        
        if(nums.size() == 0)
            return result;
        
        while(end < nums.size())
        {
            if( end + 1 < nums.size() && (nums[end+1] == nums[end] + 1))
            {
                end++;
            }
            else
            {
                if( start == end )
                {
                    s += to_string(nums[start]);
                    result.push_back(s);
                    end++;
                    start = end;
                    s.clear();
                }
                else
                {
                    s += to_string(nums[start]) + '-' + '>' + to_string(nums[end]);
                    result.push_back(s);
                    s.clear();
                    end++;
                    start = end;
                }
            }
        }
        
        return result;
    }
};
