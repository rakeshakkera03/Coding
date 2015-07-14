/*
Given a singly linked list, determine if it is a palindrome.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* ReverseLL(ListNode* head)
    {
        if( !head || !head->next)
            return head;
        
        ListNode* rev = ReverseLL(head->next);
        
        head->next->next = head;
        head->next = NULL;
        
        return rev;
        
    }
    
    bool isPalindrome(ListNode* head) {
        
        if( !head || !head->next )
            return true;
            
        ListNode *slow, *fast;
        ListNode* second_head;
        slow = head;
        fast = head->next;
        
        while( fast && fast->next )
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        second_head = slow->next;
        slow->next = NULL;
        
        second_head = ReverseLL(second_head);
        
        ListNode* temp1 = head, *temp2 = second_head;
        
        
        
        while( temp1 && temp2 )
        {
            if( temp1->val != temp2->val )
                break;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        
        // the following condition is required if there are odd number of nodes..
        if( (temp1 == NULL && temp2 == NULL) || (temp1->next == NULL && temp2 == NULL) )
            return true;
        
        return false;
        
    }
};
