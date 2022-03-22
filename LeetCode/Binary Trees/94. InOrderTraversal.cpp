// O(N) time and space solution, where N = number of node of the Binary Tree

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
    void InOrderTraversal(vector<int>& answer, TreeNode* root)
    {
        if(root == NULL)
            return;
        
        InOrderTraversal(answer,root->left);
        answer.push_back(root->val);
        InOrderTraversal(answer,root->right);
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> answer;
        if(root != NULL)
            InOrderTraversal(answer, root);
        
        return answer;
    }
};