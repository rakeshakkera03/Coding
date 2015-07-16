#include <stdio.h>
#include <stdlib.h>


typedef struct ListNode {
    int data;
    struct ListNode* next;
} ListNode;

void InsertIntoList(ListNode** head, int data)
{
    (*head) = (ListNode*)malloc( sizeof(ListNode));
    (*head)->next = NULL;
    (*head)->data = data;
}

void PrintList(ListNode* head)
{
    printf("\n List Elements:");
    while( head )
    {
        printf("\t %d", head->data);
        head = head->next;
    }
    
    printf("\n");
}

ListNode* FindMidNode(ListNode* head)
{
    ListNode *slow = head;
    ListNode *fast = head->next;
  
    while( slow && fast && fast->next )
    {
        slow = slow->next;
        fast = fast->next->next;
    }
  
    return slow;
}

void MergeList( ListNode *one, ListNode *two, ListNode **result)
{
      while( one && two )
      {
          if(one->data < two->data)
          {
              *result = one;
              one = one->next;
          }
          else
          {
            *result = two;
            two = two->next;
          }
          
          result = &((*result)->next);
      }
  
      if( one && !two )
      {
          (*result) = one;
      }
  
      if( !one && two )
      {
          (*result) = two;
      }
}


void MergeSortList(ListNode** head)
{
    if( !(*head)  || !(*head)->next)
    {
        return;
    }
    
    ListNode *mid = FindMidNode(*head);

    ListNode *temp = mid->next;
  
    mid->next = NULL;
  
    MergeSortList( head );
    MergeSortList( &temp );
  
    ListNode* result;
  
    MergeList( *head, temp, &result );
  
    *head = result;
}

ListNode* Swap2Nodes(ListNode *root)
{
    int count = 0;
  
    if( !root)
      return NULL;
  
    ListNode* temp = root;
  
    while( temp->next != NULL )
    {
        count++;
        
        ListNode* temp1;
        ListNode* prev;

        if(count == 1)
        prev = temp; 
      
        temp1 = temp->next;
      
        temp->next = temp1->next;
        temp1->next = temp;
        
        if(count == 1) 
        {
          root = temp1;
        }
        else
        {
            prev->next = temp1;
            prev = temp;
        }
      
        temp = temp->next;
    }
  
    return root;

}

void ReverseList( ListNode** head )
{      
    ListNode *first;
    ListNode *rest;
  
    if ( *head == NULL )
    {
        return;
    }
  
    first = *head;
    rest = first->next;
  
    if( !rest )
    {
        return;
    }
  
    ReverseList( &rest );
  
    first->next->next = first;
    first->next = NULL;
  
    *head = rest;
      
}


void SwapKNode(ListNode **head, int k)
{
    ListNode *temp = *head;
    int i = 1;
    for( i = 1; i < k ; i++ )
    {
        if( !temp )
            break;
        temp = temp->next;
    }
  
    if( i != k )
    {
        return;
    }
    
    ListNode* temp1 = temp->next;
    temp->next = NULL;
  
    ReverseList( head );
    
    temp = *head;
  
    while( temp->next )
    {
        temp = temp->next;
    }
    
    SwapKNode( &temp1, k );
  
    temp->next = temp1;
  
    return;
  
}

int main() {
  ListNode* head;
  
  InsertIntoList(&head, 4);
  InsertIntoList(&head->next, 7);
  InsertIntoList(&head->next->next, 1);
  InsertIntoList(&head->next->next->next, 14);
  InsertIntoList(&head->next->next->next->next, 5);
  InsertIntoList(&head->next->next->next->next->next, 8);
  InsertIntoList(&head->next->next->next->next->next->next, 6);
  
  PrintList(head);
  
  MergeSortList(&head);
  
  PrintList(head);
  
  head = Swap2Nodes(head);
  
  PrintList(head);
  
  SwapKNode(&head , 3);
  
  PrintList(head);
  return 0;
}


