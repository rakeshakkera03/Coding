# include <stdio.h>
# include <stdlib.h>

# define MAX_ELEM 10

typedef struct TreeNode
{
    unsigned int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

int top = -1;
TreeNode* Stack[ MAX_ELEM ];


void InsertIntoTree( TreeNode **root, unsigned int data )
{
    (*root) = (TreeNode *)malloc(sizeof(TreeNode));
    (*root)->data  = data;
    (*root)->left  = NULL;
    (*root)->right = NULL;
}

int IsStackEmpty()
{
    return ( -1 == top ) ? 1 : 0;
}

void Push( TreeNode *node )
{
    if( ( MAX_ELEM - 1 ) == top )
    {
        printf("\n Full Stack. \n");
        return;
    }
    else
    {
        Stack[ ++top ] = node;
    }
}

TreeNode* Pop()
{
    TreeNode* retVal = NULL;
    if( IsStackEmpty() )
    {
        printf("\n Empty Stack. \n");
    }
    else
    {
        retVal = Stack[ top-- ];
    }
    return retVal;
}

void PostOrderIterative( TreeNode *root )
{
    if( !root )
        return;

    while( 1 )
    {
        while( root )
        {
            if( root->right )
            {
                Push( root->right );
            }
            Push( root );
            root = root->left;                   
        }
        
        if( IsStackEmpty() )
        {
            break;
        }
        
        root = Pop();
        
        
        if( root->right && ( ( root->right ) ==  Stack[top] ) )
        {
            TreeNode* root_right = Pop();
            Push( root );
            root = root_right;
        }
        else
        {
            printf("\t %d", root->data );
            root = NULL;
        }
    }
}

void InOrderIterative( TreeNode *root )
{
    if( !root )
        return;
        
    while( 1 )
    {
        while( root )
        {
            Push( root );
            root = root->left;
        }
        
        if( IsStackEmpty() )
        {
            break;
        }
        
        root = Pop();
        
        printf("\t %d", root->data );
        
        root = root->right;    
    }            
}

void PreOrderIterative( TreeNode *root )
{
    if( !root )
        return;

    while( 1 )
    {
        while( root )
        {
            printf(" \t %d", root->data );
            Push( root );
            root = root->left;            
        }
        
        if( IsStackEmpty() )
        {
            break;
        }        
        
        root = Pop();
        
        root = root->right;
    }              
}

int main()
{
    TreeNode *root = NULL;
    InsertIntoTree( &root, 1 );
    InsertIntoTree( &root->left, 2 );
    InsertIntoTree( &root->right, 3 );
    InsertIntoTree( &root->left->left, 4 );
    InsertIntoTree( &root->left->right, 5 );
    InsertIntoTree( &root->right->left, 6 );
    InsertIntoTree( &root->right->right, 7 );

    printf(" \n PreOrder Iterative: ");
    PreOrderIterative( root );
    printf("\n");
    
    printf(" \n InOrder Iterative: ");
    InOrderIterative( root );
    printf("\n");
    
    printf(" \n PostOrder Iterative: ");
    PostOrderIterative( root );
    printf("\n");

    return 0;
}
