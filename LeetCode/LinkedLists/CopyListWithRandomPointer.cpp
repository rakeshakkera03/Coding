/*
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.
*/

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        
        if( !head )
        {
            return NULL;
        }
        
        RandomListNode* randomHead;
        RandomListNode* temp = head;
        RandomListNode* temp2;
        
        while( temp )
        {
            RandomListNode* newNode = (RandomListNode*)malloc(sizeof(RandomListNode));
            newNode->label = temp->label;
            newNode->next = temp->next;
            newNode->random = NULL;
            temp->next = newNode;
            
            temp = temp->next->next;
        }
        
        temp = head;
        
        while( temp )
        {
            // One of the test cases failed since I did not check to see if "temp->random" exists
            if( temp->random )
                temp->next->random = temp->random->next;
            temp = temp->next->next;
        }
        
        temp = head;
        randomHead = head->next;
        temp2 = randomHead;
        
        while( temp )
        {
            temp->next = temp2->next;
            
            if( temp->next == NULL )
            {
                temp2->next = NULL;
            }
            else
            {
                temp2->next = temp2->next->next;
            }
            temp = temp->next;
            temp2 = temp2->next;
        }
        
        return randomHead;
        
    }
};
