/*
Remove all elements from a linked list of integers that have value val.

Example
Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
Return: 1 --> 2 --> 3 --> 4 --> 5
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    
    struct ListNode* temp = head;
    
    // This following condition is not necessary since u would not enter the while loop if head == NULL
    // Notice this in the interview and remove it.
    if( !head )
        return head;
    
    while ( temp )
    {
        if( temp == head && temp->val == val)
        {
            head = head->next;
            free(temp);
            temp = head;
        }
        else if ( temp->next && temp->next->val == val )
        {
            struct ListNode* temp2 = temp->next;
            temp->next = temp2->next;
            free(temp2);
        }
        else
        {
            temp = temp->next;
        }
        
    }    
    
    return head;
    
    
    
}
