class Solution {
public:
    /**********************************
    Since this is a circular list, the idea is to find the max of 2 sets. One which is inclusive of the first house but not the last; and second which is inclusive of the last house but not the first.
    ***********************************/
    int rob(vector<int>& nums) {
        int size = nums.size();
        if (size == 0)
        {
            return 0;
        }
        else if (size == 1)
        {
            return nums[0];
        }
        else if (size == 2)
        {
            return max(nums[0], nums[1]);
        }
        
        return max(solve(nums, 0, size-2), solve(nums, 1, size-1));
}
    
    int solve(vector<int>& nums, int start, int end) {
        vector<int> DP(nums.size());
        
        DP[start] = nums[start];
        
        for (int i = start + 1; i <= end; i++)
        {
            int last = DP[i-1];
            int lastToLast = i < 2 ? 0 : DP[i-2];
            
            if (lastToLast + nums[i] > last)
            {
                DP[i] = lastToLast + nums[i];
            }
            else
            {
                DP[i] = DP[i-1];
            }
        }
        
        return DP[end];
    }
};
