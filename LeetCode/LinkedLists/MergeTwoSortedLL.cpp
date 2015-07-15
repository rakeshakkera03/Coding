/*
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

	//Here we use double pointers to solve this..
        
        ListNode** result, **final_result = result;
        ListNode *first = l1, *second = l2;
        
        while( first && second )
        {
            if( first->val < second->val )
            {
                *result = first;
                first = first->next;
                result = &(*result)->next;
            }
            else 
            {
                *result = second;
                second = second->next;
                result = &(*result)->next;
            }
        }
        
        if( first )
        {
            *result = first;
        }
        else if ( second )
        {
            *result = second;
        }
        else
        {
            *result = NULL;
        }
        
        return *final_result;
        
    }
};
