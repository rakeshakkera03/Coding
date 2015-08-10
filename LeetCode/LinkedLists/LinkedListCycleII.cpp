/*
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Follow up:
Can you solve it without using extra space?
*/

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        if( !head )
            return head;
        
        ListNode *slow = head , *fast = head;
        bool cycle_exists = false;
        
        while( slow && fast && fast->next )
        {
            slow = slow->next;
            fast = fast->next->next;
            
            if( slow == fast )
            {
                cycle_exists = true;
                break;
            }
        }
        
        if( !cycle_exists )
        {
            return NULL;
        }
        else
        {
            slow = head;
            
            while( slow && fast )
            {
                // Check this condition first since the first node may be the start of the cycle..
                if( slow == fast )
                    return slow;
                    
                slow = slow->next;
                fast = fast->next;
                
            }
        }
        
        
        
        
    }
};
