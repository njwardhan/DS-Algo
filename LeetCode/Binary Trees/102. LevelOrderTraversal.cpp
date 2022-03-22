// O(N) time and space solution, where N = number of nodes in the binary tree
 
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
    void levelOrderTraversal(TreeNode* root, vector<vector<int>>& answer)
    {
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL); // being used as a seperator
        
        vector<int> temp_data;
        while(!q.empty())
        {
            TreeNode* temp = q.front();
            q.pop();
            
            if(temp != NULL)
            {
                temp_data.push_back(temp->val);
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
            else
            {
                answer.push_back(temp_data);
                temp_data.clear();
                if(!q.empty())
                    q.push(NULL);
            }
        }
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> answer;
        if(root != NULL)
            levelOrderTraversal(root, answer);
            
        return answer;
    }
};