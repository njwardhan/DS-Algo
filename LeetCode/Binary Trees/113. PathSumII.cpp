// O(N) time and O(height of tree) space approach

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
    void Traversal(TreeNode* root, vector<vector<int>>& answer, int targetSum, vector<int> temp, int sum)
    {
        if(root == NULL)
            return;
        
        temp.push_back(root->val);
        sum += root->val;
        
        if(root->left == NULL and root->right == NULL)
        {
            if(sum == targetSum)
                answer.push_back(temp);
        }
        
        Traversal(root->left, answer, targetSum, temp, sum);
        Traversal(root->right, answer, targetSum, temp, sum);
        
        temp.pop_back();
        sum -= root->val;   
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> answer;
        vector<int> temp;
        
        Traversal(root, answer, targetSum, temp, 0);
        
        return answer;
    }
};