/*
Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    
    if( !head )
        return head;
    
    struct ListNode* temp = head;
    
    // The idea is to get temp1 to point to the node before the node to be deleted.. i.e point to node 3 in example
    // above. 
    while( temp && n > 0)
    {
        temp = temp->next;
        n--;
    }
    
    // The following condition specifies the condition where the node to be deleted is the first node, so temp1 cannot point
    // to a node before it.. So check to see if the node to be deleted is the first node and just move the head pointer to
    // next and delete the current head..
    if( !temp && n == 0 )
    {
        temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    
    struct ListNode* temp1 = head;
    while( temp->next != NULL )
    {
        temp = temp->next;
        temp1 = temp1->next;
    }
    
    //reusing temp pointer to delete the node..
    temp = temp1->next;
    temp1->next = temp->next;
    free(temp);
    return head;
    
}
