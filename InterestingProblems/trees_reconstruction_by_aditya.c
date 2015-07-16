# include <stdio.h>
# include <stdlib.h>

# define MAX_ELEM 10

typedef struct TreeNode
{
    unsigned int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

int front = -1, rear = -1;
TreeNode* Queue[ MAX_ELEM ];

int IsQueueEmpty()
{
  return ( -1 == front ) ? 1 : 0;
}

void Enqueue( TreeNode *node )
{
  if( ( MAX_ELEM - 1 ) == rear )
  {
    printf("\n Full Queue. \n");
    return;
  }
  else
  {
    Queue[ ++rear ] = node;
    if( -1 == front )
      front = 0;
  }
}

TreeNode* Dequeue()
{
  TreeNode *retVal = NULL;
  if( IsQueueEmpty() )
  {
    printf("\n Empty Queue. \n");
  }
  else
  {
    retVal = Queue[ front++ ];
    if( front > rear )
      front = rear = -1;
  }
  return retVal;
}

void LevelOrderIterative( TreeNode *root )
{
  if( !root )
  {
    return;
  }

  Enqueue( root );

  while( !IsQueueEmpty() )
  {
    root = Dequeue();
    printf("\t %d", root->data );

    if( root->left )
      Enqueue( root->left );

    if( root->right )
      Enqueue( root->right );
  }
}

int FindElementInOrderArr( int *InOrder, int elemToFind, int start, int end )
{
  int retVal = -1;
  
  int i = start;
  for( i = start; i <= end; i++ )
  {
      if( InOrder[i] == elemToFind )
      {
          retVal = i;
          break;
      }
  }
  return retVal;  
}

int* CallToHelper( int *inOrder, int *levelOrder, int start, int end )
{
    int *retVal = (int *)malloc(sizeof(int) * ( end - start + 1 ) );
    
    int i = 0, j = 0;
    for( i = 0; i <= 6; i++ )
    {
        if( -1 != FindElementInOrderArr( inOrder, levelOrder[i], start, end ) )
        {
            retVal[ j++ ] = levelOrder[i]; 
        }
    }
  
    return retVal;
}

void ReconstructUsingInLevelTraversals( int *inOrder, int *levelOrder, TreeNode **root, int start, int end )
{
  if( start <= end )
  {
    (*root) = (TreeNode *)malloc(sizeof(TreeNode));
    (*root)->left  = NULL;
    (*root)->right = NULL;
    (*root)->data  = levelOrder[ 0 ];
    
    int inIdx = FindElementInOrderArr( inOrder, levelOrder[ 0 ], start, end );
    
    int *left  = CallToHelper( inOrder, levelOrder, start, inIdx - 1 );
    int *right = CallToHelper( inOrder, levelOrder, inIdx + 1, end );
    
    ReconstructUsingInLevelTraversals( inOrder, left, &(*root)->left,  start, inIdx - 1 );
    ReconstructUsingInLevelTraversals( inOrder, right, &(*root)->right, inIdx + 1, end );    
  }  
}

void ReconstructUsingInPreTraversals( int *inOrder, int *preOrder, TreeNode **root, int start, int end )
{
  static int preIdx = 0;
  
  if( start <= end )
  {
    (*root) = (TreeNode *)malloc(sizeof(TreeNode));
    (*root)->left  = NULL;
    (*root)->right = NULL;
    (*root)->data  = preOrder[ preIdx ];
    
    int inIdx = FindElementInOrderArr( inOrder, preOrder[ preIdx], start, end );
    
    preIdx = preIdx + 1;    
    
    ReconstructUsingInPreTraversals( inOrder, preOrder, &((*root)->left),  start, inIdx - 1 );
    ReconstructUsingInPreTraversals( inOrder, preOrder, &((*root)->right), inIdx + 1, end );    
  }
  
}

void ReconstructUsingInPostTraversals( int *inOrder, int *postOrder, TreeNode **root, int start, int end )
{
  static int postIdx = 6;
  
  if( start <= end )
  {
    (*root) = (TreeNode *)malloc(sizeof(TreeNode));
    (*root)->left  = NULL;
    (*root)->right = NULL;
    (*root)->data  = postOrder[ postIdx ];
    
    int inIdx = FindElementInOrderArr( inOrder, postOrder[ postIdx], start, end );
    
    postIdx = postIdx - 1;    
    
    ReconstructUsingInPostTraversals( inOrder, postOrder, &((*root)->right), inIdx + 1, end );
    ReconstructUsingInPostTraversals( inOrder, postOrder, &((*root)->left),  start, inIdx - 1 );        
  }
  
}


int main()
{
    TreeNode *InPre    = NULL;
    TreeNode *InPost   = NULL;
    
    TreeNode *InLevel  = NULL;
    
    int InOrder[]    = { 4, 2, 5, 1, 6, 3, 7 };
    int LevelOrder[] = { 1, 2, 3, 4, 5, 6, 7 };
  
    int PreOrder[]   = { 1, 2, 4, 5, 3, 6, 7 };
    int PostOrder[]  = { 4, 5, 2, 6, 7, 3, 1 };
    
  
    ReconstructUsingInPreTraversals( InOrder, PreOrder, &InPre, 0, (sizeof(InOrder)/sizeof(InOrder[0]) - 1) );
    ReconstructUsingInPostTraversals( InOrder, PostOrder, &InPost, 0, (sizeof(InOrder)/sizeof(InOrder[0]) - 1) );
  
    ReconstructUsingInLevelTraversals( InOrder, LevelOrder, &InLevel, 0, (sizeof(InOrder)/sizeof(InOrder[0]) - 1) );
  
    printf("\n LevelOrder Iterative: ");
    LevelOrderIterative( InPre );
    printf("\n");
  
    printf("\n LevelOrder Iterative: ");
    LevelOrderIterative( InPost );
    printf("\n");
  
    printf("\n LevelOrder Iterative: ");
    LevelOrderIterative( InLevel );
    printf("\n");
  
    return 0;
}
