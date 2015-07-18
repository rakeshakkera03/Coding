/*
Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
*/

struct ListNode* Reverse(struct ListNode** head)
{
    struct ListNode* temp = (*head)->next;
    temp->next = (*head);
    (*head) = temp;
    return temp->next;
}

struct ListNode* swapPairs(struct ListNode* head) {
    
    if(!head || head->next == NULL)
    {
        return head;
    }
    
    struct ListNode* rest;
    struct ListNode* last;
    
    rest = head->next->next;
    
    last = Reverse(&head);
    
    last->next = swapPairs(rest);
    
    return head;
    
}
