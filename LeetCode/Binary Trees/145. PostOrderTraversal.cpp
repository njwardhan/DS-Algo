// O(N) space and time where N = number of nodes of the Binary Tree

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
    void PostOrderTraversal(vector<int>& answer, TreeNode* root)
    {
        if(root == NULL)
            return;
        
        PostOrderTraversal(answer,root->left);
        PostOrderTraversal(answer,root->right);
        answer.push_back(root->val);
    }
    
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> answer;
        if(root != NULL)
            PostOrderTraversal(answer, root);
        
        return answer;
    }
};