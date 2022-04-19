// Daily challenge: 17th April 2022

// 1. Storing nodes in the inorder fasion and then handling the pointers. O(N) time and space solution, though, 0 ms and faster than 100%
// LC submissions!

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
    void Traversal(TreeNode* root, vector<TreeNode*>& nodes)
    {
        if(!root)
            return;
        
        Traversal(root->left, nodes);
        nodes.push_back(root);
        Traversal(root->right, nodes);
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        vector<TreeNode*> nodes;
        
        Traversal(root, nodes);
        
        root = nodes[0];
        TreeNode* root_store = root;
        
        for(int i = 1; i < nodes.size(); i++)
        {
            root->right = nodes[i];
            root->left = NULL;
            root = nodes[i];
        }
        root->right = NULL;
        root->left = NULL;
        return root_store;
    }
};

// 2. Pure Recursive Solution

