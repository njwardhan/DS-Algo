// 1. O(N^2) time and O(height of tree) = O(N) space solution --> Not the best approach ..

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
    int height(TreeNode *root)
    {
        if(root == NULL)
            return 0;
        
        int left_height = height(root->left);
        int right_height = height(root->right);
        
        return max(left_height, right_height) + 1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL)
            return 0;
        
        int op1 = diameterOfBinaryTree(root->left);
        int op2 = diameterOfBinaryTree(root->right);
        int op3 = height(root->left) + height(root->right);
        
        return max(op1, max(op2, op3));
    }
};

// 2. O(N) time and O(height of tree) = O(N) space solution
// Working on height and diameter at the same time!

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
    pair<int, int> fastDiameter(TreeNode *root)
    {
        if(root == NULL)
        {
            pair<int, int> base = make_pair(0, 0);
            return base;
        }
        
        pair<int, int> left = fastDiameter(root->left);
        pair<int, int> right = fastDiameter(root->right);
        
        int op1 = left.first;
        int op2 = right.first;
        int op3 = left.second + right.second;
        
        pair<int,int> answer;
        answer.first = max(op1, max(op2, op3));
        answer.second = max(left.second, right.second) + 1;
        return answer;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        return fastDiameter(root).first;
    }
};