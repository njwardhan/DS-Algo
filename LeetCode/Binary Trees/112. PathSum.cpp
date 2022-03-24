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
    void rootToLeafSum(TreeNode* root, int targetSum, bool& check, int sum)
    {
        if(root == NULL)
            return;
        
        sum += root->val;
        
        if(root->left == NULL and root->right == NULL)
        {
            if(sum == targetSum)
                check = true;
        }
        rootToLeafSum(root->left, targetSum, check, sum);
        rootToLeafSum(root->right, targetSum, check, sum);
        sum -= root->val;
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        bool check = false;
        
        rootToLeafSum(root, targetSum, check, 0);
        
        return check;
    }
};