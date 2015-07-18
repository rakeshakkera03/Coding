/*
Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.
*/

struct ListNode* rotateRight(struct ListNode* head, int k) {
    
    if( !head )
    {
        return head;
    }
    int len = 1;
    struct ListNode* temp = head;
    
    while( temp->next != NULL)
    {
        temp = temp->next;
        len++;
    }
    
    k = k % len;
    
    if( k == 0)
    {
        return head;
    }
    temp = head;
    struct ListNode* temp1 = head;
    while( k > 0)
    {
        temp = temp->next;
        k--;
    }
    while( temp->next != NULL )
    {
        temp = temp->next;
        temp1 = temp1->next;
    }
    temp->next = head;
    head = temp1->next;
    temp1->next = NULL;
    
    return head;
}
