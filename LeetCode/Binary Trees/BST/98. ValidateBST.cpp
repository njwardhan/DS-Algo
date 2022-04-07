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
    
    bool isValidBST(TreeNode* root) {
        vector<int> answer;
        bool flag = true;
        
        Traversal(root, answer);
        
        for(int i = 0; i < answer.size()-1; i++)
        {
            if(answer[i] >= answer[i+1])
            {
                flag = false;
                break;
            }
        }
        
        return flag;
    }
};