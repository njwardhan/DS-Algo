// 1. O(N) time and O(height of tree) = O(N) space, where N = nodes in the Binary Tree
// Good leetcode performance as compared to the below one

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
    int answer = 0;
public:
    void InOrderTraversal(TreeNode* root, int count)
    {
        if(root == NULL)
        {
            answer = max(answer, count);
            return;
        }
        
        count++;
        InOrderTraversal(root->left, count);
        InOrderTraversal(root->right, count);
        count--;
    }
    
    int maxDepth(TreeNode* root) {
        InOrderTraversal(root, 0);
        return answer;
    }
};

// 2. O(N) time and O(height of tree) = O(N) space, where N = nodes in the Binary Tree
// Classic recursion at work

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
    int maxDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
        
        int left_height = maxDepth(root->left);
        int right_height = maxDepth(root->right);
        
        return max(left_height, right_height) + 1; 
    }
};