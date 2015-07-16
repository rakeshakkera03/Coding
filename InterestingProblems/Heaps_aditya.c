# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct MaxHeap
{
  int *array;
  int count;    // Number of elements in heap.
  int capacity; // Total capacity in the heap.
} MaxHeap;

void InitializeHeap( MaxHeap **heapPtr, int capacity )
{
  (*heapPtr)->array = ( int * )malloc( sizeof(int) * capacity );
  (*heapPtr)->count = 0;
  (*heapPtr)->capacity = capacity;
}

void InsertIntoHeap( MaxHeap **heapPtr, int element )
{
  if( (*heapPtr)->count == (*heapPtr)->capacity )
  {
    printf("\n Cannot insert. Heap is full. \n");
    return;
  }
  
  (*heapPtr)->array[ (*heapPtr)->count++ ] = element; 
}

void PrintHeap( MaxHeap *heapPtr )
{
  int i = 0;
  printf("\n");
  for( i = 0; i < heapPtr->count; i++ )
  {
    printf("%d ", heapPtr->array[i] );
  }
  printf("\n");
}

void RestoreDown( int position, MaxHeap *heapPtr )
{  
  int value = heapPtr->array[ position ];
  
  while( position <= ( ( heapPtr->count - 1 ) - 1 ) / 2 )
  {
    int child = 2 * position + 1;
    
    if( child < ( heapPtr->count - 1 ) )
    {
      if( heapPtr->array[ child ] < heapPtr->array[ child + 1 ] )
      {
        child = child + 1;
      }
    }
    
    if( value > heapPtr->array[ child ] )
    {
      break;
    }
    
    heapPtr->array[ position ] = heapPtr->array[ child ];
    position = child;    
  }
  
  heapPtr->array[ position ] = value;
}

void Heapify( MaxHeap *heapPtr )
{
  int i = 0;
  for( i = ( ( heapPtr->count - 1 ) - 1 ) / 2; i >=  0; i-- )
  {
    RestoreDown( i, heapPtr );
  }
}

void ReplaceElement( MaxHeap *heapPtr, int replaceWith )
{
      if( 0 == heapPtr->count )
      {
        printf("\n Empty heap. Nothing to replace. \n");
        return;
      }
  
      heapPtr->array[ 0 ] = replaceWith;
      RestoreDown( 0, heapPtr );
}

void DeleteElement( MaxHeap *heapPtr )
{
      if( 0 == heapPtr->count )
      {
        printf("\n Empty heap. Nothing to delete. \n");
        return;
      }
  
      heapPtr->array[ 0 ] = heapPtr->array[ heapPtr->count-- ];
  
      RestoreDown( 0, heapPtr );
}

void AddElement( MaxHeap *heapPtr, int insertElement )
{
  if( heapPtr->count == heapPtr->capacity )
  {
    printf("\n Cannot add element. Heap is full. \n");
    return;
  }
  
  heapPtr->array[ heapPtr->count++ ] = insertElement;
  
  int position = heapPtr->count - 1;
  
  while( position > 0 )
  {
    int parent = (position - 1)/2;
    
    if( heapPtr->array[ parent ] > insertElement )
    {
      break;
    }
    
    heapPtr->array[ position ] = heapPtr->array[ parent ];
    
    position = parent;
  }
  
  heapPtr->array[ position ] = insertElement;
  
}

int main()
{
  MaxHeap *heapPtr = NULL;
  
  heapPtr = ( MaxHeap * )malloc( sizeof( MaxHeap ) );

  InitializeHeap( &heapPtr, 15 );
  
  InsertIntoHeap( &heapPtr, 7);      
  InsertIntoHeap( &heapPtr, 10);      
  InsertIntoHeap( &heapPtr, 25);  
  InsertIntoHeap( &heapPtr, 17);
  InsertIntoHeap( &heapPtr, 23);
  InsertIntoHeap( &heapPtr, 27);
  InsertIntoHeap( &heapPtr, 16);
  InsertIntoHeap( &heapPtr, 19);
  InsertIntoHeap( &heapPtr, 37);
  InsertIntoHeap( &heapPtr, 42);
  InsertIntoHeap( &heapPtr, 4);
  InsertIntoHeap( &heapPtr, 33);
  InsertIntoHeap( &heapPtr, 1);
  InsertIntoHeap( &heapPtr, 5);
  InsertIntoHeap( &heapPtr, 11);
  
  PrintHeap( heapPtr );
  
  Heapify( heapPtr );
  
  PrintHeap( heapPtr );
  
  printf("\n ****** Replacing an element ***** \n");
  
  ReplaceElement( heapPtr, 1 );  
  
  PrintHeap( heapPtr );
  
  printf("\n ****** Deleting an element ***** \n");
  
  DeleteElement( heapPtr );
  DeleteElement( heapPtr );
  
  PrintHeap( heapPtr );
  
  printf("\n ****** Adding an element ***** \n");
  
  AddElement( heapPtr, 42 );
  AddElement( heapPtr, 37 );
  
  PrintHeap( heapPtr );
}
