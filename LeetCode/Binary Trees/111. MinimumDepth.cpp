// O(N) time and constant space, where N = nodes in the Binary Tree

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
    int answer = INT_MAX;
public:
    void InOrderTraversal(TreeNode* root, int count)
    {
        if(root == NULL)
            return;
        
        count++;
        if(root->left == NULL and root->right == NULL)
            answer = min(answer,count);
        
        InOrderTraversal(root->left, count);
        InOrderTraversal(root->right, count);
        count--;
    }
    
    int minDepth(TreeNode* root) {
        if(root != NULL)
            InOrderTraversal(root, 0);
        else
            return 0;
    
        return answer;
    }
};