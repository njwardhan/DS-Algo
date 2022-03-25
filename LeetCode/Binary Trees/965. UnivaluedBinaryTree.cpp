// O(N) time and O(height of tree) space

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
    void Traversal(TreeNode* root, bool&check, int root_value)
    {
        if(root == NULL)
            return;
        
        Traversal(root->left, check, root_value);
        if(root->val != root_value)
            check = false;
        Traversal(root->right, check, root_value);
    }
    
    bool isUnivalTree(TreeNode* root) {
        bool check = true;
        
        Traversal(root, check, root->val);
        
        return check;
    }
};