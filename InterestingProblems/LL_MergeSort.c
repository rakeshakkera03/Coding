# include <stdio.h>
# include <stdlib.h>

typedef struct ListNode
{
    struct ListNode* next;
    int data;
} ListNode;

void InsertIntoList( ListNode **head, int data )
{
  (*head) = ( ListNode * )malloc( sizeof( ListNode ));
  (*head)->next = NULL;
  (*head)->data = data;
}

void PrintList( ListNode *head )
{
  printf("\n List Elements: ");
  while( head )
  {
    printf("\t %d", head->data);
    head = head->next;               
  }  
  printf("\n");
}

void MergeLists( ListNode *one, ListNode *two, ListNode **result )
{    
  if( !one && !two )
  {
    return;
  }
  
  while( one && two )
  {
    if( one->data < two->data )
    {
      (*result) = one;
      one = one->next;
    }
    else
    {
      (*result) = two;
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

ListNode* FindMidElem( ListNode *head )
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

void MergeSortList( ListNode **head )
{
  if( ! (*head) || !(*head)->next )
  {
    return;
  }
  
  ListNode *mid = FindMidElem( *head );
  ListNode *temp = mid->next;
  mid->next = NULL;
  
  MergeSortList( head  );
  MergeSortList( &temp );
  
  ListNode *result = NULL;
  MergeLists( *head, temp, &result );
  
  *head = result;
}

int main() 
{
  ListNode *head = NULL;
  
  InsertIntoList( &head, 4 );
  InsertIntoList( &(head->next), 12 );
  InsertIntoList( &(head->next->next), 7 );
  InsertIntoList( &head->next->next->next, 3 );
  InsertIntoList( &head->next->next->next->next, 14 );
  InsertIntoList( &head->next->next->next->next->next, 6 );
  
  PrintList( head );
  
  MergeSortList( &head );
  
  PrintList( head );
  
  return 0;
}


