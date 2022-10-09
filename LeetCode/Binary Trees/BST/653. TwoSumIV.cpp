// 1. O(N) time and space solution --> Not the best LC performance ..

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
    void inOrder(TreeNode* root, vector<int>& answer)
    {
        if(root == NULL)
            return;
        
        inOrder(root->left, answer);
        answer.push_back(root->val);
        inOrder(root->right, answer);
    }
    
    bool findTarget(TreeNode* root, int k) {
        vector<int> answer;
        inOrder(root, answer);
        
        int start = 0, end = answer.size()-1;
        while(start < end)
        {
            int temp = answer[start] + answer[end]; 
            if(temp == k)
                return true;
            else if(temp < k)
                start++;
            else
                end--;
        }
        return false;
    }
};

// 2. Using a BST Iterator (LC-173) will help us achieve a solution with better space complexity: O(N) time and O(height) space

