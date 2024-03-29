// O(N) time and space in worst case (when the high and low range is too big to accomodate all the tree nodes ..)
// Daily challenge: 15th April 2022
// This solution makes me realize how powerful recursion can be!

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(root == NULL)
            return root;
        
        if(root->val < low)
            root = trimBST(root->right, low, high);
        
        else if(root->val > high)
            root = trimBST(root->left, low, high);
        
        else
        {
            root->left = trimBST(root->left, low, high);
            root->right = trimBST(root->right, low, high);
        }
        
        return root;
    }
};