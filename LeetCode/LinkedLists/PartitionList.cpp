/*
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5
*/

ListNode* partition(ListNode* head, int x) {
        
        if( !head )
            return head;
            
        ListNode* first = NULL, *second = NULL;
        ListNode** result1, **result2;
        result1 = &first;
        result2 = &second;
        
        while( head )
        {
            if( head->val < x )
            {
                (*result1) = head;
                head = head->next;
                (*result1)->next = NULL;
                result1 = &(*result1)->next;
            }
            else
            {
                (*result2) = head;
                head = head->next;
                (*result2)->next = NULL;
                result2 = &(*result2)->next;
            }
        }
        
        // Here it should be "*result1 = second" and not "result = &second". Analyze why!
        
        *result1 = second;
        
        return first;
        
    }
