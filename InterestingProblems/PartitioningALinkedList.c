# include <stdio.h>
# include <stdlib.h>

typedef struct ListNode
{
    unsigned int data;
    struct ListNode *next;
} ListNode;

void InsertIntoList( ListNode **head, unsigned int data )
{
  if( !(*head) )
  {
    (*head) = ( ListNode * )malloc( sizeof(ListNode));
    (*head)->data = data;
    (*head)->next = NULL;
  }
  else
  {
    ListNode *temp = ( ListNode * )malloc( sizeof( ListNode) );
    temp->next = (*head);
    (*head) = temp;
    (*head)->data = data;
  }
}

ListNode* SeparateElements( ListNode *head, unsigned int x )
{
    ListNode *lessStart = NULL;
    ListNode *lessEnd   = NULL;
    ListNode *moreStart = NULL;
    ListNode *moreEnd   = NULL;
  
    while( head )
    {
        if( head->data % 2 != 0 )
        {
          if( !lessStart )
          {
            lessStart = head;
            lessEnd = head;
          }
          else
          {
            lessEnd->next = head;
            lessEnd = lessEnd->next;
          }
        }
        else
        {
          if( !moreStart )
          {
            moreStart = head;
            moreEnd   = head;
          }
          else
          {
            moreEnd->next = head;
            moreEnd = moreEnd->next;
          }
        }
        head = head->next;
    }
  
    lessEnd->next = NULL;
    moreEnd->next = NULL;
  
    lessEnd->next = moreStart;
  
    return lessStart;
  
}

int main()
{
    ListNode *head = NULL;

    InsertIntoList( &head, 7 );  
    InsertIntoList( &head, 3 );
    InsertIntoList( &head, 5 );
    InsertIntoList( &head, 1 );
    InsertIntoList( &head, 2 );
    InsertIntoList( &head, 4 );
  
    head = SeparateElements( head, 3 );
  
    printf("\n");
    while( head )
    {
      printf("\t %d", head->data );
      head = head->next;
    }
  
    return 0;
}
