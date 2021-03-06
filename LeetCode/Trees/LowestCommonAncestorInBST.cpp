/*
Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.
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
        
        if( !root )
            return root;
            
        if( root->val == p->val )
            return p;
        else if ( root->val == q->val )
        {
            return q;
        }
        else if ( (root->val > p->val && root->val < q->val) || (root->val < p->val && root->val > q->val) )
        {
            return root;
        }
        else if( root->val > p->val && root->val > q->val )
        {
            lowestCommonAncestor(root->left, p, q);
        }
        else
        {
            lowestCommonAncestor(root->right, p, q);
        }
        
    }
};
