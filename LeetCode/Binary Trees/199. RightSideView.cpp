// 1. O(N) time and O(height of tree) space

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
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int> sol;
        if(root == NULL)
            return sol;
        
        vector<vector<int>> answer;
        levelOrderTraversal(root, answer);
        
        for(int i = 0; i < answer.size(); i++)
            sol.push_back(answer[i][answer[i].size()-1]);
        
        return sol;
    }
};

// 2. Recursive Approach (without level order traversal): O(N) time and O(height of the tree) space

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
    void Traversal(TreeNode* root, vector<int>&answer, int level)
    {
        if(root == NULL)
            return;
        
        if(level == answer.size())
            answer.push_back(root->val);
        
        Traversal(root->right, answer, level+1);
        Traversal(root->left, answer, level+1);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int> answer;
        
        Traversal(root, answer, 0);
        
        return answer;
    }
};