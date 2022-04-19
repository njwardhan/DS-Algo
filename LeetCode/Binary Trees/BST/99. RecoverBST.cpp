// Daily Challenge: 19th April 2022
// 1. Using extra array :/ - O(NlogN) time and O(N) space approach

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
    void Solve(TreeNode* root, int a, int b)
    {
        if(root == NULL)
            return;
        
        if(root->val == a)
            root->val = b;
        else if(root->val == b)
            root->val = a;
        
        Solve(root->left, a, b);
        Solve(root->right, a, b);
    }
    
    void Traversal(TreeNode* root, vector<int>& inorder)
    {
        if(root == NULL)
            return;
        
        Traversal(root->left, inorder);
        inorder.push_back(root->val);
        Traversal(root->right, inorder);
    }
    
    void recoverTree(TreeNode* root) {
        vector<int> inorder;
        
        Traversal(root, inorder);
        
        vector<int> inorder_store = inorder;
        sort(inorder.begin(), inorder.end());
        
        vector<int> to_be_changed;
        for(int i = 0; i < inorder.size(); i++)
        {
            if(inorder[i] != inorder_store[i])
                to_be_changed.push_back(inorder[i]);
        }
        
        Solve(root, to_be_changed[0], to_be_changed[1]);
    }
};


// 2. Without using any extra data strcuture: O(N) time and space
// Needed some help from the discuss section ..

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
    TreeNode* first = NULL, *second = NULL, *prev = NULL;
public:
    void inorder(TreeNode* root)
    {
        if(root == NULL)
            return;
        
        inorder(root->left);
        if(prev!=NULL && (root->val < prev->val))
        {
            if(first == NULL)
            {
                first = prev;
                second = root;
            }
            else
                second = root;
        }
        prev=root;
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        inorder(root);
        swap(first->val, second->val);
    }
};
