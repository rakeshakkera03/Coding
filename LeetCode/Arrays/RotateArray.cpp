/*
Rotate an array of n elements to the right by k steps.

For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].
*/
class Solution {
public:
    void reverseVector( vector<int>& nums, int start, int end)
    {
        int temp = 0;
        while(start <= end)
        {
            temp = nums[start];
            nums[start] = nums[ end ];
            nums[end] = temp;
            start++;
            end--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        
        if( nums.size() == 0 || nums.size() == 1)
            return;
        
        k = k % nums.size();
        
        reverseVector(nums, nums.size() - k, nums.size() - 1);
        reverseVector(nums, 0, nums.size() - k - 1);
        reverseVector(nums, 0, nums.size() - 1);
        
        return;
        
        
    }
};
