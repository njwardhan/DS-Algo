// O(2N) = O(N) time and space approach, decent LC performance
// Daily challenge: 16th April 2022

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
    void Solve(TreeNode* root, int& totalSum, int& lesserSum)
    {
        if(!root)
            return;
        
        Solve(root->left, totalSum, lesserSum);
        int temp = lesserSum;
        lesserSum += root->val;
        root->val = totalSum - temp;
        Solve(root->right, totalSum, lesserSum);
    }
    
    void Traversal(TreeNode* root, int& totalSum)
    {
        if(!root)
            return;
        
        totalSum += root->val;
        Traversal(root->left, totalSum);
        Traversal(root->right, totalSum);
    }
    
    TreeNode* convertBST(TreeNode* root) {
        int totalSum = 0, lesserSum = 0;
        
        Traversal(root, totalSum);
        Solve(root, totalSum, lesserSum);
        
        return root;
    }
};