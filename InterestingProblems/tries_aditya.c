# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

typedef struct TrieNode
{
    char c;
    bool isEndOfString;
    struct TrieNode* child[26];
} TrieNode;

void InitializeRoot( TrieNode **root )
{
  (*root) = (TrieNode *)malloc(sizeof(TrieNode));
  (*root)->c = '1';
  (*root)->isEndOfString = false;
  
  int i = 0;
  for( i = 0; i < 26; i++ )
  {
    (*root)->child[i] = NULL;
  }
}

void InsertIntoTrie( TrieNode **root, char *word )
{
  if( *word == '\0' )
    return;
  
  if( !(*root)->child[ *word - 'a' ] )
  {
    (*root)->child[ *word - 'a' ] = (TrieNode *)malloc(sizeof(TrieNode));
    (*root)->child[ *word - 'a' ]->c = *word;
    (*root)->child[ *word - 'a' ]->isEndOfString = false;
    int i = 0;
    for( i = 0; i < 26; i++ )
    {
      (*root)->child[ *word - 'a']->child[i] = NULL;
    }
    
    if( *(word + 1) == '\0' )
    {
      (*root)->child[ *word - 'a' ]->isEndOfString = true;        
    }
    InsertIntoTrie( &(*root)->child[ *word - 'a' ], word + 1 );
  }
  else
  {
    if( *(word + 1) == '\0' )
    {
        (*root)->child[ *word - 'a' ]->isEndOfString = true;
        return;
    }
    InsertIntoTrie( &(*root)->child[ *word - 'a' ], word + 1 );
  }
}

bool SearchInTrie(TrieNode* root, char *word)
{
    if( !root )
        return false;
  
    if( *word == '\0')
        return true;
  
    if( *(word + 1) == '\0')
    {
        if( root->child[ *word - 'a' ] && root->child[ *word - 'a' ]->isEndOfString == true)
        {
            return true;
        }
        return false;
    }
  
    if( root->child[ *word - 'a' ] )
    {
         return SearchInTrie(root->child[ *word - 'a'], word + 1);
    }
   
    return false;
}

int main()
{
  TrieNode *root = NULL;
  InitializeRoot( &root );
  
  InsertIntoTrie( &root, "hello" );
  InsertIntoTrie( &root, "hi" );
  InsertIntoTrie( &root, "hel" );
  
  char* word = "hii";
  bool ret = SearchInTrie( root, word );
  
  if( ret )
      printf("\nFound the word %s\n", word);
  else
      printf("\nWord not found %s\n", word); 
  
  return 0;
}
