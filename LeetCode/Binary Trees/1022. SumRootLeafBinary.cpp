// ~O(N) time and O(height of tree) space solution

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
    void Traversal(TreeNode* root, vector<vector<int>>& answer, vector<int> njw)
    {
        if(root == NULL)
            return;
        
        njw.push_back(root->val);
        
        if(root->left == NULL and root->right == NULL)
            answer.push_back(njw);
        
        Traversal(root->left, answer, njw);
        Traversal(root->right, answer, njw);
        njw.pop_back();
    }
    
    int sumRootToLeaf(TreeNode* root) {
        vector<vector<int>> answer;
        vector<int> njw;
        
        Traversal(root, answer, njw);
        
        int sum = 0;
        for(int i = 0; i < answer.size(); i++)
        {
            vector<int> temp = answer[i];
            int temp_sum = 0;
            int base = 1;

            for(int j = temp.size()-1; j >= 0; j--) 
            {
                int d = temp[j];
                temp_sum += d * base;
                base = base * 2;
            }
            sum += temp_sum;
        }
        return sum;
    }
};