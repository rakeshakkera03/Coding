/*
Write a program to find the node at which the intersection of two singly linked lists begins.


For example, the following two linked lists:

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗            
B:     b1 → b2 → b3
begin to intersect at node c1.
*/

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        int aLength = 1, bLength = 1;
        ListNode* aTemp = headA;
        ListNode* bTemp = headB;
        
        if( aTemp == NULL || bTemp == NULL)
            return NULL;
        
        if( aTemp == bTemp )
            return aTemp;
            
        while( aTemp->next )
        {
            aLength++;
            aTemp = aTemp->next;
        }
        
        while( bTemp->next )
        {
            bLength++;
            bTemp = bTemp->next;
        }
        
        aTemp = headA; bTemp = headB;
        
        int diff = 0;
        if( aLength > bLength )
        {
            diff = aLength - bLength;
            while( diff != 0 )
            {
                aTemp = aTemp->next;
                diff--;
            }
            
        }
        else if ( aLength < bLength )
        {
            diff = bLength - aLength;
            while( diff != 0 )
            {
                bTemp = bTemp->next;
                diff--;
            }
        }
        
        while( aTemp != NULL && bTemp != NULL )
        {
            if( aTemp == bTemp)
                return aTemp;
                
            aTemp = aTemp->next;
            bTemp = bTemp->next;
            
        }
        
        return NULL;
        
    }
};
