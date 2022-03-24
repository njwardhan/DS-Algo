// O(N) time and O(height of tree) space solution

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
    void Traversal(TreeNode* root, int& sum, bool valid)
    {
        if(root == NULL)
            return;
        
        if(root->left == NULL and root-> right == NULL and valid == true)
            sum += root->val;

        Traversal(root->left, sum, true);
        Traversal(root->right, sum, false);
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        
        Traversal(root, sum, false);
        
        return sum;
    }
};