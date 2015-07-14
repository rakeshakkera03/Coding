/*
Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.
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
    bool RootToLeafSumExists(TreeNode* root, int target_sum, int curr_sum)
    {
        if( !root )
        {
            return false;
        }
        
        curr_sum = curr_sum + root->val;
        
        // Following is the condition to check if a node is a leaf node or not
        if( root->left == NULL && root->right == NULL && curr_sum == target_sum )
            return true;
        
        return (RootToLeafSumExists( root->left, target_sum, curr_sum ) || RootToLeafSumExists( root->right, target_sum, curr_sum ) );
    }
    
    bool hasPathSum(TreeNode* root, int sum) {
    
        return RootToLeafSumExists( root, sum, 0);
    }
};
