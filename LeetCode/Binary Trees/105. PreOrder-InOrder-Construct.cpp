// O(NlogN) + O(N) = O(NlogN) time approach. NlogN is the complexity of inserting N elements into the map, and N is the complexity of
// the solve function.
// Using the map helps us reduce complexity considerably

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
    TreeNode* Solve(vector<int>& preorder, vector<int>& inorder, int& index, int inorderStart, int inorderEnd, int size, map<int,int>& m)
    {
        if(index >= size or inorderStart > inorderEnd)
            return NULL;
          
        int element = preorder[index++];
        TreeNode* root = new TreeNode(element);
        
        int position = m[element];
        
        root->left = Solve(preorder, inorder, index, inorderStart, position-1, size, m);
        root->right = Solve(preorder, inorder, index, position+1, inorderEnd, size, m);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preOrderIndex = 0;
        int n = preorder.size();
        
        map<int, int> m;
        for(int i = 0; i < inorder.size(); i++)
            m[inorder[i]] = i;
        
        return Solve(preorder, inorder, preOrderIndex, 0, n-1, n , m);
    }
};