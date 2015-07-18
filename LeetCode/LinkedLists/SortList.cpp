/*
Sort a linked list in O(n log n) time using constant space complexity.
*/

class Solution {
public:
    void MergeSortedLL( ListNode* first, ListNode* second, ListNode** result )
    {
        while( first && second )
        {
            if( first->val < second->val )
            {
                (*result) = first;
                first = first->next;
                result = &(*result)->next;
            }
            else
            {
                (*result) = second;
                second = second->next;
                result = &(*result)->next;
            }
        }
        
        if( first )
        {
            *result = first;
        }
        else if ( second )
        {
            *result = second;
        }
        else
        {
            *result = NULL;
        }
    }
    void MergeSortLL( ListNode** head )
    {
        ListNode* result;
        ListNode* first_head, *second_head;
        ListNode* slow = *head, *fast = (*head)->next;
        first_head = *head;
        
        if( !(*head) || !(*head)->next )
        {
            return;
        }
        
        while( fast && fast->next )
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        second_head = slow->next;
        slow->next = NULL;
        
        MergeSortLL( &first_head );
        MergeSortLL( &second_head );
        
        MergeSortedLL( first_head, second_head, &result);
        
        head = &result;
        
    }
    
    ListNode* sortList(ListNode* head) {
        
        if( !head )
        {
            return head;
        }
        
        MergeSortLL( &head );
        
        return head;
    }
};
