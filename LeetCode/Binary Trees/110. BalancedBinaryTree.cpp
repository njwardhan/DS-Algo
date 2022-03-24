// 1. O(N^2) time and O(height of tree) = O(N) as worst case space

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
    int height(TreeNode* root)
    {
        if(root == NULL)
            return 0;
        
        return max(height(root->left), height(root->right)) + 1;
    }
    
    bool isBalanced(TreeNode* root) {
        if(root == NULL)
            return true;
        
        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);
        
        bool temp = ((abs(height(root->left) - height(root->right)) <= 1));
        
        return left && right && temp;
    }
};

// 2. O(N) solution and O(height of tree) = O(N) as worst case space
// Better Leetcode performance, and obviously xD

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
    pair<bool, int> solve(TreeNode* root)
    {
        if(root == NULL)
        {
            pair<bool, int> base = make_pair(true, 0);
            return base;
        }
        
        pair<bool, int> left = solve(root->left);
        pair<bool, int> right = solve(root->right);
        
        bool temp = (abs(left.second - right.second) <= 1);
        
        pair<bool, int> answer;
        answer.first = temp && left.first && right.first;
        answer.second = max(left.second, right.second)+1;
            
        return answer; 
    }
    
    bool isBalanced(TreeNode* root) {
        return solve(root).first;
    }
};