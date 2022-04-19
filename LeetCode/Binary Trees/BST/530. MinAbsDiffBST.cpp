// O(N) time and space solution

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
    TreeNode* prev = NULL;
    int min_diff = INT_MAX;

    void Traversal(TreeNode* root)
    {
        if(root == NULL)
            return;
        
        Traversal(root->left);
        if(prev != NULL)
        {
            int temp = abs(prev->val - root->val);
            if(temp <= min_diff)
                min_diff = temp;
        }
        prev = root;
        Traversal(root->right);
        
    }
    
    int getMinimumDifference(TreeNode* root) {
        Traversal(root);
        
        return min_diff;
    }
};