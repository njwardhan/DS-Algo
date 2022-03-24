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
    void LevelOrderTraversal(TreeNode* root, int sum, vector<int>& answer)
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
                answer.push_back(sum);
                sum = 0;
                if(!q.empty())
                    q.push(NULL);
            }
            else
            {
                sum += temp->val;
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
        }
        
    }
    
    int maxLevelSum(TreeNode* root) {
        vector<int> answer;
        int sum = 0;
        
        LevelOrderTraversal(root, sum, answer);
        
        int max = INT_MIN;
        int sol;
        for(int i = 0; i < answer.size(); i++)
        {
            if(answer[i] > max)
            {
                max = answer[i];
                sol = i;
            } 
        }
        return sol+1;
    }
};