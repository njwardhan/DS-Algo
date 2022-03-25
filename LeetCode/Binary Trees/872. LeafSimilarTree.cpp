// O(2N) = O(N) space and O(height of tree) space

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
    void Traversal(TreeNode* root, vector<int>& answer)
    {
        if(root == NULL)
            return;
        
        if(root->left == NULL and root->right == NULL)
            answer.push_back(root->val);
        
        Traversal(root->left, answer);
        Traversal(root->right, answer);
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> answer1, answer2;
        
        Traversal(root1, answer1);
        Traversal(root2, answer2);
        
        if(answer1 == answer2)
            return true;
        else
            return false;
    }
};