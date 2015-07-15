/*
Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
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
    ListNode* deleteDuplicates(ListNode* head) {
        
        if( !head )
            return head;
        
        ListNode* temp = head;
        
        while( temp->next )
        {
            if( temp->next->val == temp->val )
            {
                ListNode* temp1 = temp->next;
                temp->next = temp1->next;
                free(temp1);
            }
            else
            {
                temp = temp->next;
            }
            
        }
        
        return head;
    }
};
