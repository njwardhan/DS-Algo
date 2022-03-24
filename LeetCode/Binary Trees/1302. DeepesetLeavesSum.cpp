// // O(N) time and space solution

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
    void LevelOrderTraversal(TreeNode* root, vector<vector<int>>& answer, vector<int> njw)
    {
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        
        while(!q.empty())
        {
            TreeNode* temp = q.front();
            q.pop();
            
            if(temp == NULL)
            {
                answer.push_back(njw);
                njw.clear();
                
                if(!q.empty())
                    q.push(NULL);
            }
            else
            {
                njw.push_back(temp->val);
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
        }
    }
    
    int deepestLeavesSum(TreeNode* root) {
        vector<vector<int>> answer;
        vector<int> njw;
        
        LevelOrderTraversal(root, answer, njw);
        
        vector<int> sol = answer[answer.size()-1];
        
        int sum = 0;
        for(int i = 0; i < sol.size(); i++)
            sum += sol[i];
        
        return sum;
    }
};