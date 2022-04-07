// O(N) time in the worst possible case (when the range is so big that all the nodes have to be traversed ..) and constant space 

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
    int sum = 0;
public:
    void BST(TreeNode* root, int low, int high)
    {
        if(root == NULL)
            return;
        
        if(root->val >= low and root->val <= high)
        {
            sum += root->val;
            BST(root->left, low, high);
            BST(root->right, low, high);
        }
        else if(root->val < low)
            BST(root->right, low, high);
        
        else if(root->val > high)
            BST(root->left, low, high);
    }
    
    int rangeSumBST(TreeNode* root, int low, int high) {
        BST(root, low, high);
        
        return sum;
    }
};