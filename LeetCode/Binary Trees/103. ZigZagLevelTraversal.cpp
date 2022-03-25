// 1. O(3N) = O(N) space and O(N + N^2) = O(N^2) time ?!

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
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> answer;
        vector<int> njw;
        vector<vector<int>> final_answer;
        
        if(root != NULL)
            LevelOrderTraversal(root, answer, njw);
        else
            return answer;
        
        for(int i = 0; i < answer.size(); i++)
        {
            vector<int> temp = answer[i];
            if(i % 2 != 0)
            {
                for(int j = temp.size()-1; j >= 0; j--)
                    njw.push_back(temp[j]);
                final_answer.push_back(njw);
                njw.clear();
            }
            else
                final_answer.push_back(temp);
        }
        return final_answer;
    }
};

// 2. O(N) space and time, although worse LC performance than the above solution ..

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
    void LevelOrderTraversal(TreeNode* root, vector<vector<int>>& answer, vector<int> njw, int count)
    {
        if(root == NULL)
            return;
        
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        
        while(!q.empty())
        {
            TreeNode* temp = q.front();
            q.pop();
            
            if(temp == NULL)
            {
                if(count % 2 == 0)
                    answer.push_back(njw);
                else
                {
                    reverse(njw.begin(), njw.end());
                    answer.push_back(njw);
                } 
                njw.clear();
                count++;
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
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> answer;
        vector<int> njw;
        
        LevelOrderTraversal(root, answer, njw, 0);
        
        return answer;
    }
};