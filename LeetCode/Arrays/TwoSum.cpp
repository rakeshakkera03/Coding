/*
Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       
       map<int, int> m;
       vector<int> result;
       
       for( int i = 0 ; i < nums.size(); i++ )
       {
           if( m.find(nums[i]) == m.end() ) 
           {
               if( m.find(target - nums[i]) != m.end() ) 
               {
                   result.push_back(m[target - nums[i]] + 1);
                   result.push_back(i + 1);
                   return result;
               }
               else
               {
                    m[nums[i]] = i;
               }
           }
           else 
           {	
	       // Handling duplicates..
               // sum of same element contributes to the target .. input [ 0, 4, 3, 0] ... output is [1, 4]
               if( m.find(target - nums[i]) != m.end() ) 
               {
                   result.push_back(m[target - nums[i]] + 1);
                   result.push_back(i + 1);
                   return result;
               }
           }
           
       }
       
       return result;
    }
};
