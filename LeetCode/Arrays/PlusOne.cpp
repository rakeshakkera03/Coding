/*
Given a non-negative number represented as an array of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.
*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        int carry = 0;
        if( digits.size() == 0 )
        {
            digits.push_back(1);
            return digits;
        }
        
        int x = digits[digits.size() - 1];
        
        x = (x + 1) % 10;
        carry = (digits[digits.size() - 1] + 1) / 10;
        digits[digits.size() - 1] = x;
        for( int i = digits.size() - 2 ; i >=0 ; i-- )
        {
            x = digits[i];
            x = (x + carry) % 10;
            carry = (digits[i] + carry) / 10;
            digits[i] = x;
        }
        
        if( carry > 0)
        {
            digits.insert(digits.begin(), carry);
        }
        
        return digits;
    }
};
