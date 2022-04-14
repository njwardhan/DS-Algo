// 1. O(logN) time and constant space

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
    TreeNode* answer;
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == NULL)
            return NULL;
        
        if(root->val == val)
            answer = root;
        else if(root->val < val)
            searchBST(root->right, val);
        else
            return searchBST(root->left, val);
        
        return answer;
    }
};

// 2. O(logN) time and constant space, but a more intuitive approach than the above one + better LC performance too
// Daily challenge: 14th April 2022

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
    void Find(TreeNode* root, int N, TreeNode*& answer)
    {
        if(root == NULL)
            return;
        
        if(root->val == N)
            answer = root;
        else if(root->val < N)
            Find(root->right, N, answer);
        else
            Find(root->left, N, answer);
    }
    
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* answer = NULL;
        
        Find(root, val, answer);
        
        return answer;
        
    }
};