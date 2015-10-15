/*
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5
*/

ListNode* reverseList( ListNode** head )
    {
        if( !(*head) || !(*head)->next )
        {
            return *head;
        }
        
        ListNode* rev = reverseList( &(*head)->next );
        
        (*head)->next->next = (*head);
        (*head)->next = NULL;
        
        return (rev);
    }
    
    ListNode* reverseKNodesInGroups( ListNode** head, int k )
    {
        if( !(*head) )
            return *head;
        
        int count = 1;
        ListNode* temp, *rest;
        
        temp = *head;
        
        while( temp->next && count < k )
        {
            temp = temp->next;
            count++;
        }
        
        if( count < k )
            return *head;
        else
        {
            rest = temp->next;
            temp->next = NULL;
            *head = reverseList( head );
            
            rest = reverseKNodesInGroups( &rest, k );
            
            temp = *head;
            
            while( temp->next )
            {
                temp = temp->next;
            }
            temp->next = rest;
            
            return *head;
        }
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        int count = 0;
        
        if( !head || k <= 1 )
            return head;
        
        ListNode* temp = head;
        while( temp )
        {
            temp = temp->next; 
            count++;
        }
        
        if( count / k == 0 )
            return head;
        
        return reverseKNodesInGroups( &head, k );
        
    }
