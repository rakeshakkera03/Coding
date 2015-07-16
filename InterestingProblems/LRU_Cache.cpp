# include <iostream>
# include <map>

using namespace std;

struct ListNode
{
    unsigned int pageNumber;
    struct ListNode *prev;
    struct ListNode *next;
};

map< unsigned int, ListNode* > hashMap;

unsigned int NumOfAssignedPages;
unsigned int NumOfFilledPages;

ListNode *head, *tail;

void InitializeResources( int capacity )
{
    NumOfFilledPages   = 0;
    NumOfAssignedPages = capacity;
    head = NULL;
    tail = NULL;
}

bool IsCacheEmpty()
{
    return (0 == NumOfFilledPages) ;
}

bool IsCacheFull()
{
    return (NumOfFilledPages == NumOfAssignedPages); 
}

void SetPage( unsigned int pageNumber )
{
    if( IsCacheEmpty() )
    {
      // Create first node and update head and tail pointers.
      ListNode *createNode = (ListNode *)malloc(sizeof(ListNode));
      createNode->pageNumber = pageNumber;
      createNode->prev = NULL;
      createNode->next = NULL;      
      
      head = createNode;
      tail = createNode;
      
      // Update hashTable with this information.
      hashMap[ pageNumber ] = createNode;
      
      NumOfFilledPages++;
    }
    else
    {
      // (1) Check if the page already exists in the hash table and is not already node.
      if( ( hashMap.find( pageNumber ) != hashMap.end() ) && ( hashMap[ pageNumber ] != head ) )
      {
          ListNode *temp = hashMap[ pageNumber ];
          
          temp->prev->next = temp->next;
        
          if( temp != tail )
          {
              temp->next->prev = temp->prev;
          }
          else
          {
              tail = tail->prev;
          }
        
          temp->next = NULL;
          temp->prev = NULL;
        
          temp->next = head;
          head->prev = temp;
          head = temp;
        
          return;
      }
      
      // (2) Page doesn't exist in the hash table.
      if( IsCacheFull() )
      {
        ListNode* temp = tail;
        tail = tail->prev;
        tail->next = NULL;        
        temp->prev = NULL;
        
        unsigned int removePage = temp->pageNumber;
        
        // Remove the last ( tail ) node from the hashMap.
        hashMap.erase( removePage );
        
        free( temp );        
        NumOfFilledPages--;        
      }
      
      ListNode *createNode = (ListNode *)malloc(sizeof(ListNode));
      createNode->pageNumber = pageNumber;
      
      
      createNode->prev = NULL;
      head->prev = createNode;
      createNode->next = head;
      head = createNode;
      
      // Update hashTable with this information.
      hashMap[ pageNumber ] = createNode;
      NumOfFilledPages++;
    }
}

int main()
{
    int capacity = 5;
    InitializeResources( capacity );
  
    SetPage( 1 );
    SetPage( 2 );
    SetPage( 3 );
    SetPage( 4 );
    SetPage( 5 );
    SetPage( 6 );
    SetPage( 5 );
    SetPage( 1 );
  
    ListNode *print = head;
    while( print )
    {
        cout << " " << print->pageNumber;
        print = print->next;
    }
  
    return 0;
}
