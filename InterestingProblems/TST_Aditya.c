# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

typedef struct TST
{
  char valueAtNode;
  bool isEndOfStr;
  struct TST *left;
  struct TST *right;
  struct TST *equal;
} TST;

void InsertIntoTST( TST **tstNode, char *word )
{
  if( *word == '\0' )
  {
    return;
  }
  
  if( !(*tstNode) )
  {
      (*tstNode) = (TST *)malloc(sizeof(TST));
      (*tstNode)->valueAtNode = *word;
      (*tstNode)->isEndOfStr = false;
      (*tstNode)->left   = NULL;
      (*tstNode)->right  = NULL;
      (*tstNode)->equal  = NULL;
    
      if( *(word + 1) == '\0' )
      {
        (*tstNode)->isEndOfStr = true;
      }    
      InsertIntoTST( &(*tstNode)->equal, word + 1 );
  }
  else
  {
      if( (*tstNode)->valueAtNode == *word )
      {
        if( *(word + 1) == '\0' )
        {
          (*tstNode)->isEndOfStr = true;
          return;
        }
        InsertIntoTST( &(*tstNode)->equal, word + 1 );        
      }
      else if( (*tstNode)->valueAtNode < *word )
      {
        InsertIntoTST( &(*tstNode)->right, word );
      }
      else
      {
        InsertIntoTST( &(*tstNode)->left, word );
      }
  }
}


bool SearchInTST( TST* tstNode, char *word)
{
    if( !tstNode )
    {
        return false;
    }
  
    if( *word == '\0' )
        return true;
  
    if( *word == tstNode->valueAtNode )
    {
        if ( *(word + 1) == '\0' )
        {
            return tstNode->isEndOfStr;
        }
      
        return SearchInTST( tstNode->equal, word + 1 );
    }
    else if( *word < tstNode->valueAtNode )
    {      
        return SearchInTST( tstNode->left, word );
    }
    else if( *word > tstNode->valueAtNode )
    {      
        return SearchInTST( tstNode->right, word );
    }
    return false;
}

void PrintDictionary( TST *tstPtr, char path[], int level )
{
  if( tstPtr )
  {
    PrintDictionary( tstPtr->left, path, level );
    path[ level ] = tstPtr->valueAtNode;
    if( tstPtr->isEndOfStr )
    {
      path[ level + 1 ] = '\0';
      printf("\n %s \n", path );
    }
    PrintDictionary( tstPtr->equal, path, level + 1 );
    PrintDictionary( tstPtr->right, path, level );
  }
}


int main()
{
    TST *tstNode = NULL;
  
    InsertIntoTST( &tstNode, "boats");
    InsertIntoTST( &tstNode, "cat");
    InsertIntoTST( &tstNode, "at");
    InsertIntoTST( &tstNode, "apple");
    InsertIntoTST( &tstNode, "boar");
    InsertIntoTST( &tstNode, "zebra");
    InsertIntoTST( &tstNode, "boat");
    InsertIntoTST( &tstNode, "bats");
    InsertIntoTST( &tstNode, "yellow");
  
    char *word = "bats";
    bool ret = SearchInTST( tstNode, word);
  
    if ( ret )
        printf("\nWord found - %s\n", word);
    else
        printf("\nWord not found - %s\n", word);
  
    char arr[10];
    PrintDictionary( tstNode, arr, 0 );
  
  
    return 0;
}
