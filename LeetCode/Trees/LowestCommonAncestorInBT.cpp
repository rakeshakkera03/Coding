/*
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        TreeNode* left, *right;
        if( !root )
            return root;
        
        if( root == p || root == q )
            return root;
        
        left = lowestCommonAncestor(root->left, p, q);
        right = lowestCommonAncestor(root->right, p, q);
        
        if( left != NULL && right != NULL )
            return root;
        else if( left || right )
            return left?left:right;
        else
            return NULL;
    }
};
