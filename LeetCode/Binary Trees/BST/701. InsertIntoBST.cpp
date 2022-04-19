// O(logN) time (to traverse till the correct position, adding the node happens in constant time), O(N) space

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
    TreeNode* Solve(TreeNode* root, int N)
    {
        if(root == NULL)
        {
            TreeNode* temp = new TreeNode(N);
            return temp;
        }
        
        if(N < root->val)
            root->left = Solve(root->left, N);
        else
            root->right = Solve(root->right, N);
        
        return root;
    }
    
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        return Solve(root, val);
    }
};