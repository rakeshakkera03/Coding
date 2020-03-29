/*
Problem Statement
A sequence of numbers is called a zig-zag sequence if the differences between successive numbers strictly alternate between positive and negative. The first difference (if one exists) may be either positive or negative. A sequence with fewer than two elements is trivially a zig-zag sequence.

For example, 1,7,4,9,2,5 is a zig-zag sequence because the differences (6,-3,5,-7,3) are alternately positive and negative. In contrast, 1,4,7,2,5 and 1,7,4,5,5 are not zig-zag sequences, the first because its first two differences are positive and the second because its last difference is zero.

Given a sequence of integers, sequence, return the length of the longest subsequence of sequence that is a zig-zag sequence. A subsequence is obtained by deleting some number of elements (possibly zero) from the original sequence, leaving the remaining elements in their original order.
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class ZigZag {
	public:
	int longestZigZag(vector<int> s)
	{
        if (s.size() == 0)
            return 0;
        
		vector<int> countArr(s.size(), 1);
        int ordering = 0;
        
        for (int i = 1; i < s.size(); i++ )
        {
            if (ordering == 0)
            {
                if (s[i] == s[i-1])
                {
                    continue;
                }
                else if (s[i] > s[i-1])
                {
                    countArr[i] = countArr[i-1] + 1;
                    ordering = 1;
                }
                else
                {
                    countArr[i] = countArr[i-1] + 1;
                    ordering = -1;
                }
            }
            else if (s[i] == s[i - 1] || (s[i] > s[i-1] && ordering > 0) || (s[i] < s[i-1] && ordering < 0))
            {
                countArr[i] = countArr[i-1];
            }
            else //if ((s[i] > s[i-1] && ordering < 0) || (s[i] < s[i-1] && ordering > 0)
            {
                countArr[i] = countArr[i-1] + 1;
                ordering = ordering * -1;
            }
        }
        
        return countArr[s.size() - 1];
        
	}
};
