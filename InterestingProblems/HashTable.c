# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct ListNode
{
  unsigned int key;
  struct ListNode *prev;
  struct ListNode *next;  
} ListNode;

typedef struct HashBinNode
{
  struct ListNode *first;
  struct ListNode *head;
  struct ListNode *tail;  
} HashBinNode;

void PrintContentInHashBins( HashBinNode** hashBinPtr, unsigned int numOfBins )
{
  for( int i = 0; i < numOfBins; i++ )
  {
    printf("\n Bin %d", i + 1 );
    ListNode* print = hashBinPtr[ i ]->head;
    while( print )
    {
      printf("\t %d", print->key );
      print = print->next;
    }
  }
}

void InsertIntoHash( HashBinNode** hashBinPtr, unsigned int key, unsigned int numOfBins )
{
    unsigned int insertIntoBin = key % numOfBins;
  
    // 1st element in the current hash bin.
    if( !hashBinPtr[ insertIntoBin ]->first )
    {
      ListNode *temp = ( ListNode * )malloc(sizeof(ListNode));
      temp->key  = key;
      temp->prev = NULL;
      temp->next = NULL;
      hashBinPtr[ insertIntoBin ]->first = temp;      
      hashBinPtr[ insertIntoBin ]->head  = temp;
      hashBinPtr[ insertIntoBin ]->tail  = temp;
    }
    else
    {
      ListNode *temp = ( ListNode * )malloc(sizeof(ListNode));      
      temp->key  = key;
      temp->prev = hashBinPtr[ insertIntoBin ]->tail;
      temp->next = NULL;
      hashBinPtr[ insertIntoBin ]->tail->next = temp;
      hashBinPtr[ insertIntoBin ]->tail = temp;
    }
}

void DeleteFromHash( HashBinNode** hashBinPtr, unsigned int numOfBins, unsigned int key )
{
    unsigned int bin = key % numOfBins;
      
    if( !hashBinPtr[ bin ]->first )
    {
        printf("\n Element %d does not exist \n", key);
    }
    else 
    {
      
      if( hashBinPtr[ bin ]->head->key == key )
      {
          if( hashBinPtr[ bin ]->head == hashBinPtr[ bin ]->tail )
          {
              ListNode* temp = hashBinPtr[ bin ]->head;
              hashBinPtr[ bin ]->first = NULL;
              hashBinPtr[ bin ]->head  = NULL;
              hashBinPtr[ bin ]->tail  = NULL;
              free( temp );
          }
          else 
          {  
              ListNode* temp = hashBinPtr[ bin ]->head;
              hashBinPtr[ bin ]->head = temp->next;
              temp->next->prev = NULL;
              temp->next = NULL;
              hashBinPtr[ bin ]->first = hashBinPtr[ bin ]->head;
              free(temp);
          }
      }
      else if ( hashBinPtr[ bin ]->tail->key == key )
      {
          ListNode* temp = hashBinPtr[ bin ]->tail;
          hashBinPtr[ bin ]->tail = temp->prev;
          temp->prev->next = NULL;
          free( temp );
      }
      else
      {
          ListNode* temp = hashBinPtr[ bin ]->head;
          while( temp )
          {
              if( temp->key == key )
              {
                  temp->prev->next = temp->next;
                  temp->next->prev = temp->prev;
                  free( temp );
                  return;
              }
              temp = temp->next;
          }
          printf("\n Element %d does not exist \n", key);
      }
    }
}

int main()
{
    int numOfBins = 10;
    HashBinNode* hashBinPtr[ numOfBins ];
    
    for( int i = 0 ; i < numOfBins ; i++ )
    {
            hashBinPtr[ i ] = (HashBinNode*)malloc(sizeof(HashBinNode));
              
            hashBinPtr[ i ]->first = NULL;
            hashBinPtr[ i ]->head  = NULL;
            hashBinPtr[ i ]->tail  = NULL;
    }
  
    for( int i = 1; i <= 100; i++ )
    {
        InsertIntoHash( hashBinPtr, i, numOfBins );
    }
  
    PrintContentInHashBins( hashBinPtr, numOfBins );
  
    DeleteFromHash( hashBinPtr, numOfBins, 10 );
    DeleteFromHash( hashBinPtr, numOfBins, 20 );
    DeleteFromHash( hashBinPtr, numOfBins, 30 );
    DeleteFromHash( hashBinPtr, numOfBins, 40 );
    DeleteFromHash( hashBinPtr, numOfBins, 50 );
    DeleteFromHash( hashBinPtr, numOfBins, 60 );
    DeleteFromHash( hashBinPtr, numOfBins, 70 );
    DeleteFromHash( hashBinPtr, numOfBins, 80 );
    DeleteFromHash( hashBinPtr, numOfBins, 90 );
    DeleteFromHash( hashBinPtr, numOfBins, 100 );
  
    PrintContentInHashBins( hashBinPtr, numOfBins );
    
    return 0;
}
