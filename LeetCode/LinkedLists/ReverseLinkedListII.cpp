/*
Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseLL( ListNode* head )
    {
        if( !head || !head->next )
            return head;
            
        ListNode* ret = reverseLL( head->next );
        
        head->next->next = head;
        head->next = NULL;
    
        return ret;
    }
    
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        
        if( !head || !head->next )
            return head;
        
        ListNode *start, *end, *temp;
        
        start = head;
        end = head;
        
        // end pointer would point to nth node and start pointer would point to node before the position m.
        // when m == 1, the LL should be rotated from the head itself, so we handle that case below where m == 1
        while( n > 1 )
        {
            end = end->next;
            n--;
        }
        temp = end->next;
        end->next = NULL;
        
        if( m == 1 )
        {
            head = reverseLL( head );
        }
        else
        {
            while( m > 2 )
            {
                start = start->next;
                m--;
            }
            
            start->next = reverseLL( start->next );
        }
        
        while( start->next != NULL )
        {
            start = start->next;
        }
        start->next = temp;
        
        return head;
        
    }
};
