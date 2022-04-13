// O(NlogN) time approach ..

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
    TreeNode* Solve(vector<int>& inorder, vector<int>& postorder, int& index, int inorderStart, int inorderEnd, map<int,int>& m)
    {
        if(index < 0 or inorderStart > inorderEnd)
            return NULL;
        
        int element = postorder[index--];
        TreeNode* root = new TreeNode(element);
        int position = m[element];
        
        root->right = Solve(inorder, postorder, index, position+1, inorderEnd, m);
        root->left = Solve(inorder, postorder, index, inorderStart, position-1, m);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = postorder.size();
        int postorderIndex = n-1;
        
        map<int, int> m;
        for(int i = 0; i < inorder.size(); i++)
            m[inorder[i]] = i;
        
        return Solve(inorder, postorder, postorderIndex, 0, n-1, m);
    }
};