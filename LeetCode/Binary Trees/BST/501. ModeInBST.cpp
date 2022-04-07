// 1. Using an extra data strcuture: map
// O(N) time and O(2N) = O(N) space approach

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
    void Traversal(TreeNode* root, map<int, int>& m)
    {
        if(root == NULL)
            return;
        
        Traversal(root->left, m);
        m[root->val]++;
        Traversal(root->right, m);
    }
    
    vector<int> findMode(TreeNode* root) {
        map<int, int> m;
        vector<int> answer;
        
        Traversal(root, m);
        
        int max_freq = INT_MIN;
        for(auto x : m)
        {
            if(x.second >= max_freq)
                max_freq = x.second;
        }
        
        for(auto x : m)
        {
            if(x.second == max_freq)
                answer.push_back(x.first);
        }
        
        return answer;
    }
};

// 2. Without using any extra Data Structure
//

