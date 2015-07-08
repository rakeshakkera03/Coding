/*
Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array nums = [1,1,1,2,2,3],

Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. It doesn't matter what you leave beyond the new length.
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        if( nums.size() <= 2)
            return nums.size();
        int insert_pos = 0; 
        int one = 0, two = 0;
        
        while(two < nums.size())
        {
            //Both elements are same and number of duplicates so far of this element is < 2
            if( nums[one] == nums[two] && (two - one) < 2)
            {
                nums[insert_pos++] = nums[one];
                two++;
            }
            // New element is encountered in the array, so just insert the new element and reset one
            else if( nums[two] != nums[one] )
            {
                nums[insert_pos++] = nums[two];
                one = two;
                two++;
            }
            // More than two duplicates of the current element, so just increment two.
            else if( nums[one] == nums[two] && (two - one) >= 2)
            {
                two++;
            }
        }
        
        return insert_pos;
        
    }
};
