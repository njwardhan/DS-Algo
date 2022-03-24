// O(N) time and O(height of tree) space solution

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
    void Traversal(TreeNode* root, vector<string>& answer, string s)
    {
        if(root == NULL)
            return;
        
        s += to_string(root->val);
        
        if(root->left == NULL and root->right == NULL)
            answer.push_back(s);
        
        Traversal(root->left, answer, s);
        Traversal(root->right, answer, s);
        s.pop_back();
    }
    
    int sumNumbers(TreeNode* root) {
        vector<string> answer;
        
        Traversal(root, answer, "");
        
        int sum = 0;
        
        for(int i = 0; i < answer.size(); i++)
            sum += stoi(answer[i]);
        
        return sum;
    }
};