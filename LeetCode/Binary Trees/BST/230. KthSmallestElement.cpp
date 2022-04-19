// 1. Using the inorder traversal technique
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
    void Traversal(TreeNode* root, vector<int>& answer)
    {
        if(root == NULL)
            return;
        
        Traversal(root->left, answer);
        answer.push_back(root->val);
        Traversal(root->right, answer);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        vector<int> answer;
        
        Traversal(root, answer);
        
        return answer[k-1];
    }
};


// 2. Without using inorder traversal
// O(N) time and constant space, okayish LC performance only as compared to the above one ..

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
    int answer, count = 0;
public:
    void Traversal(TreeNode* root, int k)
    {
        if(root == NULL)
            return;
            
        Traversal(root->left, k);
        
        count++;
        if(count == k)
            answer = root->val;

        Traversal(root->right, k);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        Traversal(root, k);
        
        return answer;
    }
};


// 3. Without using global variable stuff - O(N) time and space approach
// Daily challenge: 18th April 2022

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
    void Traversal(TreeNode* root, int& count, int k, int& answer)
    {
        if(root == NULL)
            return;

        Traversal(root->left, count, k, answer);
        count++;
        if(count == k)
            answer = root->val;
        Traversal(root->right, count, k, answer);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        int answer = 0;
        int count = 0;
        
        Traversal(root, count, k, answer);
        
        return answer;
    }
};