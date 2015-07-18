/*
Reverse a singly linked list.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/* Recursive
struct ListNode* reverseList(struct ListNode* head) {
    
    if( !head || head->next == NULL)
    {
        return head;
    }
    
    struct ListNode* rev = reverseList( head->next );
    
    head->next->next = head;
    head->next = NULL;
    
    return rev;
    
}*/

// Iterative
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev = NULL, *next;
    struct ListNode* current = head;
    while( current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}
