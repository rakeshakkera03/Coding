/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
ListNode* plusOne(ListNode* head) {
    int carry = calculatePlusOne(head);
    ListNode* newHead = new ListNode();
    if (carry > 0)
    {
        (newHead)->val = carry;
        (newHead)->next = head;
        
        return newHead;
    }
    
    return head;
}

int calculatePlusOne(ListNode* head) {
    if (!head)
    {
        return 1;
    }
    
    int carry = calculatePlusOne(head->next);
    
    return calculateNodePlusCarry(head, carry);
}

int calculateNodePlusCarry(ListNode* node, int carry)
{
    int sum = node->val + carry;
    if (sum > 9) {
    int carry = sum / 10;
    node->val = sum % 10;
    } else
    {
    node->val = sum;
    carry = 0;
    }
    
    return carry;
}
    
};
