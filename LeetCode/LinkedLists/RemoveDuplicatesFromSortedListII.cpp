/*
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.
*/

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        
        ListNode* temp = head;
        ListNode* prev;
        //bool isDuplicate = false;
        
        if( !head || !head->next )
            return head;
        
        // You need to have a pointer to the previous node to delete the current node
        // Except for the head node..
        
        while( head && head->next && head->next->val == head->val)
        {
            while( head && head->next && head->next->val == head->val )
            {
                temp = head;
                head = head->next;
                free(temp);
            }
            temp = head;
            head = head->next;
            free (temp);
        }
        
        if( head )
        {
            cout << head->val << endl;
            prev = head;
        }
        else
            return head;
        
        temp = prev->next;
        
        while( 1 )
        {
            if( temp && temp->next )
            {
                if(temp->next->val == temp->val)
                {
                    cout << "Duplicate found: " << prev->val << " " << temp->val <<endl;
                    while( temp && temp->next && temp->next->val == temp->val )
                    {
                        cout << "In While: " << temp->val << " " << temp->next->val <<endl;
                        ListNode* temp2 = temp->next;
            
                        temp->next = temp2->next;
            
                        free(temp2);
            
                    }
                    prev->next = temp->next;
                    free(temp);
                }
                else
                {
                    cout << "In Else: " << prev->val << " " << temp->val <<endl;
                    prev = temp;
                    temp = temp->next;
                }
            }
            else
            {
                break;
            }
            
        }
        
        return head;
        
    }
};
