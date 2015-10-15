/*
You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
*/

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        if( !l1 && !l2 )
            return NULL;
        
        if( l1 || l2 )
        {
            if( !l1 )
                return l2;
            else if ( !l2 )
                return l1;
        }
        
        int carry = 0, sum = 0;
        ListNode** result, *temp = NULL;
        ListNode* returnVal = NULL;
        result = &returnVal;
        
        while( l1 || l2 )
        {
            if( l1 && l2 )
            {
                sum = (l1->val + l2->val + carry) % 10 ;
                carry = (l1->val + l2->val + carry ) / 10;
                
                l1->val = sum;
                (*result) = l1;
                
                l1 = l1->next;
                l2 = l2->next;
            }
            else if( l1 && !l2 )
            {
                sum = (l1->val + carry) % 10 ;
                carry = (l1->val + carry ) / 10;
                
                l1->val = sum;
                (*result) = l1;
                
                l1 = l1->next;
            }
            else
            {
                sum = (l2->val + carry) % 10 ;
                carry = (l2->val + carry ) / 10;
                
                l2->val = sum;
                (*result) = l2;
                
                l2 = l2->next;
            }
            
            (*result)->next = NULL;
            result = &(*result)->next;
        }

        
        if( carry > 0 )
        {
            temp = (ListNode*)malloc(sizeof(ListNode));
            temp->val = carry;
            temp->next = NULL;
            (*result) = temp;
        }
        
        return returnVal;
        
    }
