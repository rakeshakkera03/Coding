/*
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
*/

class Solution {
public:
    int FindNextHigherNumber( vector<int>& nums, int index)
    {
        int higher = INT_MAX;
        int higher_index = -1;
        
        for( int i = index; i <= nums.size() - 1; i++)
        {
            if( nums[i] > nums[index - 1] && nums[i] < higher)
            {
                higher = nums[i];
                higher_index = i;
            }
        }
        return higher_index;
        
    }
    void nextPermutation(vector<int>& nums) {
        
        if( nums.size() == 0 )
            return;
        
        // Find an element that need to be manipulated to get our desired output.
        // This element is the first element that is decreasing when traversed from the right side of the array.
        // If no such element is found, we just sort the entire input set and return.
        
        // Start from the last but one element to the right of the array.
        int i = nums.size() - 1;
        while( i > 0)
        {
            if( i > 0 && nums[i - 1] < nums[i])
            {
                break;
            }
            i--;
        }
        
        // No element to replace has been found. We just need to sort the entire input set and return.
        if( i == 0)
        {
            sort(nums.begin(), nums.end());
            return;
        }
        else
        {
            // At this point, 'i - 1' is referring to the index of the element that can be swapped with the next highest number to the right of it.
        // We can achieve this by sorting all the elements to the right of the index 'i - 1', and finding the next higher element than at index 'i - 1' and swapping it with element at index 'i - 1'
            sort(nums.begin() + i, nums.end());
            int higher_index = FindNextHigherNumber(nums, i);
            
            swap( nums[i-1], nums[higher_index] );
            return;
        }
        
    }
};
