// O(N) time and space where N = number of nodes of the Binary Tree

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
    void PreOrderTraversal(vector<int>& answer, TreeNode* root)
    {
        if(root == NULL)
            return;
        
        answer.push_back(root->val);
        PreOrderTraversal(answer,root->left);
        PreOrderTraversal(answer,root->right);
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> answer;
        if(root != NULL)
            PreOrderTraversal(answer, root);
        
        return answer;
    }
};