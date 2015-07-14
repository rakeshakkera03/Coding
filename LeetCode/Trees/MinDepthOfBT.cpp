/*
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int minDepth(TreeNode* root) {
        
        if ( !root )
            return 0;
            
        if( !root->left && !root->right )
            return 1;
        
        int left = minDepth(root->left);
        int right = minDepth(root->right);
        
        if( left > 0 && right > 0 )
        {
            return 1 + min(left,right);
        }
        else if( left == 0 )
            return 1 + right;
        else 
            return 1 + left;

        /* *** Initially I put this condition. This is incorrect as it fails for the inpur "[1, NULL, 2], 1" *** */
//        return (1 + min(minDepth(root->left), minDepth(root->right)) );
        
    }
};
