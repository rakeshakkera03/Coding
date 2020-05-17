class Solution {
public:
    int rob(vector<int>& nums) {
        // Solution is DP. Solve the previous sub-problems to evaluate the current sub-problem. Explanation here : https://www.geeksforgeeks.org/find-maximum-possible-stolen-value-houses/
        if (nums.size() == 0)
        {
            return 0;
        }
        else if (nums.size() == 1)
        {
            return nums[0];
        }
        else if (nums.size() == 2)
        {
            return max(nums[0], nums[1]);
        }
        
        vector<int> dp(nums.size());
        
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        
        for (int i = 2; i < nums.size(); i++)
        {
            dp[i] = max(dp[i - 2] + nums[i], dp[i-1]);
        }
        
        return dp[nums.size() - 1];
    }
};
