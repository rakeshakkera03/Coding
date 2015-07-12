/*
Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.
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

    void ReturnKthSmallest( TreeNode* root, int k, int &count, int &returnVal)
    {
        if( !root )
            return;
        
        ReturnKthSmallest(root->left, k, count, returnVal);
        
        count++;
        if( count == k )
        {
            returnVal = root->val;
            return;
        }
            
        ReturnKthSmallest(root->right, k, count, returnVal);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        
        int returnVal = INT_MIN;
        int count = 0;
        ReturnKthSmallest(root, k, count, returnVal );
        
        return returnVal;
        
    }
};
