/*
Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You must do this in-place without altering the nodes' values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.
*/

class Solution {
public:
    ListNode* FindMid( ListNode* head )
    {
        ListNode *slow = head, *fast = head->next;
        
        while( fast && fast->next )
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }

    ListNode* ReverseLL( ListNode* head )
    {
        if( !head || !head->next )
        {
            return head;
        }
        
        ListNode* rev = ReverseLL( head->next );
        
        head->next->next = head;
        head->next = NULL;
        
        return rev;
    }
    
    ListNode* Reorder( ListNode* head, ListNode* second_head )
    {
        ListNode* result;
        ListNode** result_ptr = &result;
        int flag = 0;
        while( head && second_head )
        {
            if( flag == 0 )
            {
                (*result_ptr) =head;
                head = head->next;
                flag = 1;
            }
            else 
            {
                (*result_ptr) = second_head;
                second_head = second_head->next;
                flag = 0;
            }
            (*result_ptr)->next = NULL;
            (result_ptr) = &(*result_ptr)->next;
        }
        
        if( head )
        {
            *result_ptr = head;
        }
        else if ( second_head )
        {
            *result_ptr = second_head;
        }
        
        return result;
        
    }
    void reorderList(ListNode* head) {
        
        if( !head || !head->next )
        {
            return;
        }
        
        ListNode* mid = FindMid( head );
        ListNode* second_head = mid->next;
        mid->next = NULL;
        
        second_head = ReverseLL(second_head);
        
        head = Reorder( head, second_head );
    }
};
