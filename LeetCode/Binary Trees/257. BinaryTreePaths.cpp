// O(N) tiem and O(height of tree) space
 
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
        
        s += to_string(root->val) + "->";
        
        if(root->left == NULL and root->right == NULL)
        {
            s.pop_back();
            s.pop_back();
            answer.push_back(s);
        }
        
        Traversal(root->left, answer, s);
        Traversal(root->right, answer, s);
        s.pop_back();
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> answer;
        
        Traversal(root, answer, "");
        
        return answer;
    }
};